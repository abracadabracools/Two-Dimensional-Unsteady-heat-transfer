#include "functions.h"
#include <fstream>

#include <math.h>
#include <iostream>
using namespace std;

//using namespace std;

void gauss_jacobi_implicit(twodarrays temperature, int nx, int ny, double k1, double k2, double tolerance, double totime, double dtime)
{
	for (int t = 0; t < totime; t = t + dtime)
	{
		for (int i = 1; i < nx-1; i++)
		{
			for (int j = 1; j < ny-1; j++)
			{
				int flag = 0;
				double tprev = temperature.arr[i][j];
				double tleft = temperature.arr[i - 1][j];
				double tright = temperature.arr[i + 1][j];
				double ttop = temperature.arr[i][j + 1];
				double tbottom = temperature.arr[i][j - 1];

				double tnow = temperature.arr[i][j];

				double denom = 1. + 2 * k1 * k1 + 2 * k2 * k2;

				tnow = (tprev + (k1 * (tleft + tright)) + (k2 * (ttop + tbottom))) / (denom);

				double error = abs(tnow - tprev);

				if (error > tolerance)
					flag++;

				temperature.arr[i][j] = tnow;
			}
		}
	}
};

void printout(twodarrays temperature) {

	ofstream outdata; // outdata is like cin
	outdata.open("temperature.dat"); // opens the file
	if (!outdata) { // file couldn't be opened
		cerr << "Error: file could not be opened" << endl;
		exit(1);
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			outdata << temperature.arr[i][j] << "\t";
		}

	}
	outdata.close();

};
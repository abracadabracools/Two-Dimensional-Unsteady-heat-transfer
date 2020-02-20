#include <iostream>
#include <fstream>
#include <math.h>
#include "functions.h"


using namespace std;

void twodarrays:: gauss_jacobi_implicit( int nx, int ny, double k1, double k2, double tolerance, double totime, double dtime)
{
	int jacobi = 0;
	for (double t = 0; t < totime; t = t + dtime)
	{
		int flag=0;
		do
		{ ++jacobi;
			for (int i = 1; i < nx-1; i++)
			{
				for (int j = 1; j < ny-1 ; j++)
				{
					 flag = 0;
					double tprev = arr[i][j];

					double ttop = arr[i - 1][j];
					double tbottom = arr[i + 1][j];
					double tright = arr[i][j + 1];
					double tleft = arr[i][j - 1];

					

					double denom = 1. + (2. * k1 * k1) +( 2. * k2 * k2);

					double tnow = (tprev + (k1 * (tleft + tright)) + (k2 * (ttop + tbottom))) / (denom);

					double error = abs(tnow - tprev);

					if (error > tolerance)
					{
						flag++;
						cout << "Not - Convergerd \t" << "i=" << i << "j=" << j << "jacobi =" << jacobi << "time=" << t <<"error="<<error<< "\n";
					}
					else {

						cout << "Convergerd \t" << "i =" << i << "j=" << j << "jacobi =" << jacobi<< "time=" << t << "\n";
					}

					arr[i][j] = tnow; 
					//cout << "flag" << flag << "\t"<< "time"<< t<< "\n";
					//cout << "error" << error<<"\n";
					//cout << "i =" << i << "j=" << j << "temp = " << temperature.arr[i][j] << "\t";
				}
			}
		} while (flag > 0);
	}
	//cout << "jacobi" << jacobi<< "\t";
}

void twodarrays:: printout(int nx,int ny) {

	ofstream outdata; // outdata is like cin
	outdata.open("temperature.dat"); // opens the file
	if (!outdata) { // file couldn't be opened
		cerr << "Error: file could not be opened" << endl;
		exit(1);
	}

	for (int i = 0; i < nx; i++)
	{
		for (int j = 0; j < ny; j++)
		{
			outdata <<arr[i][j] << "\t";
		}

	}
	outdata.close();

}

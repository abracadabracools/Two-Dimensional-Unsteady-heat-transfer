// 2D-Unsteady state-Heat-Diffusion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include <fstream>
//#include <math.h>
#include "functions.h"

//#include "functions.cpp"
using namespace std;

void gauss_jacobi_implicit(twodarrays , int , int , double , double , double , double , double );
void printout(twodarrays);
int main()
{
    std::cout << "Hello World!\n";
    //----------
    // defining square domain
    int L = 1;
    int nx, ny;
    // input nx grids
    cout << "Input your number of grids for x- axis " << "\n";
    cin >> nx;
    cout << "Input your number of grids for y- axis " << "\n";
    cin >> ny;

    // calculating x-axis and y-axis co-ordinates

    // initialising x-axis, y- axis
    // grids and nodes
    // grids and nodes in X- axis

    arrays x_axis(nx,L);
    arrays y_axis(ny,L);

   // cout << x_axis.data[0] << "\t" << x_axis.data[1] << "\t" << x_axis.data[2] << "\n";
    //cout << y_axis.data[0] << "\t" << y_axis.data[1] << "\t" << y_axis.data[2] << "\t";



    // Temperature array delaration and initialisation

    // applying boundary conditions 
    double left_wall_temp, right_wall_temp, bottom_wall_temp, top_wall_temp;
    cout << "Input your left wall temperature" << "\n";
    cin >> left_wall_temp;
    cout << "Input your top wall temperature" << "\n";
    cin >> top_wall_temp;
    cout << "Input your right wall temperature" << "\n";
    cin >> right_wall_temp;
    cout << "Input your bottom wall temperature" << "\n";
    cin >> bottom_wall_temp;
   

    twodarrays temperature(nx, ny, left_wall_temp, top_wall_temp, right_wall_temp, bottom_wall_temp);

    // print test
  /*for (int i = 0; i < nx; i++)
  {
      for (int j = 0; j < ny; j++)
      {
          cout << temperature.arr[i][j] << "\t";
      }

  }
  */
   // define dx, dy
  double dx = ( L / double(nx));
  double dy = (L / double(ny));

  // define dt
  double totime, dtime;
  cout << "Input total time of this simulation" << "\n";
  cin >> totime;
  cout << "Input time increment(dt) for this simulation" << "\n";
  cin >> dtime;

  // define
  double alpha;

  cout << "Input Coefficient of thermal diffusivity for this simulation" << "\n";
  cin >> alpha;

 

  // gauss - jacobi explicit iteration scheme

   // define tolerance
  double tolerance = 1e-4;

  double k1 = (alpha * dtime) /  (dx*dx);
  double k2 = (alpha * dtime) / ( dy*dy);

  //  gauss - jacobi implicit

  gauss_jacobi_implicit(temperature, nx, ny, k1, k2, tolerance, totime, dtime);

  printout(temperature);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

void gauss_jacobi_implicit()
{
}

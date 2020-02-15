#pragma once
//#include "functions.cpp"
class arrays
{
public:
	double* data;
	int size;
	arrays(int size, int length) {
		data = new double[size];
		this->size = size;
		// intializing to axis nodal values
		for (int i = 0; i < size; ++i)
			data[i] =  i* (length/double(size));
	}
	
	~arrays() { delete[] data; }
};

class twodarrays
{ 
public:
	double** arr;
	double* rows;
	

	twodarrays(int rows, int cols, double lw, double tw, double rw, double bw) {

		arr = new double* [rows];
		for (int i = 0; i < rows; ++i)
			arr[i] = new double[rows];
		// intialising temperatures to '0'

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				arr[i][j] = 0.0;
			}
		}

		// updating  left wall temperature
		for (int i = 0; i < rows; ++i)
			arr[i][0] = lw;

		// updating top wall temperature
		for (int j = 0; j < cols; ++j)
			arr[0][j] = tw;

		// updating right wall temperature
		for (int i = 0; i < rows; ++i)
			arr[i][(cols - 1)] = rw;

		// updating bottom wall temperature
		for (int j = 0; j < cols; ++j)
			arr[(rows - 1)][j] = bw;

		// correcting corner temperatures
		// top left corner
		arr[0][0] = (lw + tw) / 2.;
		// top right corner
		arr[0][cols - 1] = (tw + rw) / 2.;
		// bottom right corner
		arr[rows - 1][cols - 1] = (rw + bw) / 2.;
		// bottom left corner
		arr[rows - 1][0] = (lw + bw) / 2.;
	}
		
		~twodarrays() { delete[] arr; }
};



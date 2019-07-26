/*MIT License

Copyright (c) 2019 Alex-Antoine Caron

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.*/


#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include "ult.h"



int main() {
	
	//exemple float
	int size = 20; // For a square grid [size * size]
	float * laplacian = (float*) malloc(size *size *size *size * sizeof(float)); 

	laplacian = laplacian_matrix(size*size, 5);

	//creating inital value
	float * vector = (float*)malloc(size *size  * sizeof(float));
	for (int i = 0; i < size*size; i++) {
		vector[i] = 0;
	}
	for (int i = 0; i < size; i++) {
			vector[i] = -1;
			vector[size - 1 + i] = -1;
	}
	
	float * test_laplacian = (float*)malloc(size *size * sizeof(float));
	


	//exemple double
	/*
	int size = 20; // For a square grid [size * size]
	double * laplacian = (double*)malloc(size *size *size *size * sizeof(double));

	laplacian = laplacian_matrix_double(size*size, 5);

	//creating inital value
	double * vector = (double*)malloc(size *size * sizeof(double));
	for (int i = 0; i < size*size; i++) {
		vector[i] = 0;
	}
	for (int i = 0; i < size; i++) {
		vector[i] = -1;
		vector[size - 1 + i] = -1;
	}

	double * test_laplacian = (double*)malloc(size *size * sizeof(double));
	test_laplacian = sor(laplacian, vector, size*size, 1e-4F);
	*/

	

	//test_laplacian = jacobi((float*)laplacian, vector, size*size,1e-4F);
	//test_laplacian = sidel((float*)laplacian, vector, size*size, 1e-4F);
	test_laplacian = sor((float*)laplacian, vector, size*size, 1e-4F);

	//Export Data to a csv file
	std::ofstream myfile;
	for (int i = 0; i < size ; i++)
	{
		myfile << test_laplacian[i*size + 0];

		for (int j = 1; j < size; j++)
		{
			myfile << ", " << test_laplacian[i*size + j];
		}
		myfile << std::endl;
	}
	myfile.close();
	

	free(test_laplacian);
	free(vector);
	free(laplacian);
	return 0;
}
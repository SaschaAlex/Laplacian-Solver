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
#include <cstdlib>
#include "Laplace_solver.h"



int main() {
	
	//initializing variables  
	int size = 40;  // For a square grid [size * size]
	float * laplacian = (float*) malloc(size *size *size *size * sizeof(float)); 
	float * vector = (float*)malloc(size *size * sizeof(float));
	float * result = (float*)malloc(size *size * sizeof(float));


	//Generate a 2D laplacian Matrix
	laplacian = laplacian2d_matrix(size*size, size);

	//dirichlet condition boundary conditions
	for (int i = 0; i < size*size; i++) {
		vector[i] = 0;
	}
	for (int i = 0; i < size; i++) {
			//vector[i] = -10;
			//vector[(4)*size + i] = -1;
			vector[(size - 1)*size + i]= -10;
	}


	//solvers

	//result = jacobi((float*)laplacian, vector, size*size,1e-4F);
	//result = seidel((float*)laplacian, vector, size*size, 1e-4F);
	result = sor((float*)laplacian, vector, size*size, 1e-4F);

	//Export Data to a csv file
	
	std::ofstream myfile;
	myfile.open("data.csv");
	for (int i = 0; i < size ; i++)
	{
		myfile << result[i*size + 0];

		for (int j = 1; j < size; j++)
		{
			myfile << ", " << result[i*size + j];
		}
		myfile << std::endl;
	}
	myfile.close();

	
	//free memory 
	free(result);
	free(vector);
	free(laplacian);
	return 0;
}
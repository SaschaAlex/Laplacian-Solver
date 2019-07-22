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

void show_matrix(float *  matrix, int r) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < r; j++) {
			if (j == 0) {
				std::cout << "[" << *(matrix + i * r + j);

			}
			else if (j == r - 1)
			{
				std::cout << "," << *(matrix + i * r + j) << "]";
			}
			else
			{
				std::cout << "," << *(matrix + i * r + j);
			}

		}
		std::cout << std::endl;
	}
}

void show_vector(float * vector, int r) {
	for (int i = 0; i < r; i++) {
		std::cout << "[" << vector[i] << "]" << std::endl;
	}

}

float * laplacian_matrix(int size ,int N) {
	float * laplacian;
	laplacian = (float*)malloc(size *size *sizeof(float));
	for (int i = 0; i < size*size; i++) {
		laplacian[i] = 0;
	}
	for (int i = 0; i < size; i++) {
		if (((i + 1) * size + i) < size * size) {
			laplacian[(i + 1) * size + i] = 1;
		}
		if (0 <= ((i - 1) * size + i)) {
			laplacian[(i - 1) * size + i] = 1;
		}

		laplacian[i * size + i] = -4;

		if (((i + N) * size + i) < size * size) {
			laplacian[(i + N) * size + i] = 1;
		}

		if (0 <= ((i - N) * size + i)) {
			laplacian[(i - N) * size + i] = 1;
		}
	}
	return laplacian;

}

float * jacobi(float * matrix, float * vector, int r, int round) {
	float * x = new float[r];
	float * x_holder = new float[r];
	for (int k = 0; k < round; k++) {
		for (int n = 0; n < r; n++) {
			x_holder[n] = vector[n] / (*(matrix + n * r + n));
			for (int i = 0; i < r; i++) {
				if (n != i) {
					x_holder[n] -= (*(matrix + n * r + i)*x[i]) / (*(matrix + n * r + n));
				}
			}
		}
		for (int l = 0; l < r; l++) {
			x[l] = x_holder[l] + 0;
		}
		std::cout << k << std::endl;
	}
	return x;
}



int main() {

	int size = 40;
	float * laplacian = (float*) malloc(size *size *size *size * sizeof(float));

	laplacian = laplacian_matrix(size*size, size);
	float * vector = (float*)malloc(size *size  * sizeof(float));
	for (int i = 0; i < size*size; i++) {
		vector[i] = 0;
	}
	for (int i = 0; i < size; i++) {
			vector[i] = -1*10;
	}

	float * test_laplacian = (float*)malloc(size *size * sizeof(float));
	test_laplacian = jacobi((float*)laplacian, vector, size*size, 100000);

	//Export Data to a csv file
	std::ofstream myfile;
	myfile.open("data.csv");
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
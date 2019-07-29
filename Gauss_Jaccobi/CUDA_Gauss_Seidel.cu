// This program is an exemple the vs setup for Cuda
#include <iostream>
#include <chrono>
#include<cuda_runtime.h>
#include<device_launch_parameters.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fstream>

__global__ void GaussSeidel(float * matrix , float * vector , float * x , int  r,int n, int red_black) {
	int i = blockIdx.x*blockDim.x + threadIdx.x;
	if (i < n && i%2 == red_black ) {

		x[i] = vector[i] / (*(matrix + i * n + i));
		
		for (int j = 0; j < n; j++) {
			if (j != i) {
				x[i] -= (*(matrix + i * n + j)*x[j]) / (*(matrix + i * n + i));
			}

		}

	}
}




float * laplacian2d_matrix(int size, int N) {
	float * laplacian;
	laplacian = (float*)malloc(size *size * sizeof(float));
	int side = (int)sqrt((double)size);
	for (int i = 0; i < size*size; i++) {
		laplacian[i] = 0;
	}
	for (int i = 0; i < size; i++) {
		if ((((i + 1) * size + i) < size * size) && (( (i+1) % side) != 0)) {
			laplacian[(i + 1) * size + i] = 1;
		}

		if (0 <= ((i - 1) * size + i) && ((i % side) != 0)) {
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


int main() {

	//laplace solver

	int size = 121; // For a square grid [size * size]

	//host input
	float * laplacian = (float*)malloc(size *size *size *size * sizeof(float));
	float * vector = (float*)malloc(size *size * sizeof(float));
	//device input
	float * laplacian_device;
	float * vector_device;

	//caling generator
	laplacian = laplacian2d_matrix(size*size, size);

	//creating inital values
	for (int i = 0; i < size*size; i++) {
		vector[i] = 0;
	}
	for (int i = 0; i < size; i++) {
		vector[(size - 1)*size + i] = -10;
	}
	//output host
	float * test_laplacian = (float*)malloc(size *size * sizeof(float));

	for (int i = 0; i < size*size; i++) {
		test_laplacian[i] = 0;
	}

	//device output
	float * test_laplacian_device;

	//test_laplacian = jacobi((float*)laplacian, vector, size*size,1e-4F);

	// Allocate memory for each vector on GPU
	cudaMalloc(&laplacian_device, size *size *size *size * sizeof(float));
	cudaMalloc(&vector_device, size *size * sizeof(float));
	cudaMalloc(&test_laplacian_device, size *size * sizeof(float));


	cudaMemcpy(laplacian_device, laplacian, size *size *size *size * sizeof(float), cudaMemcpyHostToDevice);
	cudaMemcpy(vector_device, vector, size *size * sizeof(float), cudaMemcpyHostToDevice);
	
	int blockSize, gridSize;

	// Number of threads in each thread block
	blockSize = 64;

	// Number of thread blocks in grid
	gridSize = (int)  (ceil((float)size*size / blockSize));


	// Execute the kernel
	for (int i = 0; i < 1000; i++) {
		GaussSeidel << <gridSize, blockSize >> > (laplacian_device, vector_device, test_laplacian_device, size, size*size, 0);//even index first
		GaussSeidel << <gridSize, blockSize >> > (laplacian_device, vector_device, test_laplacian_device, size, size*size, 1); // odd index
		std::cout << i << std::endl;
		cudaDeviceSynchronize(); // sync the result
	}


	//sync
	cudaDeviceSynchronize();

	// Copy array back to host
	cudaMemcpy(test_laplacian, test_laplacian_device, size *size * sizeof(float), cudaMemcpyDeviceToHost);


	//output csv file
	std::ofstream myfile;
	myfile.open("data.csv");
	for (int i = 0; i < size; i++)
	{
		myfile << test_laplacian[i*size + 0];

		for (int j = 1; j < size; j++)
		{
			myfile << ", " << test_laplacian[i*size + j];
		}
		myfile << std::endl;
	}
	myfile.close();

	// Release device memory
	cudaFree(vector_device);
	cudaFree(laplacian_device);
	cudaFree(test_laplacian_device);

	// Release host memory
	free(vector);
	free(laplacian);
	free(test_laplacian);
	return 0;
}
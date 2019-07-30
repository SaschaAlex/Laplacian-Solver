#include <iostream>
#include <cmath> 
#include <cstdlib>

float * laplacian1d_matrix(int size, int N) {
	float * laplacian;
	laplacian = (float*)malloc(size *size * sizeof(float));
	int side = (int)sqrt((double) size);
	for (int i = 0; i < size*size; i++) {
		laplacian[i] = 0;
	}
	for (int i = 0; i < size; i++) {
		if ((((i + 1) * size + i) < size * size) && ((i % side) != 0)) {
			laplacian[(i + 1) * size + i] = 1;
		}
		
		if (0 <= ((i - 1) * size + i) && ((i % side) != 0 )) {
			laplacian[(i - 1) * size + i] = 1;
		}

		laplacian[i * size + i] = -2;

		if (((i + N) * size + i) < size * size) {
			laplacian[(i + N) * size + i] = 1;
		}

		if (0 <= ((i - N) * size + i) ) {
			laplacian[(i - N) * size + i] = 1;
		}
	}
	return laplacian;

}



float * laplacian2d_matrix(int size, int N) {
	float * laplacian;
	laplacian = (float*)malloc(size *size * sizeof(float));
	int side = (int)sqrt((double)size);
	for (int i = 0; i < size*size; i++) {
		laplacian[i] = 0;
	}
	for (int i = 0; i < size; i++) {
		if ((((i + 1) * size + i) < size * size) && (((i + 1) % side) != 0)) {
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

double * laplacian2d_matrix_double(int size, int N) {
	double * laplacian;
	laplacian = (double*)malloc(size *size * sizeof(double));
	int side = (int)sqrt((double)size);
	for (int i = 0; i < size*size; i++) {
		laplacian[i] = 0;
	}
	for (int i = 0; i < size; i++) {
		if ((((i + 1) * size + i) < size * size) && (((i + 1) % side) != 0)) {
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

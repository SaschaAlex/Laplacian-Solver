#include <iostream>

float * laplacian_matrix(int size, int N) {
	float * laplacian;
	laplacian = (float*)malloc(size *size* sizeof(float));
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
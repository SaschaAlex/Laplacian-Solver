#pragma once
#include <cstdlib>

float * Ax(float * A, float *x, int vector_size) {
	float * residual = (float*)malloc(vector_size * sizeof(float));
	for (int i = 0; i < vector_size; i++) {
		residual[i] = 0;
		for (int j = 0; j < vector_size; j++) {
			residual[i] += *(A + i * vector_size + j) * x[j];
		}
	}
	return residual;
}



float * add_vector(float * a, float * b, int vector_size) {
	float * residual = (float*)malloc(vector_size * sizeof(float));
	for (int i = 0; i < vector_size; i++) {
		residual[i] = a[i] + b[i];
	}
	return residual;
}

float * mScalar(float scalar, float * vector, int vector_size) {
	float * residual = (float*)malloc(vector_size * sizeof(float));
	for (int i = 0; i < vector_size; i++) {
		residual[i] = scalar * vector[i];
	}
	return residual;
}
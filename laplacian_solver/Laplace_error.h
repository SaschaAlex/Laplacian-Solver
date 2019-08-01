#pragma once
#include <cstdlib>

float * residual(float * A, float * x, float * b, int vector_size) {
	float * residual_value = (float*) malloc(vector_size * sizeof(float));
	for (int i = 0; i < vector_size; i++) {
		residual_value[i] = b[i];
		for (int j = 0; j < vector_size; j++)
			residual_value[i] -= *(A + i * vector_size + j) * x[j];
	}
	return residual_value;
}
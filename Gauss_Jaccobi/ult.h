#pragma once

void show_matrix(float *  matrix, int r);
void show_vector(float * vector, int r);
float * laplacian_matrix(int size, int N);
float * jacobi(float * matrix, float * vector, int r, float precision);
float * sidel(float * matrix, float * vector, int r, float precision);
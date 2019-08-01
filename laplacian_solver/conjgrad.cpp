#include <iostream>
#include <cstdlib>
#include "Laplace_dot.h"
#include "Laplace_error.h"
#include "Laplace_matrix.h"
#include "cmath"

float * conjgrad(float * A, float * b, int vector_size,float precision) {
	float * x = (float*)malloc(vector_size * sizeof(float));
	for (int i = 0; i < vector_size; i++) {
		x[i] = 0;
	}
	float * r = residual(A, x, b, vector_size);
	float * p = r;
	float rsold = norm(r,vector_size);
	float * Ap;
	float alpha;
	float rsnew;
	while (true) {
		Ap = Ax(A, p, vector_size);
		alpha = rsold / dot(p, Ap,vector_size);
		x = add_vector(x, mScalar(alpha, p, vector_size),vector_size);
		r = add_vector(r, mScalar(-1*alpha, Ap, vector_size), vector_size);
		rsnew = norm(r, vector_size);
		std::cout << sqrt(rsnew) << std::endl;
		if (sqrt(rsnew) < precision) { // changing the floating value by the precision
			break;
		}
		p = add_vector(r, mScalar((rsnew / rsold), p, vector_size), vector_size);
		rsold = rsnew;
	}
	return x;
}
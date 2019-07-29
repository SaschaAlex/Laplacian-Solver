#include <cmath>
#include <iostream>
float * jacobi(float * matrix, float * vector, int r, float precision) {
	float * x = new float[r];
	float * x_holder = new float[r];
	bool convergence = true;
	while (convergence == true) {
		//convergence = true;
		for (int n = 0; n < r; n++) {
			x_holder[n] = vector[n] / (*(matrix + n * r + n));
			for (int i = 0; i < r; i++) {
				if (n != i) {
					x_holder[n] -= (*(matrix + n * r + i)*x[i]) / (*(matrix + n * r + n));
				}
			}
		}
		for (int l = 0; l < r; l++) {
			if (l % r == 0)
				std::cout << "Error: " << fabs(x[0] - x_holder[0]) << std::endl;
			if (fabs(x[l] - x_holder[l]) < precision && x[l] != x_holder[l]) {
				convergence = false;
			}
			x[l] = x_holder[l];
		}
	}
	return x;
}

double * jacobi(double * matrix, double * vector, int r, float precision) {
	double * x = new double[r];
	double * x_holder = new double[r];
	bool convergence = true;
	while (convergence == true) {
		convergence = true;
		for (int n = 0; n < r; n++) {
			x_holder[n] = vector[n] / (*(matrix + n * r + n));
			for (int i = 0; i < r; i++) {
				if (n != i) {
					x_holder[n] -= (*(matrix + n * r + i)*x[i]) / (*(matrix + n * r + n));
				}
			}
		}
		for (int l = 0; l < r; l++) {
			if (l % r == 0)
				std::cout << "Error: " << fabs(x[0] - x_holder[0]) << std::endl;
			if (fabs(x[l] - x_holder[l]) < precision && x[l] != x_holder[l]) {
				convergence = false;
			}
			x[l] = x_holder[l];
		}
	}
	return x;
}
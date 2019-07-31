#include <cmath>
#include <iostream>
#include <cstdlib>

float * sor(float * matrix, float * vector, int r, float precision) {
	float * x = new float[r];
	float * x_holder = new float[r];
	bool convergence = true;
	while (convergence == true) {
		//convergence test
		convergence = true;
		for (int n = 0; n < r; n++) {
			x_holder[n] = vector[n] / (*(matrix + n * r + n));
			for (int i = 0; i < r; i++) {
				if (n != i) {
					x_holder[n] -= (*(matrix + n * r + i)*x[i]) / (*(matrix + n * r + n));
				}
			}
			if (n % r*r == 0)
				std::cout << "Error: " << fabs(x[0] - x_holder[0]) << std::endl;
			//convergence test and update iteration
			if (fabs(x[n] - x_holder[n]) < precision && x[n] != x_holder[n]) {
				convergence = false;
			}
			x[n] = 1.73*x_holder[n]-0.73*x[n];
		}
	}
	return x;
}

double * sor(double * matrix, double * vector, int r, float precision) {
	double * x = new double[r];
	double * x_holder = new double[r];
	bool convergence = true;
	while (convergence == true) {
		//convergence test
		convergence = true;
		for (int n = 0; n < r; n++) {
			x_holder[n] = vector[n] / (*(matrix + n * r + n));
			for (int i = 0; i < r; i++) {
				if (n != i) {
					x_holder[n] -= (*(matrix + n * r + i)*x[i]) / (*(matrix + n * r + n));
				}
			}
			if (n % r*r == 0)
				std::cout << "Error: " << fabs(x[0] - x_holder[0]) << std::endl;
			//convergence test and update iteration
			if (fabs(x[n] - x_holder[n]) < precision && x[n] != x_holder[n]) {
				convergence = false;
			}
			x[n] = 1.73*x_holder[n]-0.73*x[n];
		}
	}
	return x;
}


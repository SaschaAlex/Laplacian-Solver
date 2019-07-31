#include <cmath>
#include <iostream>

float * v_cylce(float * matrix, float * vector, int r, float precision) {
	float * x = new float[r];
	float error = 999999; 
	for (int i = 0; i <10; i++ ) { // replace by convergence test but using a for loop for debuging 
		float * x_holder = new float[r];
		error = 0;
		for (int n = 0; n < r; n++) {
			x_holder[n] = vector[n] / (*(matrix + n * r + n));
			for (int i = 0; i < r; i++) {
				if (n != i) {
					x_holder[n] -= (*(matrix + n * r + i)*x[i]) / (*(matrix + n * r + n));
				}
			}
			if (fabs(x[n] - x_holder[n]) > error)
				error = fabs(x[0] - x_holder[0]);
			x[n] = 1.73*x_holder[n] - 0.73*x[n];
		}
		std::cout << error <<std::endl;
	}
	return x;
}
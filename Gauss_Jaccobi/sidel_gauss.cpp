#include <cmath>
#include <iostream>
float * sidel(float * matrix, float * vector, int r, float precision) {
	float * x = new float[r];
	float * x_holder = new float[r];
	bool convergence = true;
	while(convergence == true){
		convergence = true;

		//actual solver
		for (int n = 0; n < r; n++) {
			x_holder[n] = vector[n] / (*(matrix + n * r + n));
			for (int i = 0; i < r; i++) {
				if (n != i) {
					x_holder[n] -= (*(matrix + n * r + i)*x[i]) / (*(matrix + n * r + n));
				}
			}
			//convergence test and update iteration
			if (fabs(x[n] - x_holder[n]) < precision && x[n] != x_holder[n]) {
				convergence = false;
			}

			x[n] = x_holder[n];
		}



	}
	return x;
}

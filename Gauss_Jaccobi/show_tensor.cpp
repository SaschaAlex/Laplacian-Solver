#include <iostream>

void show_matrix(float *  matrix, int r) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < r; j++) {
			if (j == 0) {
				std::cout << "[" << *(matrix + i * r + j);

			}
			else if (j == r - 1)
			{
				std::cout << "," << *(matrix + i * r + j) << "]";
			}
			else
			{
				std::cout << "," << *(matrix + i * r + j);
			}

		}
		std::cout << std::endl;
	}
}

void show_vector(float * vector, int r) {
	for (int i = 0; i < r; i++) {
		std::cout << "[" << vector[i] << "]" << std::endl;
	}

}
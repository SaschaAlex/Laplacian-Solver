#pragma once
// flaot functions
float * laplacian_matrix(int size, int N);
float * jacobi(float * matrix, float * vector, int r, float precision);
float * sidel(float * matrix, float * vector, int r, float precision);
float * sor(float * matrix, float * vector, int r, float precision);


// double functions 
double * laplacian_matrix_double(int size,  int N);
double * jacobi(double * matrix, double * vector, int r, float precision);
double * sidel(double * matrix, double * vector, int r, float precision);
double * sor(double * matrix, double * vector, int r, float precision);

//show tensor
template<typename T>
void show_matrix(T *  matrix, int r) {
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

template<typename T>
void show_vector(T * vector, int r) {
	for (int i = 0; i < r; i++) {
		std::cout << "[" << vector[i] << "]" << std::endl;
	}

}
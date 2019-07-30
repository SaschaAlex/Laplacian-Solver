cmake_minimum_required (VERSION 2.6)
project (LaplaceSolver)
add_executable(LaplaceSolver exemple.cpp sor.cpp seidel_gauss.cpp jacobi_gauss.cpp  generate_laplacian.cpp)
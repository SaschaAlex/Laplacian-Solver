# Laplacian solver [![Build Status](https://travis-ci.org/SaschaAlex/Laplacian-Solver.svg?branch=master)](https://travis-ci.org/SaschaAlex/Laplacian-Solver)  [![CodeFactor](https://www.codefactor.io/repository/github/saschaalex/laplacian-solver/badge)](https://www.codefactor.io/repository/github/saschaalex/laplacian-solver)
A simple laplacian solver using iterative methods written in c++


## Requirements
* A modern c++ compiler
* [CMake](https://cmake.org/)  VERSION 2.6 / +



## Installation


Clone :
```sh
git clone https://github.com/SaschaAlex/Laplacian-Solver
```

## Compiling test

### CMake:

```sh
cmake ./laplacian_solver # and compile with a c++ compiler
```

### Code [Exemple](https://github.com/SaschaAlex/Laplacian-Solver/blob/master/laplacian_solver/exemple.cpp)
```cpp
#include <cstdlib>
#include "Laplace_solver.h"



int main() {
	
	//initializing variables  
	int size = 40;  // For a square grid [size * size]
	float * laplacian = (float*) malloc(size *size *size *size * sizeof(float)); 
	float * vector = (float*)malloc(size *size * sizeof(float));
	float * result = (float*)malloc(size *size * sizeof(float));


	//Generate a 2D laplacian Matrix
	laplacian = laplacian2d_matrix(size*size, size);

	//boundary conditions
	for (int i = 0; i < size*size; i++) {
		vector[i] = 0;
	}
	for (int i = 0; i < size; i++) {
			//vector[i] = -10;
			//vector[(4)*size + i] = -1;
			vector[(size - 1)*size + i]= -10;
	}


	//solver
	result = sor((float*)laplacian, vector, size*size, 1e-4F);
	
	//free memory 
	free(result);
	free(vector);
	free(laplacian);
	return 0;
}
```
###  Result

![](https://i.imgur.com/VxFA0hr.png)

## Contributing

1. Fork it (<https://github.com/SaschaAlex/Laplacian-Solver/fork>)
2. Create your feature branch (`git checkout -b feature/fooBar`)
3. Commit your changes (`git commit -am 'Add some fooBar'`)
4. Push to the branch (`git push origin feature/fooBar`)
5. Create a new Pull Request
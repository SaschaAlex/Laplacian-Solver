#pragma once

float dot(float * vector1, float * vector2,int vector_size) {
	float result = 0;
	for (int i = 0; i < vector_size; i++) {
		result += vector1[i] * vector2[i];
	}
	return result;
}

float norm(float * x,int vector_size) {
	return dot(x,x,vector_size);
}
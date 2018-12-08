#include "Mat2.h"
#include <iostream>

Mat2::Mat2() {
	Mat2(0, 0, 0, 0);
}

Mat2::Mat2(
	float f1, float f2, 
	float f3, float f4
) {
	m[0][0] = f1; m[0][1] = f2;
	m[1][0] = f3; m[1][1] = f4;
}
float Mat2::Det() {
	return (m[0][0] * m[1][1]) - (m[0][1] * m[1][0]);
}

void Mat2::SetNull() {
	for (size_t i = 0; i < m.size(); i++) {
		for (size_t j = 0; j < m.size(); j++) {
			m[i][j] = NULL;
		}
	}
}

// print the matrix to the console
void Mat2::Print() const {
	//iterate through all indices printing every value
	for (auto k : m) {
		for (float j : k) {
			std::cout << j << " ";
		}

		std::cout << std::endl;

	}
}
#include "Mat3.h"
#include <iostream>

Mat3::Mat3(
	float f1, float f2, float f3,
	float f4, float f5, float f6,
	float f7, float f8, float f9
	) {
	m[0][0] = f1; m[0][1] = f2; m[0][2] = f3;
	m[1][0] = f4; m[1][1] = f5; m[1][2] = f6;
	m[2][0] = f7; m[2][1] = f8; m[2][2] = f9;
}
float Mat3::Det() {
	float total = 0;
	float det2;
	int symbol;
	bool alternateSymbol = false;


	//loop through each index to get base multiplier
	for (int a = 0; a < m.size(); a++) {
		for (int b = 0; b < m.size(); b++) {
			//current indicies are the current index of the temporary 2d vector
			int currentXIndex = 0;
			int currentYIndex = 0;
			Mat2 tempMat;
			
			//loop through each index to put it in
			for (int c = 0; c < m.size(); c++) {
				for (int d = 0; d < m.size(); d++) {
					if (currentXIndex >= tempMat.m.size()) {
						currentXIndex = 0;
						currentYIndex = 1;
					}
					if (c != a && d != b) {
						tempMat.m[currentXIndex][currentYIndex] = m[d][c];
						currentXIndex++;
					}
				}
			}

			//calculates checkerboard pattern
			alternateSymbol != alternateSymbol;
			if (!alternateSymbol) symbol = 1;
			else symbol = -1;
			//total += symbol * m[0][i] * det2;
		}
	}
	this->Print();
	float x =  m[0][0] * Mat2(m[1][1], m[1][2], m[2][1], m[2][2]).Det();
	float y = -m[0][1] * Mat2(m[1][0], m[1][2], m[2][0], m[2][2]).Det();
	float z =  m[0][2] * Mat2(m[1][0], m[1][1], m[2][0], m[2][1]).Det();
	return x + y + z;
}

// print the matrix to the console
void Mat3::Print() const {
	//iterate through all indices printing every value
	for (auto k : m) {
		for (float j : k) {
			std::cout << j << " ";
		}

		std::cout << std::endl;

	}
}
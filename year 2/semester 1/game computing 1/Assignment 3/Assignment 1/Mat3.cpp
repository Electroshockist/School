#include "Mat3.h"
#include <iostream>

Mat3::Mat3() {
	for (int i = 0; i < m.size(); i++) {
		for (int j = 0; j < m.size(); j++) {
			m[i][j] = 0;
		}
	}
}

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
	float det;
	int symbol;
	bool alternateSymbol = false;
	Mat3 resultMat;


	//loop through each row to get base multiplier
	/*
	|X X X|
	|` ` `|
	|` ` `|
	*/
	for (int a = 0; a < m.size(); a++) {
			//current indicies are the current index of the temporary 2d vector
			/*
			|` `|
			|` `|
			*/
			int currentXIndex = 0;
			int currentYIndex = 0;
			Mat2 tempMat;
			
			//loop through each index to put it in
			for (int b = 0; b < m.size(); b++) {
				//starts at 1 and not 0 to automatically skip first row where the multiplier will always be
				for (int c = 1; c < m.size(); c++) {

					//2D x and y index calculations
					/*
					  |` `|->
					->|` `|
					*/
					if (currentXIndex >= tempMat.m.size()) {
						currentXIndex = 0;
						currentYIndex++;
					}

					//if current loop values not equal to column of multiplyer, add to vec2, increase vec2 index
					if (b != a) {
						tempMat.m[currentXIndex][currentYIndex] = m[c][b];
						currentXIndex++;
					}
				}
			}
			//calculates checkerboard pattern
			if (!alternateSymbol) symbol = 1;
			else symbol = -1;

			total += symbol * m[0][a] * tempMat.Det();

			alternateSymbol = !alternateSymbol;
	}
	return total;
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
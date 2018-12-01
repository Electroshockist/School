#include "Mat3.h"
#include "Mat4.h"

// Set member variables to the values inside the identity matrix
Mat4::Mat4() {
	for (int i = 0; i < m.size(); i++) {
		for (int j = 0; j < m[i].size(); j++) {
			m[i][j] = 0;
		}
	}
}

Mat4::Mat4(
	float f1, float f2, float f3, float f4,
	float f5, float f6, float f7, float f8,
	float f9, float f10, float f11, float f12,
	float f13, float f14, float f15, float f16
) {
	m[0][0] = f1;  m[0][1] = f2;  m[0][2] = f3;  m[0][3] = f4;
	m[1][0] = f5;  m[1][1] = f6;  m[1][2] = f7;  m[1][3] = f8;
	m[2][0] = f9;  m[2][1] = f10; m[2][2] = f11; m[2][3] = f12;
	m[3][0] = f13; m[3][1] = f14; m[3][2] = f15; m[3][3] = f16;
}

Mat4::Mat4(Vec4 v1, Vec4 v2, Vec4 v3, Vec4 v4) {
	setRow(0, v1);
	setRow(1, v2);
	setRow(2, v3);
	setRow(3, v4);
}

// Set this matrix to the Identity Matrix
void Mat4::SetIdentity() {
	//iterate through all indices setting the diagonal to ones and everything else to zeros
	for (int i = 0; i < m.size(); i++) {
		for (int j = 0; j < m[0].size(); j++) {
			if (i == j) m[i][j] = 1;
			else m[i][j] = 0;
		}
	}
}

//sets a row of the matrix given a row number and a Vec4
void Mat4::setRow(int row, Vec4 v) {
	m[row][0] = v.x;
	m[row][1] = v.y;
	m[row][2] = v.z;
	m[row][3] = v.w;
}

// Set to the Rotation Matrix about x
void Mat4::RotateX(float angleInDegrees) {
	//converts degrees to radians
	float theta = angleInDegrees * DEGREES_TO_RADIANS;
	Mat4 rotationMatrix = Mat4();

	rotationMatrix.SetIdentity();

	//calls a function to check if the result of the cos or sin function will be too small for a float to handle
	rotationMatrix.m[1][1] = checkCos(theta); rotationMatrix.m[1][2] = -checkSin(theta);
	rotationMatrix.m[2][2] = checkCos(theta); rotationMatrix.m[2][1] = checkSin(theta);	

	//multiplies the rotation matrix with itself, completing the rotation
	*this = *this * rotationMatrix;
}

// Set to the Rotation Matrix about y
void Mat4::RotateY(float angleInDegrees) {
	//converts degrees to radians
	float theta = angleInDegrees * DEGREES_TO_RADIANS;
	Mat4 rotationMatrix = Mat4();

	rotationMatrix.SetIdentity();

	//calls a function to check if the result of the cos or sin function will be too small for a float to handle
	rotationMatrix.m[0][0] = checkCos(theta); rotationMatrix.m[0][2] = -checkSin(theta);
	rotationMatrix.m[2][0] = checkCos(theta); rotationMatrix.m[2][2] = checkSin(theta);

	//multiplies the rotation matrix with itself, completing the rotation
	*this = *this * rotationMatrix;
}

// Set to the Rotation Matrix about z =
void Mat4::RotateZ(float angleInDegrees) {
	//converts degrees to radians
	float theta = angleInDegrees * DEGREES_TO_RADIANS;
	Mat4 rotationMatrix = Mat4();

	rotationMatrix.SetIdentity();

	//calls a function to check if the result of the cos or sin function will be too small for a float to handle
	rotationMatrix.m[0][0] = checkCos(theta); rotationMatrix.m[0][1] = -checkSin(theta);
	rotationMatrix.m[1][0] = checkCos(theta); rotationMatrix.m[1][1] = checkSin(theta);

	//multiplies the rotation matrix with itself, completing the rotation
	*this = *this * rotationMatrix;

}

// Set to the Scaling Matrix
void Mat4::Scale(float x, float y, float z) {
	Mat4 scalingMatrix = Mat4();
	scalingMatrix.SetIdentity();

	scalingMatrix.m[0][0] = x;
	scalingMatrix.m[1][1] = y;
	scalingMatrix.m[2][2] = z;

	*this = *this * scalingMatrix;
}

// Set to the Translation Matrix
void  Mat4::Translate(Vec3 translation) {
	Mat4 translationMatrix = Mat4();

	translationMatrix.m[0][3] = translation.x;
	translationMatrix.m[1][3] = translation.y;
	translationMatrix.m[2][3] = translation.z;

	*this = *this * translationMatrix;
}

// Swap rows and columns
void Mat4::Transpose() {
	Mat4 tempMatrix;

	for (int i = 0; i < m.size(); i++) {
		for (int j = 0; j < m[0].size(); j++) {
			tempMatrix.m[j][i] = m[i][j];
		}
	}
	*this = tempMatrix;
}

// Return the determinant of the matrix
float Mat4::Det() {
	float total = 0;
	float det;
	int symbol;
	bool alternateSymbol = false;
	Mat4 resultMat;


	//loop through each row to get base multiplier
	/*
	|X X X X|
	|` ` ` `|
	|` ` ` `|
	*/
	for (int a = 0; a < m.size(); a++) {
		//current indicies are the current index of the temporary 2d vector
		/*
		|` ` `|
		|` ` `|
		|` ` `|
		*/
		int currentXIndex = 0;
		int currentYIndex = 0;
		Mat3 tempMat;

		//loop through each index to put it in
		for (int b = 0; b < m.size(); b++) {
			//starts at 1 and not 0 to automatically skip first row where the multiplier will always be
			for (int c = 1; c < m.size(); c++) {

				//2D x and y index calculations
				/*
				  |` ` `|->
				->|` ` `|->
				->|` ` `|
				*/
				if (currentXIndex >= tempMat.m.size()) {
					currentXIndex = 0;
					currentYIndex++;
				}

				//if current loop values not equal to column of multiplyer, add to vec3, increase vec3 index
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

// Invert the matrix using minors, cofactors and adjugate
// Your life may be easier if you create a 3x3 Mat3 class with a Det and Transpose method to use here!
void Mat4::Inverse() {
	int symbol;
	bool alternateSynbol = false;
	float det = this->Det();

	Mat3 m0(m[1][1], m[1][2], m[1][3], m[2][1], m[2][2], m[2][3], m[3][1], m[3][2], m[3][3]); // + 
	Mat3 m1(m[1][0], m[1][2], m[1][3], m[2][0], m[2][2], m[2][3], m[3][0], m[3][2], m[3][3]); // - 
	Mat3 m2(m[1][0], m[1][1], m[1][3], m[2][0], m[2][1], m[2][3], m[3][0], m[3][1], m[3][3]);  // + 
	Mat3 m3(m[1][0], m[1][1], m[1][2], m[2][0], m[2][1], m[2][2], m[3][0], m[3][1], m[3][2]);  // -

	Mat3 m4(m[0][1], m[0][2], m[0][3], m[2][1], m[2][2], m[2][3], m[3][1], m[3][2], m[3][3]); // - 
	Mat3 m5(m[0][0], m[0][2], m[0][3], m[2][0], m[2][2], m[2][3], m[3][0], m[3][2], m[3][3]); // + 
	Mat3 m6(m[0][0], m[0][1], m[0][3], m[2][0], m[2][1], m[2][3], m[3][0], m[3][1], m[3][3]);  // - 
	Mat3 m7(m[0][0], m[0][1], m[0][2], m[2][0], m[2][1], m[2][2], m[3][0], m[3][1], m[3][2]);  // +

	Mat3 m8(m[0][1], m[0][2], m[0][3], m[1][1], m[1][2], m[1][3], m[3][1], m[3][2], m[3][3]);   // +
	Mat3 m9(m[0][0], m[0][2], m[0][3], m[1][0], m[1][2], m[1][3], m[3][0], m[3][2], m[3][3]);   // -
	Mat3 m10(m[0][0], m[0][1], m[0][3], m[1][0], m[1][1], m[1][3], m[3][0], m[3][1], m[3][3]);  // +
	Mat3 m11(m[0][0], m[0][1], m[0][2], m[1][0], m[1][1], m[1][2], m[3][0], m[3][1], m[3][2]);  // -

	Mat3 m12(m[0][1], m[0][2], m[0][3], m[1][1], m[1][2], m[1][3], m[2][1], m[2][2], m[2][3]);   // -
	Mat3 m13(m[0][0], m[0][2], m[0][3], m[1][0], m[1][2], m[1][3], m[2][0], m[2][2], m[2][3]);   // + 
	Mat3 m14(m[0][0], m[0][1], m[0][3], m[1][0], m[1][1], m[1][3], m[2][0], m[2][1], m[2][3]);// -
	Mat3 m15(m[0][0], m[0][1], m[0][2], m[1][0], m[1][1], m[1][2], m[2][0], m[2][1], m[2][2]);// + 

	Mat4 tempMat(m0.Det(), m1.Det(), m2.Det(), m3.Det(), m4.Det(), m5.Det(), m6.Det(), m7.Det(), m8.Det(), m9.Det(), m10.Det(), m11.Det(), m12.Det(), m13.Det(), m14.Det(), m15.Det());

	tempMat.Transpose();
	det = 1 / det;

	//todo: figure out why this doesn't work
	for (int i = 0; i < m.size(); i++) {
		for (int j = 0; j < m.size(); j++) {
			if (!alternateSynbol) symbol = 1;
			else symbol = -1;

			m[i][j] = tempMat.m[i][j] * det * symbol;
			alternateSynbol = !alternateSynbol;
		}
	}

	//working math
	m[0][0] = tempMat.m[0][0] * det;
	m[0][1] = tempMat.m[0][1] * det * -1;
	m[0][2] = tempMat.m[0][2] * det;
	m[0][3] = tempMat.m[0][3] * det* -1;

	m[1][0] = tempMat.m[1][0] * det* -1;
	m[1][1] = tempMat.m[1][1] * det;
	m[1][2] = tempMat.m[1][2] * det* -1;
	m[1][3] = tempMat.m[1][3] * det;

	m[2][0] = tempMat.m[2][0] * det;
	m[2][1] = tempMat.m[2][1] * det * -1;
	m[2][2] = tempMat.m[2][2] * det;
	m[2][3] = tempMat.m[2][3] * det * -1;

	m[3][0] = tempMat.m[3][0] * det* -1;
	m[3][1] = tempMat.m[3][1] * det;
	m[3][2] = tempMat.m[3][2] * det* -1;
	m[3][3] = tempMat.m[3][3] * det;
}


// print the matrix to the console
void Mat4::Print() const {
	//iterate through all indices printing every value
	for (auto k : m) {
		for (float j : k) {
			std::cout << j << " ";
		}

		std::cout << std::endl;
	
	}
}

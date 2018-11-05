#include "Mat4.h"

// Set member variables to the values inside the identity matrix
Mat4::Mat4() {
	SetIdentity();
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

// Set to the Rotation Matrix about x
void Mat4::RotateX(float angleInDegrees) {
	//converts degrees to radians
	float theta = angleInDegrees * DEGREES_TO_RADIANS;
	Mat4 rotationMatrix = Mat4();

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

	//calls a function to check if the result of the cos or sin function will be too small for a float to handle
	rotationMatrix.m[0][0] = checkCos(theta); rotationMatrix.m[0][1] = -checkSin(theta);
	rotationMatrix.m[1][0] = checkCos(theta); rotationMatrix.m[1][1] = checkSin(theta);

	//multiplies the rotation matrix with itself, completing the rotation
	*this = *this * rotationMatrix;

}

// Set to the Scaling Matrix
void Mat4::Scale(float x, float y, float z) {
	Mat4 scalingMatrix = Mat4();
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

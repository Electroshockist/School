#pragma once
#include "Vec3.h"
#include "Vec4.h"

#include <array>
#include <iostream>
#include <math.h>

#ifndef VERY_SMALL
#define VERY_SMALL 1.0e-7f
#endif

#ifndef PI
#define PI 3.14159265358979323846f
#endif

#ifndef DEGREES_TO_RADIANS
#define DEGREES_TO_RADIANS (PI / 180.0f)
#endif	


class Mat4
{
public:
	//Multiply matrices
	inline Mat4 operator * (const Mat4& mat)const {
		Mat4 mat4 = Mat4();
		/*j iterates through each column of m, then i iterates from left to right
		while iterating normally through the second matrix, multiplying each set of iterations*/

		for (int i = 0; i < m.size(); i++) {
			for (int j = 0; j < m[0].size(); j++) {
				mat4.m[i][j] = m[j][m.size() - (i + 1)] * mat.m[i][j];
			}
		}
		return mat4;
	}

	// Sixteen elements of the 4x4 matrix held inside an array
	std::array<std::array<float, 4>, 4> m;
	
	// Set member variables to the values inside the identity matrix
	Mat4();

	Mat4(Vec4 v1, Vec4 v2, Vec4 v3, Vec4 v4);

	void setRow(int row, Vec4 v);

	// Set this matrix to the Identity Matrix =  
	void SetIdentity();
		
	// Set to the Rotation Matrix about x =
	void RotateX(float angleInDegrees);

	// Set to the Rotation Matrix about y =
	void RotateY(float angleInDegrees);

	// Set to the Rotation Matrix about z =
	void RotateZ(float angleInDegrees);

	// Set to the Scaling Matrix =
	void Scale(float x, float y, float z);

	// Set to the Translation Matrix =
	void Translate(Vec3 translation);

	// Swap rows and columns
	void Transpose();

	// Return the determinant of the matrix
	float Det();

	// Invert the matrix using minors, cofactors and adjugate
	// Your life may be easier if you create a 3x3 Mat3 class with a Det and Transpose method to use here!
	void Inverse();

	// print the matrix to the console
	void Print() const;

private:

	//get absolute cos value and check if it's too small for a float to hold correctly
	inline float checkCos(float angle) {
		if (abs(cos(angle)) > VERY_SMALL) return cos(angle);
		else return 0;
	}

	//get absolute sin value and check if it's too small for a float to hold correctly
	inline float checkSin(float angle) {
		if (abs(cos(angle)) > VERY_SMALL) return sin(angle);
		else return 0;
	}
};


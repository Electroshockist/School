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
		Mat4 result = Mat4();
		result.m[0][0] = m[0][0] * mat.m[0][0] + m[0][1] * mat.m[1][0] + mat.m[0][2] * mat.m[2][0] + mat.m[0][3] * mat.m[3][0];
		result.m[0][1] = m[0][0] * mat.m[0][1] + m[0][1] * mat.m[1][1] + mat.m[0][2] * mat.m[2][1] + mat.m[0][3] * mat.m[3][1];
		result.m[0][2] = m[0][0] * mat.m[0][2] + m[0][1] * mat.m[1][2] + mat.m[0][2] * mat.m[2][2] + mat.m[0][3] * mat.m[3][2];
		result.m[0][3] = m[0][0] * mat.m[0][3] + m[0][1] * mat.m[1][3] + mat.m[0][2] * mat.m[2][3] + mat.m[0][3] * mat.m[3][3];

		result.m[1][0] = m[1][0] * mat.m[0][0] + m[1][1] * mat.m[1][0] + mat.m[1][2] * mat.m[2][0] + mat.m[1][3] * mat.m[3][0];
		result.m[1][1] = m[1][0] * mat.m[0][1] + m[1][1] * mat.m[1][1] + mat.m[1][2] * mat.m[2][1] + mat.m[1][3] * mat.m[3][1];
		result.m[1][2] = m[1][0] * mat.m[0][2] + m[1][1] * mat.m[1][2] + mat.m[1][2] * mat.m[2][2] + mat.m[1][3] * mat.m[3][2];
		result.m[1][3] = m[1][0] * mat.m[0][3] + m[1][1] * mat.m[1][3] + mat.m[1][2] * mat.m[2][3] + mat.m[1][3] * mat.m[3][3];

		result.m[2][0] = m[2][0] * mat.m[0][0] + m[2][1] * mat.m[1][0] + mat.m[2][2] * mat.m[2][0] + mat.m[2][3] * mat.m[3][0];
		result.m[2][1] = m[2][0] * mat.m[0][1] + m[2][1] * mat.m[1][1] + mat.m[2][2] * mat.m[2][1] + mat.m[2][3] * mat.m[3][1];
		result.m[2][2] = m[2][0] * mat.m[0][2] + m[2][1] * mat.m[1][2] + mat.m[2][2] * mat.m[2][2] + mat.m[2][3] * mat.m[3][2];
		result.m[2][3] = m[2][0] * mat.m[0][3] + m[2][1] * mat.m[1][3] + mat.m[2][2] * mat.m[2][3] + mat.m[2][3] * mat.m[3][3];
		
		result.m[3][0] = m[3][0] * mat.m[0][0] + m[3][1] * mat.m[1][0] + mat.m[3][2] * mat.m[2][0] + mat.m[3][3] * mat.m[3][0];
		result.m[3][1] = m[3][0] * mat.m[0][1] + m[3][1] * mat.m[1][1] + mat.m[3][2] * mat.m[2][1] + mat.m[3][3] * mat.m[3][1];
		result.m[3][2] = m[3][0] * mat.m[0][2] + m[3][1] * mat.m[1][2] + mat.m[3][2] * mat.m[2][2] + mat.m[3][3] * mat.m[3][2];
		result.m[3][3] = m[3][0] * mat.m[0][3] + m[3][1] * mat.m[1][3] + mat.m[3][2] * mat.m[2][3] + mat.m[3][3] * mat.m[3][3];;


		////the first two for loops iterate through the resultant matrix
		//for (int i = 0; i < result.m.size(); i++) {
		//	for (int j = 0; j < result.m[i].size(); j++) {
		//		printf("[%i, %i] = ", i, j);
		//		//this loop iterates through the matricies that will be multiplied and multiplies and adds them
		//		for (int k = 0; k < m.size(); k++) {
		//			//printf(" [%i, %i] * [%i, %i] ", j, k, k, j);
		//			std::cout << m[i][j] << "*" << mat.m[j][k] << " ";
		//			result.m[i][j] += (m[i][j] * mat.m[k][j]);

		//			if (k != 3){
		//				printf("+ ");
		//			}

		//		}
		//		//std::cout << std::endl;
		//		
		//		//std::cout << std::endl << result.m[i][j] << std::endl;
		//	}
		//	std::cout << std::endl;
		//}
		return result;
	}

	// Sixteen elements of the 4x4 matrix held inside an array
	std::array<std::array<float, 4>, 4> m;
	
	// Set member variables to the values inside the identity matrix
	Mat4();

	Mat4(
		float f1, float f2, float f3, float f4,
		float f5, float f6, float f7, float f8,
		float f9, float f10, float f11, float f12,
		float f13, float f14, float f15, float f16
		);

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


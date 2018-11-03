#pragma once
#include <iostream>
#include <math.h>
#include "Vec3.h"
class Vec4
{
public:
	float x, y, z, w;

	//Add vectors
	inline Vec4 operator + (const Vec4& v)const {
		return Vec4(x + v.x, y + v.y, z + v.z, w + v.w);
	}
	//Subtract vectors
	inline Vec4 operator - (const Vec4& v)const {
		return Vec4(x - v.x, y - v.y, z - v.z, w - v.w);
	}
	//Multiply vectors
	inline Vec4 operator * (const Vec4& v)const {
		return Vec4(x * v.x, y * v.y, z * v.z, w * v.w);
	}
	//Divide vectors
	inline Vec4 operator / (const Vec4& v)const {
		return Vec4(x / v.x, y / v.y, z / v.z, w / v.w);
	}
	//Divide vector by float
	inline Vec4 operator / (const float& f)const {
		return Vec4(x / f, y / f, z / f, w / f);
	}

	// Set the x, y, z member variables
	Vec4(float x_, float y_, float z_, float w_);

	//take Vec3
	Vec4(Vec3 v3);

	// Set all x, y, z to zero, and w to one
	Vec4();

	// Return the magnitude of the vector using Pythagoras’s theorem
	float Magnitude();

	// Normalize the vector by dividing it by it’s magnitude
	void Normalize();

	// Dot this vector with the other one
	float Dot(Vec4 otherVec);

	void print();
	
	~Vec4();
};


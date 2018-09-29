#pragma once
#include <math.h>
#include <iostream>
class Vec3 {
public:
	//Add vectors
	inline Vec3 operator + (const Vec3& v)const {
		return Vec3(x + v.x, y + v.y, z + v.z);
	}
	//Subtract vectors
	inline Vec3 operator - (const Vec3& v)const {
		return Vec3(x - v.x, y - v.y, z - v.z);
	}
	//Multiply vectors
	inline Vec3 operator * (const Vec3& v)const {
		return Vec3(x * v.x, y * v.y, z * v.z);
	}
	//Divide vectors
	inline Vec3 operator / (const Vec3& v)const {
		return Vec3(x / v.x, y / v.y, z / v.z);
	}
	//Divide vector by float
	inline Vec3 operator / (const float& f)const {
		Vec3 v = *this;
		return Vec3(v.x /= f, v.y /= f, v.z /= f);
	}

	float x, y, z;

	// Set the x, y, z member variables
	Vec3(float x, float y, float z);

	// Set all x, y, z to zero
	Vec3();

	// Add other vector to this vector
	void Add(Vec3 v);

	// Subtract other vector from this vector
	void Subtract(Vec3 v);

	// Multiply this vector by a number
	void ScalarMultiplication(float scalar);

	// Return the magnitude of the vector using Pythagoras’s theorem
	float Magnitude();

	// Normalize the vector by dividing it by it’s magnitude
	void Normalize();

	// Take the cross product of the x, y, z of this vector with x, y, z of the other one. 
	Vec3 Cross(Vec3 v);

	void print();

	~Vec3();
};

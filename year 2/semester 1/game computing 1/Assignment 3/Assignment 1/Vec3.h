#pragma once

#include <math.h>
#include <iostream>

class Vec4;

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
	//Multiply vector by float
	inline Vec3 operator * (const float& f)const {
		return Vec3(x * f, y * f, z * f);
	}
	//Divide vectors
	inline Vec3 operator / (const Vec3& v)const {
		return Vec3(x / v.x, y / v.y, z / v.z);
	}
	//Divide vector by float
	inline Vec3 operator / (const float& f)const {
		return Vec3(x / f, y / f, z / f);
	}
	// Overload the * operator to multiply this matrix with a 4D vector to return a new Vec3 (throw away the w component)
	Vec3 operator * (const Vec4& v) const;

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

	float Dot(Vec3 v);

	void print();

	~Vec3();
};

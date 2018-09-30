#include "Vec3.h"
#include <math.h>
#include <iostream>

Vec3::Vec3(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}
Vec3::Vec3() {
	x = 0;
	y = 0;
	z = 0;
}

void Vec3::Add(Vec3 v) {
	x += v.x;
	y += v.y;
	z += v.z;
}

void Vec3::Subtract(Vec3 v) {
	x -= v.x;
	y -= v.y;
	z -= v.z;
}

void Vec3::ScalarMultiplication(float scalar) {
	x *= scalar;
	y *= scalar;
	z *= scalar;
}

float Vec3::Magnitude() {
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

void Vec3::Normalize(){
	*this = *this / Magnitude();
}
Vec3 Vec3 :: Cross(Vec3 v) {
	Vec3 vt(y*v.z - z * v.y, z*v.x - x * v.z, x*v.y - y * v.x);
	return vt;
}

void Vec3::print() {
	std::cout << x << " " << y << " " << z <<"\n";
}

Vec3::~Vec3() {
}


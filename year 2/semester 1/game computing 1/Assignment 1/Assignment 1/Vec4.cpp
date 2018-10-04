#include "Vec4.h"
// Set the x, y, z member variables
Vec4::Vec4(float x_, float y_, float z_, float w_) {
	x = x_;
	y = y_;
	z = z_;
	w = w_;
}

// Set all x, y, z to zero, and w to one
Vec4::Vec4() {
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

// Return the magnitude of the vector using Pythagoras’s theorem
float Vec4::Magnitude() {
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2) + pow(w, 2));
}

// Normalize the vector by dividing it by it’s magnitude
void Vec4::Normalize() {
	*this = *this / Magnitude();
}

// Dot this vector with the other one
float Vec4::Dot(Vec4 v) {
	return (x * v.x + y * v.y + z * v.z + w * v.w);
}

void Vec4::print() {
	std::cout << x << " " << y << " " << z << " " <<  w << "\n";
}

Vec4::~Vec4(){}

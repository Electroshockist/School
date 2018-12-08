#include "Quaternion.h"
#include "Math.h"

using namespace AngleMath;

Quaternion::Quaternion() {}

Quaternion::Quaternion(Vec4 quaternion) {
	x = quaternion.x;
	y = quaternion.y;
	z = quaternion.z;
	w = quaternion.w;
}

Quaternion::Quaternion(Vec3 axis, float angleInDegrees) {
	float angleInRadians = angleInDegrees * DEGREES_TO_RADIANS;
	axis.Normalize();
	x = Math::checkSin(angleInRadians/2) * axis.x;
	y = Math::checkSin(angleInRadians/2) * axis.y;
	z = Math::checkSin(angleInRadians/2) * axis.z;
	w = Math::checkCos(angleInRadians/2);
}

Quaternion::~Quaternion() {}

float Quaternion::Mag() {
	return sqrt(pow(w, 2) + pow(x, 2) + pow(y, 2) + pow(z, 2));
}

void Quaternion::Normalize() {
	//Normalizes by calling the Magnitude method
	float mag = Mag();
	x /= mag;
	y /= mag;
	z /= mag;
	w /= mag;
}

void Quaternion::Conjugate() {
	x = -x;
	y = -y;
	z = -z;
}

void Quaternion::Inverse() {
	float mag = Mag();
	Conjugate();

	*this /= pow(mag, 2);
}

Vec3 Quaternion::Rotate(Vec3 vec) {
	Vec3 result;
	Quaternion inverse;

	inverse = *this;
	inverse.Inverse();

	inverse.print();
	vec.print();
	Vec3(x, y, z).print();
	Vec3(inverse.x, inverse.y, inverse.z).print();

	result = Vec3(x, y, z) * vec * Vec3(inverse.x, inverse.y,inverse.z);
	return result;
}

void Quaternion::Slerp(Quaternion otherQuat, float t) {
	float temp1;
	float temp2;
	float theta;
	theta = acos((w * otherQuat.w) + (x * otherQuat.x) + (y * otherQuat.y) + (z * otherQuat.z));

	temp1 = (sin(theta *(1 - t))) / (sin(theta));
	temp2 = ((sin(t * theta)) / (sin(theta)));

	w *= temp1;
	x *= temp1;
	y *= temp1;
	z *= temp1;

	otherQuat.w *= temp2;
	otherQuat.x *= temp2;
	otherQuat.y *= temp2;
	otherQuat.z *= temp2;

	w += otherQuat.w;
	x += otherQuat.x;
	y += otherQuat.y;
	z += otherQuat.z;
}

Mat3 Quaternion::ConvertToMatrix() {
	Mat3 result;
	result.m[0][0] = 1 - 2 * (pow(y, 2)) - 2 * (pow(z, 2));
	result.m[0][1] = (2 * x * y) + (2 * w * z);
	result.m[0][2] = (2 * x * z) - (2 * w * y);
	result.m[1][0] = (2 * x * y) - (2 * w * z);
	result.m[1][1] = 1 - 2 * (pow(x, 2)) - 2 * (pow(z, 2));
	result.m[1][2] = (2 * y * z) + (2 * w * x);
	result.m[2][0] = (2 * x * z) + (2 * w * y);
	result.m[2][1] = (2 * y * z) + (2 * w * x);
	result.m[2][2] = 1 - 2 * (pow(x, 2)) - 2 * (pow(y, 2));
	return result;
}

void Quaternion::print() {
	std::cout << x << " " << y << " " << z << " " << w << "\n";
}
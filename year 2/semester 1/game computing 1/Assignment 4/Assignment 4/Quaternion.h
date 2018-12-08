#pragma once
#include "Vec3.h"
#include "Vec4.h"
#include "Mat3.h"
#include "Mat4.h"
#include <math.h>
class Quaternion :Vec4
{
public:
	inline Quaternion operator * (Quaternion otherQuat) {
		Quaternion result;
		result.x = (w * otherQuat.x) + (x * otherQuat.w) + (y * otherQuat.z) - (z * otherQuat.y);
		result.y = (w * otherQuat.y) + (y * otherQuat.w) + (z * otherQuat.x) - (x * otherQuat.z);
		result.z = (w * otherQuat.z) + (z * otherQuat.w) + (x * otherQuat.y) - (y * otherQuat.x);
		result.w = (w * otherQuat.w) - (x * otherQuat.x) - (y * otherQuat.y) - (z * otherQuat.z);
		return result;
	}

	inline Quaternion operator /= (float f) {
		Quaternion result = *this;
		result.x /= f;
		result.y /= f;
		result.z /= f;
		result.w /= f;
		return result;
	}

	float Mag();
	void Normalize();
	void Conjugate();
	void Inverse();
	Vec3 Rotate(Vec3 vec);
	void Slerp(Quaternion otherQuat, float t);
	void print();
	Mat3 ConvertToMatrix();
	Quaternion();
	Quaternion(Vec4 quat_);
	Quaternion(Vec3 axis, float angleInDegrees);
	~Quaternion();
};
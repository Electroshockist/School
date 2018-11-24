#pragma once
#include <array>
#include "Mat2.h"
class Mat3
{
public:
	// Sixteen elements of the 3x3 matrix held inside an array
	std::array<std::array<float, 3>, 3> m;
	Mat3(
		float f1, float f2, float f3,
		float f4, float f5, float f6,
		float f7, float f8,	float f9
	);
	float Det();
	void Print() const;
};


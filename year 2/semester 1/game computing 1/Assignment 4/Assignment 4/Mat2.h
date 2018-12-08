#pragma once
#include <array>
class Mat2
{
public:
	// Sixteen elements of the 3x3 matrix held inside an array
	std::array<std::array<float, 2>, 2> m;
	Mat2();
	Mat2(
		float f1, float f2,
		float f3, float f4
	);
	float Det();
	void SetNull();
	void Print() const;
};


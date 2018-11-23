#include "Mat3.h"



Mat3::Mat3(
	float f1, float f2, float f3,
	float f4, float f5, float f6,
	float f7, float f8, float f9
	) {
	m[0][0] = f1; m[0][1] = f2; m[0][2] = f3;
	m[0][3] = f4; m[1][0] = f5; m[1][1] = f6;
	m[1][2] = f7; m[1][3] = f8; m[2][0] = f9;
}
float Mat3::Det() {
	float x =  m[0][0] * ((m[1][1] * m[2][2]) - (m[2][1] * m[1][2]));
	float y = -m[0][1] * ((m[1][0] * m[2][2]) - (m[1][2] * m[2][0]));
	float z =  m[0][2] * ((m[1][0] * m[2][1]) - (m[1][1] * m[2][0]));
	return x + y + z;
}
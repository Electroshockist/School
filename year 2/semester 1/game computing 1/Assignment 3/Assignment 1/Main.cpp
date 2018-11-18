#include "Mat4.h"

using namespace std;

void main() {
	Vec3 translation(1, 2, 3);
	Mat4 mat;
	mat.Translate(translation);

	//mat * Vec4(1, 1, 1, 1);

	//• Multiply this matrix by the 4D vector[1, 1, 1, 1]

	Vec4 initialPosition(0, 0, 0, 1);
	//Vec3 finalPosition = mat * initialPosition;

	getchar();
}
#include "Mat4.h"
#include "Mat3.h"
#include "Mat2.h"

using namespace std;

void main() {
			   
	Mat4 mat =
		Mat4(
			1,1,1,1,
			1,1,1,1,
			1,1,1,1,
			1,1,1,1
		);

	mat.Translate(Vec3(2,3,1));
	mat.Print();

	getchar();
}
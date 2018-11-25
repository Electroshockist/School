#include "Mat4.h"
#include "Mat3.h"
#include "Mat2.h"

using namespace std;

void main() {
			   
	Mat4 mat =
		Mat4(
			1,0,2,1,
			0,4,1,0,
			1,2,1,0,
			0,0,2,3
		);
	mat.Inverse();
	mat.Print();

	getchar();
}
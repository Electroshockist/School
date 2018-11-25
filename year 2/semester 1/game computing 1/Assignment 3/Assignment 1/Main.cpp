#include "Mat4.h"
#include "Mat3.h"
#include "Mat2.h"

using namespace std;
//		|
//_	4, 1, 0,
//	2, 1, 0,
//	0, 2, 3

void main() {

	/*Mat3 mat =
		Mat3(
			4, 1, 0,
			2, 1, 0,
			0, 2, 3
		);*/
			   
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
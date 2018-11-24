#include "Mat4.h"

using namespace std;

void main() {
	Vec3 translation(1, 2, 3);

	Mat4 mat =
		Mat4(
			1,0,2,1,
			0,4,1,0,
			1,2,1,0,
			0,0,2,3
		);
	mat.Inverse();
	mat.Print();

	cout << endl << mat.Det() << endl;

	getchar();
}
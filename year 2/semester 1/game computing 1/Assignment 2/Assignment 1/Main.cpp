#include "Mat4.h"

using namespace std;

void main() {
	Mat4 mat = Mat4();
	cout << "Original Matrix:" << std::endl;

	mat.Print();

	mat.RotateX(90);

	mat.Print();

	getchar();
}
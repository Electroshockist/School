#include "Vec3.h";
using namespace std;
void main() {
	Vec3 v(3, 4, 5);
	Vec3 v1(3, 2, 1);

	Vec3 vadd = v.Add(v1);
	Vec3 vsub = v - v1;
	Vec3 vmulti = v * v1;
	Vec3 vdiv = v / v1;
	Vec3 vscale = v;
	float scalar = 3;
	vscale.ScalarMultiplication(scalar);
	float vmag = v.Magnitude();
	Vec3 vcross = v;
	vcross.Cross(v1);

	Vec3 vnorm = v;
	vnorm.Normalize();

	//displays 3d vector operators
	cout << "3D Vector:\nUsing vectors:\nV: ";
	v.print();
	cout << "V1: ";
	v1.print();
	cout << "Added vectors: ";
	v.Add(v1);
	vadd.print();
	cout << "Subtracted vectors: ";
	v.Subtract(v1);
	vsub.print();
	cout << "Multiplied vectors: ";
	vmulti.print();
	cout << "Divided vectors: ";
	vdiv.print();
	cout << "Using v only\nScaled vector";
	vscale.print();
	cout << "Vector magnitude\n" << vmag;
	cout << "Cross product of both vectors:";
	vcross.print();

	getchar();
}
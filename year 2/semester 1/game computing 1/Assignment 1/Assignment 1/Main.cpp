#include "Vec3.h";
#include "Vec4.h";
#include "Ray.h"

using namespace std;

void main() {
	//vec3 stuff
	Vec3 v(3, 4, 5);
	Vec3 v1(3, 2, 1);
	float scalar = 3;

	Vec3 vadd = v;
	Vec3 vsub = v;
	Vec3 vscale = v;
	vscale.ScalarMultiplication(scalar);
	float vmag = v.Magnitude();
	Vec3 vnorm = v;
	vnorm.Normalize();
	Vec3 vcross = v;
	vcross.Cross(v1);

	//vec4 stuff
	Vec4 v4(5, 2, 9, 1);
	Vec4 v4b(4, 8, 3, 3);

	float v4mag = v4.Magnitude();
	Vec4 v4norm = v4;
	v4norm.Normalize();
	float v4dot = v4.Dot(v4b);

	//ray stuff
	Ray ray(v,v1);
	float t = 1.5;	

	//displays vector3 operators
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
	cout << "\nUsing v only\nScalar: " << scalar;
	cout << "\nScaled vector: ";
	vscale.print();
	cout << "Vector magnitude: " << vmag << "\nNormalized vector: ";
	vnorm.print();
	cout << "Cross product of both vectors: ";
	vcross.print();

	//displays vector4 operators
	cout << "\n\n4D Vector:\nUsing vector:\nV4: ";
	v4.print();
	cout << "V4b: ";
	v4b.print();
	cout << "Vector magnitude: " << v4mag << "\nNormalized vector: ";
	v4norm.print();
	cout << "Dotted vectors: " << v4dot ;

	//displays ray operators
	cout << "\n\nRays:\nUsing:\n Ray start: ";
	ray.start.print();
	cout << "Ray direction: ";
	ray.dir.print();
	cout << "Ray position at t = " << t << ": ";
	ray.currentPosition(t).print();

	getchar();
}
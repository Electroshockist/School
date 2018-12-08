#include "Mat4.h"
#include "Quaternion.h"

using namespace std;

void main() {
	Quaternion q = Quaternion(Vec3(0, 0, 1), 90);

	Vec3 bip = Vec3(1, 0, 0);

	Vec3 tot = q.Rotate(bip);

	tot.print();
	
	getchar();
}
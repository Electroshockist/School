#include "Plane.h"

// Set the member variables of the plane
Plane::Plane(float x_, float y_, float z_, float d_) {
	plane = Vec4(x_, y_, z_, d_);

}
// Define the plane using three points that are on the plane
Plane::Plane(const Vec3& v0, const Vec3& v1, const Vec3& v2) {
	Vec3 tempV1 = v1 - v0;
	Vec3 tempV2 = v2 - v1;

	tempV1.Cross(tempV2);
	tempV1.Normalize();

	float d = tempV1.Dot(tempV2);

	*this = Plane(tempV1.x, tempV1.y, tempV1.z, d);
}
// Find the intersection point of a ray passing through this plane
Vec3 Plane::intersectionPoint(Ray ray) {
	float t;
	Vec3 vNorm(plane.x, plane.y, plane.z);
	Vec4 ray4(ray.start.x, ray.start.y, ray.start.z, 1.0f);

	if (vNorm.Dot(ray.dir) != 0) {
		t = -(plane.w + vNorm.Dot(ray.start)) / vNorm.Dot(ray.dir);
		return Vec3(ray.currentPosition(t));
	}
	else {
		if (ray4.Dot(plane) == 0) std::cout << "Line is within plane.";
		else std::cout << "Line is does not intersect plane.";
		return Vec3();
	} 

}

Plane::~Plane()
{
}

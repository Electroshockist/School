#include "Plane.h"

// Set the member variables of the plane
Plane::Plane(float x_, float y_, float z_, float d_) {
	plane = Vec4(x_, y_, z_, d_);

}
// Define the plane using three points that are on the plane
Plane::Plane(const Vec3& v0, const Vec3& v1, const Vec3& v2) {


}
// Find the intersection point of a ray passing through this plane
Vec3 Plane::intersectionPoint(Ray ray) {
	return Vec3();
}



Plane::~Plane()
{
}

#pragma once
#include "Vec3.h"
#include "Vec4.h"
#include "Ray.h"

class Plane
{
public:
	// represent plane using x, y, z, and d as the 4th component
	Vec4 plane;

	// Set the member variables of the plane
	Plane(float x_, float y_, float z_, float d_);

	// Define the plane using three points that are on the plane
	Plane(const Vec3& v0, const Vec3& v1, const Vec3& v2);

	// Find the intersection point of a ray passing through this plane
	Vec3 intersectionPoint(Ray ray);

	~Plane();
};


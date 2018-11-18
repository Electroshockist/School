#pragma once
#include "Vec3.h"
class Ray {
public:
	// Starting position of ray
	Vec3 start;
	// Direction of ray
	Vec3 dir;
	Ray();
	// Set the member variables of the ray
	Ray(Vec3 start_, Vec3 dir_);
	// Where are we along the Ray? 
	// Calculate position = start + dir * t
	Vec3 currentPosition(float t);

	~Ray();
};


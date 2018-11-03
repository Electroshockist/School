#include "Ray.h"

Ray::Ray() {
	start = Vec3();
	dir = Vec3();
}

// Set the member variables of the ray
Ray::Ray(Vec3 start_, Vec3 dir_) {
	start = start_;
	dir = dir_;
}

Vec3 Ray :: currentPosition(float t) {
	return (start + dir * t);
}

Ray::~Ray() {
}

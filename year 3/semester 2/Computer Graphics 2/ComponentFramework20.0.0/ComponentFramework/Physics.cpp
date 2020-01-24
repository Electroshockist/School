#include "Physics.h"
#include <iostream>


void Physics::SimpleNewtonMotion(Object &object1, const float deltaTime) {
}

bool Physics::PlaneSphereCollision(const Object &object1, const Plane &p) {
	return false;
}

void Physics::PlaneSphereCollisionResponse(Object &object1, const Plane &p) {
}

bool Physics::SphereSphereCollision(const Object &object1, const Object &object2) {
	return false;
}

void Physics::SphereSphereCollisionResponse(Object &object1, Object &object2) {
}

#ifndef PHYSICSOBJECT_H
#define PHYSICSOBJECT_H
#include "Vector.h"
#include "Sphere.h"

using namespace MATH;

class PhysicsObject {
	friend class Physics;
public:
	PhysicsObject();
	virtual ~PhysicsObject();
	void Update(const float deltaTime);

protected:
	Vec3 pos, vel, accel, centerOfMass;
	float mass;
	Sphere boundingSphere;
};
#endif


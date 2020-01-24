#ifndef PHYSICS_H
#define PHYSICS_H
#include "Object.h"
#include "Plane.h"
class Physics {
public:
	
	static void SimpleNewtonMotion(Object &model, const float deltaTime);
	static bool PlaneSphereCollision(const Object &model, const Plane &p);
	static void PlaneSphereCollisionResponse(Object &model, const Plane &p);
	static bool SphereSphereCollision(const Object &model1, const Object &model2);
	static void SphereSphereCollisionResponse(Object &model1, Object &model2);
};

#endif


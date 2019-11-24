#ifndef COLLISIONDETECTION_H
#define COLLISIONDETECTION_H

#include "../Core/Camera/Camera.h"

class Ray;
class BoundingBox;

class CollisionDetection {
public:
	CollisionDetection(const CollisionDetection&) = delete;
	CollisionDetection(CollisionDetection&&) = delete;
	CollisionDetection& operator=(const CollisionDetection&) = delete;
	CollisionDetection& operator=(CollisionDetection&&) = delete;

	CollisionDetection() = delete;
	~CollisionDetection();

	static Ray screenPosToWorldRay(glm::vec2 mouseCoords_, glm::vec2 screenSize_, Camera* camera_);
	static bool rayOBBIntersection(Ray* ray_, BoundingBox* box_);
};

#endif
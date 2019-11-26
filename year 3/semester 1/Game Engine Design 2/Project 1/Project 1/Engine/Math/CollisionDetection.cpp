#include "CollisionDetection.h"
#include "Ray.h"
#include "../Core/Engine.h"

CollisionDetection::~CollisionDetection() {}

Ray CollisionDetection::screenPosToWorldRay(glm::vec2 mouseCoords_, glm::vec2 screenSize_, Camera* camera_) {
	glm::vec4 rayStart_NDC((mouseCoords_.x / screenSize_.x - 0.5f) * 2.0f, (mouseCoords_.y / screenSize_.y - 0.5f) * 2.0f,
						   -1.0f, 1.0f);
	glm::vec4 rayEnd_NDC((mouseCoords_.x / screenSize_.x - 0.5f) * 2.0f, (mouseCoords_.y / screenSize_.y - 0.5f) * 2.0f,
						 0.0f, 1.0f);

	glm::mat4 inverse = glm::inverse(camera_->getPerspective() * camera_->getView());

	glm::vec4 rayStart_World = inverse * rayStart_NDC;
	rayStart_World /= rayStart_World.w;

	glm::vec4 rayEnd_World = inverse * rayEnd_NDC;
	rayEnd_World /= rayEnd_World.w;

	glm::vec3 rayDir_World(rayEnd_World - rayStart_World);
	rayDir_World = glm::normalize(rayDir_World);

	return Ray(glm::vec3(rayStart_World), rayDir_World);
}

/*http://www.opengl-tutorial.org/miscellaneous/clicking-on-objects/picking-with-custom-ray-obb-function/*/
bool CollisionDetection::rayOBBIntersection(Ray* ray_, BoundingBox* box_) {
	glm::mat4 modelMatrix = box_->transform;

	glm::vec3 rayOrigin = ray_->origin;
	glm::vec3 rayDir = ray_->direction;

	glm::vec3 aabbMin = box_->min;
	glm::vec3 aabbMax = box_->max;

	float tMax = Engine::getInstance()->getCamera()->getClippingPlanes().y;
	float tMin = Engine::getInstance()->getCamera()->getClippingPlanes().x;

	glm::vec3 OBBposition_World(modelMatrix[3].x, modelMatrix[3].y, modelMatrix[3].z);

	glm::vec3 delta = OBBposition_World - rayOrigin;

	//X Axis
	glm::vec3 xAxis(modelMatrix[0].x, modelMatrix[0].y, modelMatrix[0].z);
	float e = glm::dot(xAxis, delta);
	float f = glm::dot(rayDir, xAxis);

	if(fabs(f) > 0.001f) {
		float t1 = (e + aabbMin.x) / f;
		float t2 = (e + aabbMax.x) / f;

		if(t1 > t2) {
			float tmp = t1;
			t1 = t2;
			t2 = tmp;
		}

		if(t2 < tMax) {
			tMax = t2;
		}

		if(t1 > tMin) {
			tMin = t1;
		}

		if(tMax < tMin) {
			return false;
		}
	}
	else {
		if(-e + aabbMin.x > 0.0f || -e + aabbMax.x < 0.0f) {
			return false;
		}
	}


	//HOMEWORK
	//Y Axis
	glm::vec3 yAxis(modelMatrix[0].x, modelMatrix[0].y, modelMatrix[0].z);
	e = glm::dot(yAxis, delta);
	f = glm::dot(rayDir, yAxis);

	if(fabs(f) > 0.001f) {
		float t1 = (e + aabbMin.y) / f;
		float t2 = (e + aabbMax.y) / f;

		if(t1 > t2) {
			float tmp = t1;
			t1 = t2;
			t2 = tmp;
		}

		if(t2 < tMax) {
			tMax = t2;
		}

		if(t1 > tMin) {
			tMin = t1;
		}

		if(tMax < tMin) {
			return false;
		}
	}
	else {
		if(-e + aabbMin.y > 0.0f || -e + aabbMax.y < 0.0f) {
			return false;
		}
	}

	//Z Axis
	glm::vec3 zAxis(modelMatrix[0].x, modelMatrix[0].y, modelMatrix[0].z);
	e = glm::dot(zAxis, delta);
	f = glm::dot(rayDir, zAxis);

	if(fabs(f) > 0.001f) {
		float t1 = (e + aabbMin.z) / f;
		float t2 = (e + aabbMax.z) / f;

		if(t1 > t2) {
			float tmp = t1;
			t1 = t2;
			t2 = tmp;
		}

		if(t2 < tMax) {
			tMax = t2;
		}

		if(t1 > tMin) {
			tMin = t1;
		}

		if(tMax < tMin) {
			return false;
		}
	}
	else {
		if(-e + aabbMin.z > 0.0f || -e + aabbMax.z < 0.0f) {
			return false;
		}
	}

	ray_->intersectionDistance = tMin;
	return true;
}
#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H
#include <glm\glm.hpp>
#include <glm\gtx\string_cast.hpp>

struct BoundingBox {
	glm::vec3 min, max;
	glm::mat4 transform;

	inline BoundingBox() {
		min = max = glm::vec3();
		transform = glm::mat4();
	}

	inline BoundingBox(glm::vec3 min, glm::vec3 max, glm::mat4 transform) {
		this->min = min;
		this->max = max;
		this->transform = transform;
	}

	inline bool intersects(BoundingBox* box) {
		glm::vec3
			minCorner = getTransformPoint(min, transform),
			maxCorner = getTransformPoint(max, transform);

		glm::vec3
			otherMinCorner = getTransformPoint(box->min, box->transform),
			otherMaxCorner = getTransformPoint(box->max, box->transform);

		return 
			(minCorner.x <= otherMaxCorner.x && maxCorner.x >= otherMinCorner.x) &&
			(minCorner.y <= otherMaxCorner.y && maxCorner.y >= otherMinCorner.y) &&
			(minCorner.z <= otherMaxCorner.z && maxCorner.z >= otherMinCorner.z);
	}

	inline glm::vec3 getTransformPoint(glm::vec3 point, glm::mat4 transformationMatrix) {
		return glm::vec3(transformationMatrix[3].x, transformationMatrix[3].y, transformationMatrix[3].z) + point;
	}

};

#endif // !BOUNDINGBOX_H

#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H
#include <glm\glm.hpp>

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
};

#endif // !BOUNDINGBOX_H


#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Model.h"

struct GameObject {
	GameObject(Model* model);
	GameObject(Model* model, glm::vec3 position);
	~GameObject();
	void Render(Camera* camera);
	void OnDestroy();

	glm::vec3 getPosition() const;
	float getAngle() const;
	glm::vec3 getRotation() const;
	glm::vec3 getScale() const;

	void setPosition(glm::vec3 position_);
	void setAngle(float angle_);
	void setRotation(glm::vec3 rotation_);
	void setScale(glm::vec3 scale_);

private:
	Model* model;
	glm::vec3 position, rotation, scale;
	float angle;
	int modelInstance;
};
#endif // !GAMEOBJECT_H




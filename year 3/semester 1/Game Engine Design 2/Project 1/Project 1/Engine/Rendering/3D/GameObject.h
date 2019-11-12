
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Model.h"

struct GameObject {
	GameObject(Model* model);
	GameObject(Model* model, glm::vec3 position);
	~GameObject();
	void Update(const float deltaTime);
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

	BoundingBox getBoundingBox();

	std::string getTag() const;
	void setTag(std::string tag);

private:
	Model* model;
	glm::vec3 position, rotation, scale;
	float angle;
	int modelInstance;
	BoundingBox b;
	std::string tag;
};
#endif // !GAMEOBJECT_H




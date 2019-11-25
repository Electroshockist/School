
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

	void setPosition(glm::vec3 position);
	void setAngle(float angle);
	void setRotation(glm::vec3 rotation);
	void setScale(glm::vec3 scale);

	BoundingBox getBoundingBox();

	std::string getTag() const;
	void setTag(std::string tag);
	void setHit(bool hit, int buttonType);
	bool getHit() const;

	void Update(float deltaTime);

private:
	Model* model;
	glm::vec3 position, rotation, scale;
	float angle;
	int modelInstance;

	BoundingBox boundingBox;

	std::string tag;

	bool hit;
};
#endif // !GAMEOBJECT_H




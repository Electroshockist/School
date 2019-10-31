#include "GameObject.h"

GameObject::GameObject(Model * model) {
	GameObject(model, glm::vec3());
}

GameObject::GameObject(Model * model, glm::vec3 position) {
	this->model = model;
	this->position = position;
	angle = 0.0f;
	rotation = glm::vec3(0.0f, 1.0f, 0.0f);
	scale = glm::vec3(1.0f);
	if(model) {
		modelInstance = model->createInstance(position, angle, rotation, scale);
	}
}

GameObject::~GameObject() {
	OnDestroy();
}

void GameObject::Render(Camera* camera) {
	if(model) {
		model->render(camera);
	}
}

void GameObject::OnDestroy() {
	if(model) {
		delete model;
	}
	model = nullptr;
}

glm::vec3 GameObject::getPosition() const {
	return position;
}

float GameObject::getAngle() const {
	return angle;
}

glm::vec3 GameObject::getRotation() const {
	return rotation;
}

glm::vec3 GameObject::getScale() const {
	return scale;
}

void GameObject::setPosition(glm::vec3 position) {
	this->position = position;
	if(model) {
		model->updateInstance(modelInstance, position, angle, rotation, scale);
	}
}

void GameObject::setAngle(float angle) {
	this->angle = angle;
	if(model) {
		model->updateInstance(modelInstance, position, angle, rotation, scale);
	}
}

void GameObject::setRotation(glm::vec3 rotation) {
	this->rotation = rotation;
	if(model) {
		model->updateInstance(modelInstance, position, angle, rotation, scale);
	}
}

void GameObject::setScale(glm::vec3 scale) {
	this->scale = scale;
	if(model) {
		model->updateInstance(modelInstance, position, angle, rotation, scale);
	}
}

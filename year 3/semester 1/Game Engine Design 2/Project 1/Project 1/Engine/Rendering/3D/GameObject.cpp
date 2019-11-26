#include "GameObject.h"
#include <iostream>

GameObject::GameObject(Model * model) : GameObject(model, glm::vec3()) {}

GameObject::GameObject(Model * model, glm::vec3 position) {
	this->model = model;
	this->position = position;
	angle = 0.0f;
	rotation = glm::vec3(0.0f, 1.0f, 0.0f);
	scale = glm::vec3(1.0f);
	if(model) {
		modelInstance = model->createInstance(position, angle, rotation, scale);
		boundingBox = model->getBoundingBox();
		boundingBox.transform = this->model->getTransform(modelInstance);
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
		boundingBox.transform = this->model->getTransform(modelInstance);
	}
}

void GameObject::setAngle(float angle) {
	this->angle = angle;

	if(model) {
		model->updateInstance(modelInstance, position, angle, rotation, scale);
	}

	boundingBox.transform = this->model->getTransform(modelInstance);
}

void GameObject::setRotation(glm::vec3 rotation) {
	this->rotation = rotation;
	if(model) {
		model->updateInstance(modelInstance, position, angle, rotation, scale);
	}

	boundingBox.transform = this->model->getTransform(modelInstance);
}

void GameObject::setScale(glm::vec3 scale) {
	this->scale = scale;
	if(model) {
		model->updateInstance(modelInstance, position, angle, rotation, scale);

		boundingBox.transform = this->model->getTransform(modelInstance);
		boundingBox.min *= scale.x > 1.0f ? scale : (scale / 2.0f);
		boundingBox.max *= scale.x > 1.0f ? scale : (scale / 2.0f);
	}
}

BoundingBox GameObject::getBoundingBox() {
	return boundingBox;
}

std::string GameObject::getTag() const {
	return tag;
}

void GameObject::setTag(std::string tag) {
	this->tag = tag;
}

void GameObject::setHit(bool hit_, int buttonType) {
	hit = hit_;
	if(hit) {
		std::cout << "Hit: " << tag << std::endl;
	}
}

bool GameObject::getHit() const {
	return hit;
}

void GameObject::Update(float deltaTime) {}

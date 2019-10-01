#include "Camera.h"
#include "../Core/Engine.h"


void Camera::updateCameraVectors() {
	forwardVector.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	forwardVector.y = sin(glm::radians(pitch));
	forwardVector.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

	forwardVector = glm::normalize(forwardVector);

	rightVector = glm::normalize(glm::cross(forwardVector, worldUp));
	upVector = glm::normalize(glm::cross(rightVector, forwardVector));
}

Camera::Camera() : position(glm::vec3()), pitch(0.0f) {
	fieldOfView = 45.0f;
	forwardVector = glm::vec3(0.0f, 0.0f, -1.0f);
	upVector = glm::vec3(0.0f, 1.0f, 0.0f);
	worldUp = upVector;
	nearPlane = 2.0f;
	farPlane = 50.0f;
	yaw = -90.0f;

	getPerspective();
	getOrthographic();

	updateCameraVectors();
}


Camera::~Camera() {}

void Camera::setPosition(glm::vec3 position) {
	this->position = position;
}

void Camera::setRotation(float yaw, float pitch) {
	this->yaw = yaw;
	this->pitch = pitch;
	updateCameraVectors();
}

glm::mat4 Camera::getView() const {
	return glm::lookAt(position, position + forwardVector, upVector);
}

const glm::mat4 Camera::getPerspective() {
	perspective = glm::perspective(fieldOfView, Engine::getInstance()->getScreenSize().x / Engine::getInstance()->getScreenSize().y, nearPlane, farPlane);
	return perspective;
}

const glm::mat4 Camera::getOrthographic() {
	orthographic = glm::ortho(0.0f, Engine::getInstance()->getScreenSize().x, 0.0f, Engine::getInstance()->getScreenSize().y, -1.0f, 1.0f);
	return perspective;
}

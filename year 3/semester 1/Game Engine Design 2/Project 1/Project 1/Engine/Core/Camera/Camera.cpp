#include "Camera.h"
#include "../Engine.h"


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

void Camera::processMouseMovement(float xOffset, float yOffset) {
	xOffset *= 0.05f;
	yOffset *= 0.05f;

	yaw += xOffset;
	pitch += yOffset;

	if(pitch > 89.0f) {
		pitch = 89.0f;
	}

	if(pitch < -89.0f) {
		pitch = -89.0f;
	}

	if(yaw > 360) {
		yaw -= 360;
	}
	if(yaw < 0) {
		yaw += 360;
	}
	updateCameraVectors();
}

void Camera::processMouseZoom(int y) {
	if(y < 0 || y>0) {
		position += static_cast<float>(y) * (forwardVector * 2.0f);
	}
	updateCameraVectors();
}

void Camera::addLightSource(LightSource * light) {
	lightSources.push_back(light);
}

std::vector<LightSource*> Camera::getLightSources() {
	return lightSources;
}

glm::vec3 Camera::getPosition() const {
	return position;
}

glm::vec2 Camera::getClippingPlanes() const {
	return glm::vec2(nearPlane, farPlane);
}

void Camera::Frustum::transform(glm::vec3 position, float angle, glm::vec3 rotation, glm::vec3 scale) {
	glm::mat4 matrix;
	matrix = glm::translate(matrix, position);
	matrix = glm::rotate(matrix, angle, rotation);
	matrix = glm::scale(matrix, scale);

	transformMatrix = matrix;
}

glm::vec3 Camera::Frustum::getPosition() const {
	return position;
}

float Camera::Frustum::getAngle() const {
	return angle;
}

glm::vec3 Camera::Frustum::getRotation() const {
	return rotation;
}

glm::vec3 Camera::Frustum::getScale() const {
	return scale;
}

void  Camera::Frustum::setPosition(glm::vec3 position) {
	this->position = position;
	transform(position, angle, rotation, scale);
}

void Camera::Frustum::setAngle(float angle) {
	this->angle = angle;
	transform(position, angle, rotation, scale);
}

void Camera::Frustum::setRotation(glm::vec3 rotation) {
	this->rotation = rotation;
	transform(position, angle, rotation, scale);
}

void Camera::Frustum::setScale(glm::vec3 scale) {
	this->scale = scale;
	transform(position, angle, rotation, scale);
}

std::vector<glm::vec3> Camera::Frustum::getPoints() {
	std::vector<glm::vec3> p;
	for(size_t i = 0; i < 8; i++) {
		p.push_back(points[i]);
	}
	return p;
}

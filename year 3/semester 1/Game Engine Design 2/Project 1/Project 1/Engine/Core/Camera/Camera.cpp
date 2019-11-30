#include "Camera.h"
#include "../Engine.h"
#include "../../Rendering/3D/Model.h"

void Camera::updateCameraVectors() {
	forwardVector.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	forwardVector.y = sin(glm::radians(pitch));
	forwardVector.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

	forwardVector = glm::normalize(forwardVector);

	rightVector = glm::normalize(glm::cross(forwardVector, worldUp));
	upVector = glm::normalize(glm::cross(rightVector, forwardVector));

	frustum.updateMatrix(getPerspective() * getView());
}

void Camera::onCameraUpdate() {}

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
	return orthographic;
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

Frustum Camera::getFrustum() const {
	return frustum;
}

void Camera::addLightSources(LightSource * light) {
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

Frustum::Frustum(glm::mat4 matrix) {
	updateMatrix(matrix);
}

Frustum::~Frustum() {}

bool Frustum::isModelInView(Model * model) {
	int sum = 0;
	for(auto plane : planes) {
		sum += (int)classifyPoint(plane, model->getPosition());
		std::cout << classifyPoint(plane, model->getPosition())  << std::endl;
	}
	std::cout << std::endl;
	

	return sum == 6;
}

void Frustum::updateMatrix(glm::mat4 matrix) {
	// Left clipping plane
	planes[Left].x = matrix[3].x + matrix[0].x;
	planes[Left].y = matrix[3].y + matrix[0].y;
	planes[Left].z = matrix[3].z + matrix[0].z;
	planes[Left].w = matrix[3].w + matrix[0].w;
	// Right clipping plane
	planes[Right].x = matrix[3].x - matrix[0].x;
	planes[Right].y = matrix[3].y - matrix[0].y;
	planes[Right].z = matrix[3].z - matrix[0].z;
	planes[Right].w = matrix[3].w - matrix[0].w;
	// Top clipping plane
	planes[Top].x = matrix[3].x - matrix[1].x;
	planes[Top].y = matrix[3].y - matrix[1].y;
	planes[Top].z = matrix[3].z - matrix[1].z;
	planes[Top].w = matrix[3].w - matrix[1].w;
	// Bottom clipping plane
	planes[Bottom].x = matrix[3].x + matrix[1].x;
	planes[Bottom].y = matrix[3].y + matrix[1].y;
	planes[Bottom].z = matrix[3].z + matrix[1].z;
	planes[Bottom].w = matrix[3].w + matrix[1].w;
	// Near clipping plane
	planes[Near].x = matrix[3].x + matrix[2].x;
	planes[Near].y = matrix[3].y + matrix[2].y;
	planes[Near].z = matrix[3].z + matrix[2].z;
	planes[Near].w = matrix[3].w + matrix[2].w;
	// Far clipping plane
	planes[Far].x = matrix[3].x - matrix[2].x;
	planes[Far].y = matrix[3].y - matrix[2].y;
	planes[Far].z = matrix[3].z - matrix[2].z;
	planes[Far].w = matrix[3].w - matrix[2].w;

	//normalize plane
	planes[Left] = glm::normalize(planes[Left]);
	planes[Right] = glm::normalize(planes[Right]);
	planes[Top] = glm::normalize(planes[Top]);
	planes[Bottom] = glm::normalize(planes[Bottom]);
	planes[Near] = glm::normalize(planes[Near]);
	planes[Far] = glm::normalize(planes[Far]);
}

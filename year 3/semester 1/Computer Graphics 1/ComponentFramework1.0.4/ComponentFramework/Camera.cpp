#include "Camera.h"
#include "MMath.h"

Camera::Camera() {
	createProjection(45.0f, (16.0f / 9.0f), 0.5f, 100.0f);
	createView(Vec3(0.0, 0.0, 10.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 1.0f, 0.0f));
}

Camera::~Camera() {}

void Camera::createProjection(float fovy, float aspect, float near, float far) {
	fovY = fovy;
	aspectRatio = aspect;
	nearClip = near;
	farClip = far;
	projection = MMath::perspective(fovy, aspect, near, far);
}

void Camera::createView(Vec3 pos, Vec3 at, Vec3 up) {
	this->pos = pos;
	this->at = at;
	this->up = up;
	view = MMath::lookAt(pos, at, up);
}

void Camera::setFovY(float fovY) {
	createProjection(fovY, aspectRatio, nearClip, farClip);
}

void Camera::setAspectRatio(float aspectRatio) {
	createProjection(fovY, aspectRatio, nearClip, farClip);
}

void Camera::setNearClip(float nearClip) {
	createProjection(fovY, aspectRatio, nearClip, farClip);
}

void Camera::setFarClip(float farClip) {
	createProjection(fovY, aspectRatio, nearClip, farClip);
}

void Camera::setPos(Vec3 pos) {
	createView(pos, at, up);
}

void Camera::setAt(Vec3 at) {
	createView(pos, at, up);
}

void Camera::setUp(Vec3 up) {
	createView(pos, at, up);
}

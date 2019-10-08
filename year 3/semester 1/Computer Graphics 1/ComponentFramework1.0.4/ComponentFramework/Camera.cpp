#include "Camera.h"
#include "MMath.h"
#include "SkyBox.h"
#include "Shader.h"
#include <SDL.h>

Camera::Camera() : skybox(new SkyBox()) {
	createProjection(45.0f, (16.0f / 9.0f), 0.5f, 100.0f);
	createView(Vec3(0.0, 0.0, 10.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 1.0f, 0.0f));
	skybox->onCreate();
}

Camera::~Camera() {
	if (skybox) delete skybox;
}

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
	view = MMath::rotate(5.0, Vec3(0.0, 1.0, 0.0)) * MMath::translate(0.0, 0.0, -10.0);
}

void Camera::render() {
	if (skybox != nullptr) {
		skybox->Render(&projection, &view);
	}
}

void Camera::handleEvents(const SDL_Event & sdlEvent) {}

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

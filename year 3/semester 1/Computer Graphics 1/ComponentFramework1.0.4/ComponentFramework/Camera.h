#ifndef CAMERA_H
#define CAMERA_H
#include "Vector.h"
#include "Matrix.h"

using namespace MATH;

union SDL_Event;
class Camera {
private:
	class SkyBox* skybox;
	class Trackball* trackball;
	Matrix4 projection;
	Matrix4 view;
	float fovY, aspectRatio, nearClip, farClip;
	Vec3 pos, at, up;

public:
	inline Matrix4 getProjectionMatrix() const { return projection; }
	inline Matrix4 getViewMatrix() const { return view; }

	void createProjection(float fovy, float aspectRatio, float near, float far);
	void createView(Vec3 pos, Vec3 at, Vec3 up);

	void render();
	void handleEvents(const SDL_Event &sdlEvent);

	void setFovY(float fovY);
	void setAspectRatio(float aspectRatio);
	void setNearClip(float nearClip);
	void setFarClip(float farClip);
	void setPos(Vec3 pos);
	void setAt(Vec3 at);
	void setUp(Vec3 up);


	Vec3 getPos();
	Camera();
	~Camera();
};

#endif




#ifndef CAMERA_H
#define CAMERA_H
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

class LightSource;
class Camera {
	glm::vec3 position;
	glm::mat4 perspective, orthographic;
	float fieldOfView;
	float yaw, pitch;
	float nearPlane, farPlane;
	glm::vec3 forwardVector, upVector, rightVector, worldUp;
	void updateCameraVectors();
	std::vector<LightSource*> lightSources;

public:
	Camera();
	~Camera();

	void setPosition(glm::vec3 position);
	void setRotation(float yaw, float pitch);
	glm::mat4 getView() const;
	const glm::mat4 getPerspective();
	const glm::mat4 getOrthographic();

	void processMouseMovement(float xOffset, float yOffset);
	void processMouseZoom(int y);

	void addLightSources(LightSource* light);
	std::vector<LightSource*> getLightSource();

	glm::vec2 getClippingPlanes() const;
};
#endif // !CAMERA_H


#ifndef CAMERA_H
#define CAMERA_H
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include "../../FX/LightSource.h"



class Camera {
	class Frustum {	
		glm::mat4 transformMatrix;

		glm::vec3 points[8];

		glm::vec3 position, rotation, scale;
		float angle;

		void transform(glm::vec3 position, float angle, glm::vec3 rotation, glm::vec3 scale) ;

	public:		
		glm::vec3 getPosition() const;
		float getAngle() const;
		glm::vec3 getRotation() const;
		glm::vec3 getScale() const;

		void setPosition(glm::vec3 position);
		void setAngle(float angle);
		void setRotation(glm::vec3 rotation);
		void setScale(glm::vec3 scale);

		std::vector<glm::vec3> getPoints();
	};

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
	std::vector<LightSource*> getLightSources();

	glm::vec3 getPosition() const;

	glm::vec2 getClippingPlanes() const;
};
#endif // !CAMERA_H


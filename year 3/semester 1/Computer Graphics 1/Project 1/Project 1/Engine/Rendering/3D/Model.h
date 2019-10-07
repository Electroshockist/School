#ifndef MODEL_H
#define MODEL_H

#include "Mesh.h"

class Model {
public:
	Model(GLuint shaderProgram);
	Model(GLuint shaderProgram, glm::vec3 position, float angle, glm::vec3 rotation, glm::vec3 scale);
	~Model();
	void AddMesh(Mesh* mesh_);
	void Render(Camera* camera);
	void OnDestroy();

	inline glm::vec3 GetPosition() const { return position; };
	inline float GetAngle() const { return angle; };
	inline glm::vec3 GetRotation() const { return rotation; };
	inline glm::vec3 GetScale() const { return scale; };
	glm::mat4 getTransform() const;

	void setPosition(glm::vec3 position);
	void setAngle(float angle);
	void setRotation(glm::vec3 rotation);
	void setScale(glm::vec3 scale);

private:
	GLuint shaderProgram;
	std::vector<Mesh*> subMeshes;

	glm::vec3 position, rotation, scale;
	float angle;
	glm::mat4 GetTransform() const;
};
#endif // !MODEL_H



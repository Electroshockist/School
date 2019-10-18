#ifndef MODEL_H
#define MODEL_H

#include "Mesh.h"
#include <glm/gtc/matrix_transform.hpp>

class Model {
	std::vector<Mesh*> subMeshes;
	GLuint shaderProgram;
	float angle;
	glm::mat4 getTransform(glm::vec3 position, float angle, glm::vec3 rotation, glm::vec3 scale) const;
	void LoadModel();
	std::vector<glm::mat4> modelInstance;

public:
	Model(const std::string& objPath, const std::string& mathPath, GLuint shaderProgram);
	~Model();
	void addMesh(Mesh* mesh);
	void render(Camera* camera);
	void onDestroy();
	int createInstance(glm::vec3 position, float angle, glm::vec3 rotation, glm::vec3 scale);
	void updateInstance(int index, glm::vec3 position, float angle, glm::vec3 rotation, glm::vec3 scale);
	glm::mat4 getTransform(int index) const;
};
#endif // !MODEL_H



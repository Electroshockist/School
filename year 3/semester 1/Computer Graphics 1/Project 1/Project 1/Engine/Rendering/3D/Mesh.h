#ifndef MESH_H
#define MESH_H

#include <glew.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../../Camera/Camera.h"

struct Vertex {
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec3 texCoords;
	glm::vec3 colour;
};

class Mesh {
	void GenerateBuffers();
	GLuint VAO, VBO;
	std::vector<Vertex> vertexList;
	GLuint shaderProgram;
	GLuint modelLoc;
	GLuint viewLoc;
	GLuint projLoc;


public:
	Mesh(std::vector<Vertex>* vertexList, GLuint shaderProgram);
	~Mesh();

	void Render(glm::mat4 transform, Camera* camera);
	void OnDestroy();

};

#endif // !MESH_H
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
	glm::vec2 texCoords;
	glm::vec3 colour;
};

struct SubMesh {
	std::vector<Vertex> vertexList;
	std::vector<int> meshIndices;
	GLuint textureID;
};

class Mesh {
	void GenerateBuffers();
	GLuint VAO, VBO;
	std::vector<Vertex> vertexList;
	GLuint shaderProgram;
	GLuint textureLoc, modelLoc, viewLoc, projLoc;
	SubMesh subMesh;


public:
	Mesh(SubMesh submesh, GLuint shaderProgram);
	~Mesh();

	void Render(Camera* camera, std::vector<glm::mat4> &instance);
	void OnDestroy();

};

#endif // !MESH_H
#ifndef MESH_H
#define MESH_H

#include <glew.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../../Graphics/MaterialHandler.h"
#include "../../Core/Camera/Camera.h"

struct Vertex {
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 texCoords;
	glm::vec3 colour;
};

struct SubMesh {
	std::vector<Vertex> vertexList;
	std::vector<int> meshIndices;
	Material material;
};

class Mesh {
	void GenerateBuffers();
	GLuint VAO, VBO;
	GLuint shaderProgram;
	GLuint modelLoc, viewLoc, projLoc;
	GLuint viewPositionLoc, lightPosLoc, lightAmbientLoc, lightDiffuseLoc, lightColourLoc;
	GLuint diffuseMapLoc, shineLoc, transparencyLoc, ambientLoc, diffuseLoc, specLoc;
	SubMesh subMesh;


public:
	Mesh(SubMesh submesh, GLuint shaderProgram);
	~Mesh();

	void Render(Camera* camera, std::vector<glm::mat4> &instance);
	void OnDestroy();

};

#endif // !MESH_H
#include "Mesh.h"

Mesh::Mesh(SubMesh submesh, GLuint shaderProgram) : VAO(0), VBO(0), shaderProgram(0) {
	this->shaderProgram = shaderProgram;
	this->subMesh = subMesh;
	GenerateBuffers();
}

Mesh::~Mesh() {
	OnDestroy();
}

void Mesh::GenerateBuffers() {
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, vertexList.size() * sizeof(Vertex), &vertexList[0], GL_STATIC_DRAW);

	//Position
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), static_cast<GLvoid*>(0));

	//Normal
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));

	//Texture
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, texCoords));

	//Colour
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, colour));

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	textureLoc = glGetUniformLocation(shaderProgram, "inTexture");
	modelLoc = glGetUniformLocation(shaderProgram, "model");
	viewLoc = glGetUniformLocation(shaderProgram, "view");
	projLoc = glGetUniformLocation(shaderProgram, "proj");
}



void Mesh::Render(Camera* camera, std::vector<glm::mat4> &instance) {
	glUniform1i(textureLoc, 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, subMesh.textureID);

	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(camera->getView()));
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(camera->getPerspective()));

	glBindVertexArray(VAO);
	for(size_t i = 0; i < instance.size(); i++) {
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(instance[i]));
		glDrawArrays(GL_TRIANGLES, 0, vertexList.size());


	}

	glBindVertexArray(0);

	glBindTexture(GL_TEXTURE_2D, 0);
}

void Mesh::OnDestroy() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	subMesh.vertexList.clear();
	subMesh.meshIndices.clear();
}



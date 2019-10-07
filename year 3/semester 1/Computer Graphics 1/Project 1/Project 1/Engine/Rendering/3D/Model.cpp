#include "Model.h"
#include <glm/gtc/matrix_transform.hpp>

Model::Model(GLuint shaderProgram) : subMeshes(std::vector<Mesh*>()), position(glm::vec3()), angle(0.0f), rotation(glm::vec3(0.0f, 1.0f, 0.0f)), scale(glm::vec3(1.0f)) {
	this->shaderProgram = shaderProgram;
}

Model::Model(GLuint shaderProgram, glm::vec3 position, float angle, glm::vec3 rotation, glm::vec3 scale) {
	Model::Model(shaderProgram);
	this->position = position;
	this->angle = angle;
	this->rotation = rotation;
	this->scale = scale;
}

Model::~Model() {
	OnDestroy();
}

void Model::AddMesh(Mesh * mesh_) {
	subMeshes.push_back(mesh_);
}

void Model::Render(Camera* camera) {
	glUseProgram(shaderProgram);
	for(auto m : subMeshes) {
		m->Render(getTransform(), camera);
	}
}

void Model::OnDestroy() {
	if(subMeshes.size() > 0) {
		for(auto m : subMeshes) {
			delete m;
			m = nullptr;
		}
		subMeshes.clear();
	}
}

glm::mat4 Model::getTransform() const {
	glm::mat4 model;
	model = glm::translate(model, position);
	model = glm::rotate(model, angle, rotation);
	model = glm::scale(model, scale);

	return model;
}

void Model::setPosition(glm::vec3 position) {
	this->position = position;
}

void Model::setAngle(float angle) { 
	this->angle = angle;
}

void Model::setRotation(glm::vec3 rotation) {
	this->rotation = rotation;
}

void Model::setScale(glm::vec3 scale) {
	this->scale = scale;
}

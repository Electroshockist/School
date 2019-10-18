#include "Model.h"

Model::Model(const std::string& objPath_, const std::string& mathPath_, GLuint shaderProgram_)
	: subMeshes(std::vector<Mesh*>()) {
	shaderProgram = shaderProgram_;
}


Model::~Model() {
	onDestroy();
}

void Model::addMesh(Mesh * mesh_) {
	subMeshes.push_back(mesh_);
}

void Model::render(Camera* camera_) {
	glUseProgram(shaderProgram);

	for(auto m : subMeshes) {
		m->Render(camera_, modelInstance);
	}
}

void Model::onDestroy() {
	if(subMeshes.size() > 0) {
		for(auto m : subMeshes) {
			delete m;
			m = nullptr;
		}
		subMeshes.clear();
	}
}

int Model::createInstance(glm::vec3 position, float angle, glm::vec3 rotation, glm::vec3 scale) {
	modelInstance.push_back(getTransform(position, angle, rotation, scale));
	return modelInstance.size() - 1;
}

void Model::updateInstance(int index, glm::vec3 position, float angle, glm::vec3 rotation, glm::vec3 scale) {
	modelInstance[index] = getTransform(position, angle, rotation, scale);

}

glm::mat4 Model::getTransform(int index) const {
	return modelInstance[index];
}

glm::mat4 Model::getTransform(glm::vec3 position, float angle, glm::vec3 rotation, glm::vec3 scale) const {
	glm::mat4 model;
	model = glm::translate(model, position);
	model = glm::rotate(model, angle, rotation);
	model = glm::scale(model, scale);

	return model;
}


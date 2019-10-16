#include "Model.h"

Model::Model(const std::string& objPath_, const std::string& mathPath_, GLuint shaderProgram_)
	: subMeshes(std::vector<Mesh*>()),
	shaderProgram(0) {
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
	modelInstance.push_back(GetTransform(position, angle, rotation, scale));
	return modelInstance.size() - 1;
}

void Model::updateInstance(int index_, glm::vec3 position, float angle, glm::vec3 rotation, glm::vec3 scale) {
	modelInstance[index_] = getTransform(position, angle, rotation, scale);

}

glm::mat4 Model::getTransform(int index) const {
	return modelInstance[index];
}

glm::mat4 Model::GetTransform(glm::vec3 position_, float angle_, glm::vec3 rotation_, glm::vec3 scale_) const {
	glm::mat4 model;
	model = glm::translate(model, position_);
	model = glm::rotate(model, angle, rotation_);
	model = glm::scale(model, scale_);


	return model;
}

void Model::LoadModel() {}


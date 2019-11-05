#include "Model.h"
#include <iostream>

Model::Model(const std::string& objPath_, const std::string& matPath_, GLuint shaderProgram_)
	: subMeshes(std::vector<Mesh*>()), shaderProgram(0), modelInstances(std::vector<glm::mat4>()) {

	shaderProgram = shaderProgram_;
	obj = new LoadObjModel();

	obj->loadModel(objPath_, matPath_);
	this->loadModel();
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
		m->Render(camera_, modelInstances);
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
	modelInstances.clear();
}

int Model::createInstance(glm::vec3 position_, float angle_, glm::vec3 rotation_, glm::vec3 scale_) {
	modelInstances.push_back(getTransform(position_, angle_, rotation_, scale_));
	return modelInstances.size() - 1;
}

void Model::updateInstance(int index_, glm::vec3 position_, float angle_, glm::vec3 rotation_, glm::vec3 scale_) {
	modelInstances[index_] = getTransform(position_, angle_, rotation_, scale_);

}

glm::mat4 Model::getTransform(int index_) const {
	return modelInstances[index_];
}

void Model::loadModel() {
	for(int i = 0; i < obj->getSubMeshes().size(); i++) {
		std::cout << obj->getSubMeshes().size() << " " << i << std::endl;
		subMeshes.push_back(new Mesh(obj->getSubMeshes()[i], shaderProgram));
	}
	delete obj;
	obj = nullptr;
}

glm::mat4 Model::getTransform(glm::vec3 position_, float angle_, glm::vec3 rotation_, glm::vec3 scale_) const {
	glm::mat4 model;
	model = glm::translate(model, position_);
	model = glm::rotate(model, angle, rotation_);
	model = glm::scale(model, scale_);

	return model;
}
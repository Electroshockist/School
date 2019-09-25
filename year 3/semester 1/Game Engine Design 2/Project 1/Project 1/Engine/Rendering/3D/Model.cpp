#include "Model.h"

Model::Model(GLuint shaderProgram) : subMeshes(std::vector<Mesh*>()) {
	this->shaderProgram = shaderProgram;
}

Model::~Model() {
	OnDestroy();
}

void Model::AddMesh(Mesh * mesh_) {
	subMeshes.push_back(mesh_);
}

void Model::Render() {
	glUseProgram(shaderProgram);
	for (auto m : subMeshes) {
		m->Render();
	}
}

void Model::OnDestroy()
{
	if (subMeshes.size() > 0) {
		for (auto m : subMeshes) {
			delete m;
			m = nullptr;
		}
		subMeshes.clear();
	}
}

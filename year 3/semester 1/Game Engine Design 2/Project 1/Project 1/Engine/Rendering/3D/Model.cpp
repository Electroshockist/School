#include "Model.h"

Model::Model() : subMeshes(std::vector<Mesh*>()) {

}

Model::~Model() {
	OnDestroy();
}

void Model::AddMesh(Mesh * mesh_) {
	subMeshes.push_back(mesh_);
}

void Model::Render() {
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

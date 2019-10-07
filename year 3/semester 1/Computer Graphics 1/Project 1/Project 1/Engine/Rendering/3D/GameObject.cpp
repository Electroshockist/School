#include "GameObject.h"

GameObject::GameObject(Model * model_) : model(nullptr) {
	model = model_;
}

GameObject::~GameObject() {
	OnDestroy();
}

void GameObject::Render(Camera* camera) {
	if (model) {
		model->Render(camera);
	}
}

void GameObject::OnDestroy()
{
	if (model) {
		delete model;
	}
	model = nullptr;
}

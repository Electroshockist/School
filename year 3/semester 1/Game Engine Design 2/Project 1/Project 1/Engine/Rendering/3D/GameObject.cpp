#include "GameObject.h"

GameObject::GameObject(Model * model_) : model(nullptr) {
	model = model_;
}

GameObject::~GameObject() {
	OnDestroy();
}

void GameObject::Render() {
	if (model) {
		model->Render();
	}
}

void GameObject::OnDestroy()
{
	if (model) {
		delete model;
	}
	model = nullptr;
}

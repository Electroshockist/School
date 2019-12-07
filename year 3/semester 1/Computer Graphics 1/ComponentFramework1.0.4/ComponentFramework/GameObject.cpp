#include "GameObject.h"
#include "ARenderable.h"
#include "ARenderable.h"
#include "Shader.h"
#include "Texture.h"
#include "MMath.h"

GameObject::GameObject(ARenderable *renderable, Shader *shader_, Texture *texture_) : renderable(nullptr), shader(nullptr), texture(nullptr) {
	this->renderable = renderable;
	shader = shader_;
	texture = texture_;
	modelMatrixID = shader->getUniformID("modelMatrix");
	normalMatrixID = shader->getUniformID("normalMatrix");
}

GameObject::~GameObject() {}

void GameObject::Update(float deltaTime_) {}

void GameObject::Render() const {
	Matrix3 normalMatrix = modelMatrix;
	glUniformMatrix4fv(modelMatrixID, 1, GL_FALSE, modelMatrix);
	glUniformMatrix3fv(normalMatrixID, 1, GL_FALSE, normalMatrix);
	if(texture) {
		glBindTexture(GL_TEXTURE_2D, texture->getTextureID());
	}

	renderable->Render();

	/// Unbind the texture
	glBindTexture(GL_TEXTURE_2D, 0);
}
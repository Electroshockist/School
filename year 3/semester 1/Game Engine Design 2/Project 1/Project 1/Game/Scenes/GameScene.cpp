#include "GameScene.h"
#include <iostream>
#include "../../Engine/Graphics/ShaderHandler.h"



GameScene::GameScene() {
	OnCreate();
}


GameScene::~GameScene() {
	onDestroy();
}

bool GameScene::OnCreate() {
	Engine::getInstance()->setCamera(new Camera());
	Engine::getInstance()->getCamera()->setPosition(glm::vec3(0.0f, 0.0f, 4.0f));

	model = new Model("Resources/Models/Apple.obj", "Resources/Materials/Apple.mtl", ShaderHandler::getInstance()->getShader("basicShader"));
	object = new GameObject(model, glm::vec3());
	if(!object || !model) {
		return false;
	}

	return true;
}

void GameScene::Update(const float deltaTime) {
	object->setAngle(object->getAngle() + 0.0005f);
}

void GameScene::Render() {
	object->Render(Engine::getInstance()->getCamera());
}

void GameScene::onDestroy() {
	delete object;
	object = nullptr;
}

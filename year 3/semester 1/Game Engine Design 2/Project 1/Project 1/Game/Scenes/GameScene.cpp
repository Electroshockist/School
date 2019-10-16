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
	camera = new Camera();
	camera->setPosition(glm::vec3(0.0f, 0.0f, 4.0f));

	model = new Model("Resources/Models/Dice.obj", "Resources/Materials/Dice.mtl", ShaderHandler::getInstance()->getShader("basicShader"));
	object = new GameObject(model);
	if(!object || !model) {
		return false;
	}

	return true;
}

void GameScene::Update(const float deltaTime) {
	object->setAngle(object->getAngle() + 0.0005f);
}

void GameScene::Render() {
}

void GameScene::onDestroy() {

	delete camera;
	camera = nullptr;
}

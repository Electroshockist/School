#include "GameScene.h"
#include <iostream>
#include "../../Engine/Graphics/ShaderHandler.h"



GameScene::GameScene() {
	OnCreate();
}


GameScene::~GameScene() {
}

bool GameScene::OnCreate() {
	Engine::getInstance()->setCamera(new Camera());
	Engine::getInstance()->getCamera()->setPosition(glm::vec3(0.0f, 0.0f, 4.0f));

	Model* diceModel = new Model("Resources/Models/Dice.obj", "Resources/Materials/Dice.mtl", ShaderHandler::getInstance()->getShader("basicShader"));
	Model* appleModel = new Model("Resources/Models/Apple.obj", "Resources/Materials/Apple.mtl", ShaderHandler::getInstance()->getShader("basicShader"));

	SceneGraph::getInstance()->addModel(diceModel);
	SceneGraph::getInstance()->addModel(appleModel);

	SceneGraph::getInstance()->addGameObject(new GameObject(diceModel, glm::vec3(3.0, 0, 0)));
	SceneGraph::getInstance()->addGameObject(new GameObject(appleModel), "Apple");

	//SceneGraph::getInstance()->getGameObject("Apple")->setPosition(glm::vec3(1, 0, 3));

	return true;
}

void GameScene::Update(const float deltaTime) {
	SceneGraph::getInstance()->Update(deltaTime);
	//object->setAngle(object->getAngle() + 0.0005f);
}

void GameScene::Render() {
	SceneGraph::getInstance()->Render(Engine::getInstance()->getCamera());
}

void GameScene::onDestroy() {}

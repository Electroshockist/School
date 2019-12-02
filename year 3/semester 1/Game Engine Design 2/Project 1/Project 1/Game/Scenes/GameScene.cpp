#include "GameScene.h"
#include <iostream>
#include "../../Engine/Graphics/ShaderHandler.h"
#include "../../Engine/Math/CollisionHandler.h"

GameScene::GameScene() : Scene() {
}

GameScene::~GameScene() {
	onDestroy();
}

bool GameScene::OnCreate() {
	Engine::getInstance()->setCamera(new Camera());
	Engine::getInstance()->getCamera()->setPosition(glm::vec3(0.0f, 0.0f, 10.0f));
	Engine::getInstance()->getCamera()->addLightSources(new LightSource(glm::vec3(5.0f, 10.0f, 5.0f), 1.0f, 0.5f, glm::vec3(1.0f, 1.0f, 1.0f)));

	CollisionHandler::GetInstance()->OnCreate(100);

	Model* diceModel = new Model("./Resources/Models/Dice.obj", "./Resources/Materials/Dice.mtl", ShaderHandler::getInstance()->getShader("basicShader"));
	Model* appleModel = new Model("./Resources/Models/Apple.obj", "./Resources/Materials/Apple.mtl", ShaderHandler::getInstance()->getShader("basicShader"));

	SceneGraph::getInstance()->addModel(diceModel);
	SceneGraph::getInstance()->addModel(appleModel);

	SceneGraph::getInstance()->addGameObject(new GameObject(diceModel, glm::vec3(-3.0, -4.0, 0.0)));
	SceneGraph::getInstance()->addGameObject(new GameObject(appleModel),"Apple");

	SceneGraph::getInstance()->getGameObject("Apple")->setPosition(glm::vec3(1, -3.0, 0));

	return true;
}

void GameScene::Update(const float deltaTime) {
	
	SceneGraph::getInstance()->getGameObject("Apple")->setAngle(SceneGraph::getInstance()->getGameObject("Apple")->getAngle() + 0.05f);
	SceneGraph::getInstance()->getGameObject("GameObject1")->setAngle(SceneGraph::getInstance()->getGameObject("Apple")->getAngle() + 0.05f);
	SceneGraph::getInstance()->Update(deltaTime);
}

void GameScene::Render() {
	SceneGraph::getInstance()->Render(Engine::getInstance()->getCamera());
}

void GameScene::onDestroy() {}

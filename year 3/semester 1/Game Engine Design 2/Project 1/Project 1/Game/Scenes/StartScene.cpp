#include "StartScene.h"
#include "../../Engine/Core/Engine.h"
#include <iostream>


StartScene::StartScene() {
}


StartScene::~StartScene() {
}

bool StartScene::OnCreate() {
	Debug::info("creating startscene", __FILE__, __LINE__);
	std::cout << "creating startscene" << std::endl;
	Engine::getInstance()->setCurrentScene(1);
	return true;
}

void StartScene::Update(const float deltaTime) {
}

void StartScene::Render() {
}

void StartScene::onDestroy() {
}

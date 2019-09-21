#include "StartScene.h"

StartScene::StartScene() {
}


StartScene::~StartScene() {
}

bool StartScene::OnCreate() {
	Engine::getInstance()->setCurrentScene(1);
	return true;
}

void StartScene::Update(const float deltaTime) {
}

void StartScene::Render() {
}

void StartScene::onDestroy() {
}

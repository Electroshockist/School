#include "GameScene.h"
#include <iostream>



GameScene::GameScene(){
}


GameScene::~GameScene() {
}

bool GameScene::OnCreate() {
	std::cout << "creating gamescene" << std::endl;
	return true;
}

void GameScene::Update(const float deltaTime) {
}

void GameScene::Render() {
}

void GameScene::onDestroy() {
}

#include "Game0.h"



Game0::Game0() : GameInterface(), currentScene(nullptr), sceneNumber(0) {
}


Game0::~Game0() {
}

bool Game0::OnCreate() {
	delete currentScene;
	if (Engine::getInstance()->getCurrentScene() == 0) {
		currentScene = new StartScene();
		sceneNumber = 0;
	}
	//return success state of currentscene
	return currentScene->OnCreate();
}

void Game0::Update(const float deltaTime) {
	if (sceneNumber != Engine::getInstance()->getCurrentScene()) {
		BuildScene();
	}
	currentScene->Update(deltaTime);
}

void Game0::Render() {
}

void Game0::onDestroy() {
	delete currentScene;
	currentScene = nullptr;
}

void Game0::BuildScene() {
	delete currentScene;
	currentScene = nullptr;

	switch (Engine::getInstance()->getCurrentScene()) {
	case 1: currentScene = new GameScene();
		break;
	case 2: currentScene = new StartScene();
		break;
	}

	if (!currentScene->OnCreate()) {
		Engine::getInstance()->setIsRuning(false);
	}
	sceneNumber = Engine::getInstance()->getCurrentScene();

}

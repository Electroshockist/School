#include "Engine.h"

#include <iostream>

std::unique_ptr<Engine> Engine::instance = nullptr;

Engine::Engine() : window(nullptr), isRunning(false), gameInterface(nullptr), currentScene(0) {}

Engine::~Engine() {
	OnDestroy();
}

bool Engine::OnCreate(std::string name, int width, int height) {
	Debug::debugInit();
	Debug::setSeverity(MessageType::TYPE_INFO);

	window = new Window();
	if (!window->OnCreate(name, width, height)) {
		Debug::fatalerror("Window Failed to create", "Engine.h", __LINE__);
		return isRunning = false;
	}
	if (!gameInterface->OnCreate()) {
		//Debug::
	}

	return isRunning = true;
}

void Engine::Run() {
	while (isRunning) {
		Update(0.016f);
		Render();
	}

	//if not running, destroy
	OnDestroy();
}

void Engine::Update(const float deltaTime) {
	if (gameInterface) gameInterface->Update(deltaTime);
}

void Engine::Render() {

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (gameInterface) gameInterface->Render();

	SDL_GL_SwapWindow(window->getWindow());
}

void Engine::OnDestroy() {
	delete gameInterface;
	gameInterface = nullptr;

	delete window;
	window = nullptr;

	SDL_Quit();
	exit(0);
}

bool Engine::getIsRunning() {
	return false;
}

void Engine::setIsRuning(const bool isRunning) {
	this->isRunning = isRunning;
}

Engine * Engine::getInstance() {
	if (instance.get() == nullptr) {
		instance.reset(new Engine);
	}
	return instance.get();
}

void Engine::setGameInterface(GameInterface * gameInterface) {
	this->gameInterface = gameInterface;
}

void Engine::setCurrentScene(int currentScene) {
	this->currentScene = currentScene;
}

int Engine::getCurrentScene() const{
	return currentScene;
}


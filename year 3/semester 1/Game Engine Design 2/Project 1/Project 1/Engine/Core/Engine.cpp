#include "Engine.h"

#include <iostream>

std::unique_ptr<Engine> Engine::instance = nullptr;

Engine::Engine() : window(nullptr), isRunning(false) {}

Engine::~Engine() {
	OnDestroy();
}

bool Engine::OnCreate(std::string name, int width, int height) {
	window = new Window();
	if (!window->OnCreate(name, width, height)) {
		std::cout << "Window failed to create" << std::endl;
		return isRunning = false;
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
}

void Engine::Render() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	SDL_GL_SwapWindow(window->getWindow());
}

void Engine::OnDestroy() {
}

bool Engine::getIsRunning() {
	return false;
}

Engine * Engine::getInstance() {
	if (instance.get() == nullptr) {
		instance.reset(new Engine);
	}
	return instance.get();
}


#include "Engine.h"

#include "../Graphics/ShaderHandler.h"
#include <iostream>

std::unique_ptr<Engine> Engine::instance = nullptr;

Engine::Engine() : window(nullptr), isRunning(false), gameInterface(nullptr), fps(120), currentScene(0), camera(nullptr) {}

Engine::~Engine() {
	OnDestroy();
}

bool Engine::OnCreate(std::string name, int width, int height) {
	Debug::debugInit();
	Debug::setSeverity(MessageType::TYPE_INFO);

	window = new Window();
	if(!window->OnCreate(name, width, height)) {
		Debug::fatalError("Window Failed to create", __FILE__, __LINE__);
		return isRunning = false;
	}

	SDL_WarpMouseInWindow(window->getWindow(),
						  window->getWidth() / 2, window->getHeight() / 2);

	MouseEventListener::RegisterEngineObject(this);

	ShaderHandler::getInstance()->createProgram("colourShader",
												"Engine/Shaders/colourVertexShader.glsl",
												"Engine/Shaders/colourFragmentShader.glsl"
	);

	ShaderHandler::getInstance()->createProgram("basicShader",
												"Engine/Shaders/vertexShader.glsl",
												"Engine/Shaders/fragmentShader.glsl"
	);

	if(!gameInterface->OnCreate()) {
		Debug::fatalError("Game failed to create", __FILE__, __LINE__);
		return isRunning = false;
	}

	timer.Start();
	return isRunning = true;
}

void Engine::Run() {
	while(isRunning) {
		EventListener::update();
		timer.UpdateFrameTicks();
		Update(timer.GetDeltaTime());
		Render();
		SDL_Delay(timer.GetSleepTime(fps));
	}

	//if not running, destroy
	OnDestroy();
}

void Engine::setCamera(Camera * camera) {
	this->camera = camera;
}

Camera * Engine::getCamera() {
	return camera;
}

void Engine::Update(const float deltaTime) {
	if(gameInterface) gameInterface->Update(deltaTime);
}

void Engine::Render() {

	glClearColor(0.1f, 0.01f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if(gameInterface) gameInterface->Render();

	SDL_GL_SwapWindow(window->getWindow());
}

void Engine::OnDestroy() {
	delete camera;
	camera = nullptr;

	delete gameInterface;
	gameInterface = nullptr;

	delete window;
	window = nullptr;

	SDL_Quit();
	exit(0);
}

bool Engine::getIsRunning() {
	return isRunning;
}

void Engine::setIsRuning(const bool isRunning) {
	this->isRunning = isRunning;
}

Engine * Engine::getInstance() {
	if(instance.get() == nullptr) {
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

int Engine::getCurrentScene() const {
	return currentScene;
}

void Engine::notifyMousePressed(int x, int y) {

}

void Engine::notifyMouseReleased(int x, int y, int buttonType) {

}

void Engine::notifyMouseMove(int x, int y) {
	if(camera) {
		camera->processMouseMovement(MouseEventListener::GetMouseOffset().x,
									 MouseEventListener::GetMouseOffset().y);
	}

}

void Engine::notifyMouseScroll(int y) {
	if(camera) {
		camera->processMouseZoom(y);
	}
}

void Engine::exitGame() {
	isRunning = false;
}

glm::vec2 Engine::getScreenSize() const {
	return glm::vec2(window->getWidth(), window->getHeight());
}


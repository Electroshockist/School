#include "GameManager.h"
#include "Window.h"
#include "Timer.h"
#include "Assignment1.h"
#include "UI2.h"
#include <iostream>

GameManager::GameManager() {
	timer = nullptr;
	isRunning = true;
	currentScene = nullptr;
}


bool GameManager::OnCreate() {
	const int SCREEN_WIDTH = 1280;
	const int SCREEN_HEIGHT = 720;
	ptr = new Window(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (ptr == nullptr) {
		OnDestroy();
		return false;
	}
	if (ptr->OnCreate() == false) {
		OnDestroy();
		return false;
	}

	timer = new Timer();
	if (timer == nullptr) {
		OnDestroy();
		return false;
	}

	currentScene = new Assignment1(ptr->GetSDL_Window());
	if (currentScene == nullptr) {
		OnDestroy();
		return false;
	}

	if (currentScene->OnCreate() == false) {
		OnDestroy();
		return false;
	}

	return true;
}

void GameManager::Run() {
	SDL_Event event;
	bool start = false;
	while (isRunning) {
		if (SDL_PollEvent(&event) != 0) {
			currentScene->HandleEvents(event);
			
			//start, swap and close assignments via key press
			if (event.type == SDL_QUIT) { isRunning = false; }
			if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_1) {
					currentScene->OnDestroy();
					delete currentScene;
					currentScene = nullptr;
					currentScene = new Assignment1(ptr->GetSDL_Window());
					currentScene->OnCreate();
				}
				if (event.key.keysym.sym == SDLK_2) {
					currentScene->OnDestroy();
					delete currentScene;
					currentScene = nullptr;
					currentScene = new UI2(ptr->GetSDL_Window());
					currentScene->OnCreate();
				}
				
			}
			if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_0) {
					start = (SDLK_s);
					timer->Start();
				}
			}
				
		}
		if (start) {
			timer->UpdateFrameTicks();
			currentScene->Update(timer->GetDeltaTime());
			currentScene->Render();
		}

	}




		SDL_Delay(timer->GetSleepTime(60));
	}

GameManager::~GameManager() {}

void GameManager::OnDestroy(){
	if (ptr) delete ptr;
	if (timer) delete timer;
	if (currentScene) delete currentScene;
}
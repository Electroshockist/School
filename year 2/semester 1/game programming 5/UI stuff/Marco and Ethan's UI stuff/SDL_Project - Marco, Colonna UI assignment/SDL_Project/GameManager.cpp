#include "GameManager.h"
#include "Window.h"
#include "Timer.h"
#include "Assignment1.h"
#include <iostream>
#include "UI1.h"
#include "UI2.h"


GameManager::GameManager() {
	timer = nullptr;
	isRunning = true;
	currentScene = nullptr;
	
}


/// In this OnCreate() method, fuction, subroutine, whatever the word, 
bool GameManager::OnCreate() {
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;
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
	currentUI = new UI1(ptr->GetSDL_Window());
	if (currentUI == nullptr) {
		OnDestroy();
		return false;
	}

	if (currentUI->oncreate() == false) {
		OnDestroy();
		return false;
	}
	return true;
}

/// Here's the whole game
void GameManager::Run() {
	timer->Start();
	while (isRunning) {
		if (SDL_PollEvent(&event) != 0) {
			switch (event.type) {

			case(SDL_QUIT):
				isRunning = false;
				break;
			case(SDL_KEYDOWN):
				if (event.key.keysym.sym == SDLK_q) {
					delete currentUI;
				/*	currentUI = new UI1(ptr->GetSDL_Window);
					currentUI->oncreate();*/	
					
					currentUI = new UI1(ptr->GetSDL_Window());
					currentUI->oncreate();
					
				}
				if (event.key.keysym.sym == SDLK_w) { // event for press of f3 
					
					delete currentUI;
					currentUI = new UI2(ptr->GetSDL_Window());
					currentUI->oncreate();
					
				}
				
			default:
				break;
			}

		}

		timer->UpdateFrameTicks();
		//currentScene->Update(timer->GetDeltaTime());
		//currentScene->Render();
		currentUI->render();

		/// Keeep the event loop running at a proper rate
		SDL_Delay(timer->GetSleepTime(60)); ///60 frames per sec
	}
}

GameManager::~GameManager() {}

void GameManager::OnDestroy(){
	if (ptr) delete ptr;
	if (timer) delete timer;
	if (currentScene) delete currentScene;
}
#include "GameManager.h"
#include "Window.h"
#include "Timer.h"
#include "SDL.h"
#include "Assignment1.h"

#include <iostream>

GameManager::GameManager() {
	timer = nullptr;
	isRunning = true;
	currentScene = nullptr;
}

/// In this OnCreate() method, fuction, subroutine, whatever the word, 
bool GameManager::OnCreate() {
	const int SCREEN_WIDTH = 1024;
	const int SCREEN_HEIGHT = 500;
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

	windowName = "";
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

    while (isRunning) {

        if (SDL_PollEvent(&event) != 0) {
            currentScene->HandleEvents(event);

			switch (event.type) {
				//quit on escape or close
				case SDL_QUIT:
					isRunning = false;
					break;
				case SDL_KEYDOWN:
					switch (event.key.keysym.sym)
					{
					case SDLK_ESCAPE:
					default:
						break;
					}
					if (event.key.keysym.sym == SDLK_ESCAPE) isRunning = false;
					break;

				default:
					break;
			}
        }
		currentScene->Update(timer->GetDeltaTime());
		currentScene->Render();

		timer->UpdateFrameTicks();

        /// Keeep the event loop running at a proper rate
        SDL_Delay(timer->GetSleepTime(1000)); ///1000 frames per sec

    }
}

GameManager::~GameManager() {}

void GameManager::OnDestroy(){
	if (ptr) delete ptr;
	if (timer) delete timer;
	if (currentScene) delete currentScene;
}
#include "Assignment1.h"
#include <SDL.h>
#include <SDL_image.h>
#include "BaseUI.h"
#include "Timer.h"
#include <iostream>
#include <string>

using namespace std;
Assignment1::Assignment1(SDL_Window* sdlWindow_) {
	window = sdlWindow_;
	elapsedTime = 0.0f;
	frameCount = 0.0f;
	playerHp = 68;
	//body (used this because thats what we did in scott's class making it easier to remember and work with) hold each ui element we create. works as an
	//array for easy use and deletion of specific/all elements
	for (int i = 0; i < NUM_BODIES; i++)
	{
		body[i] = nullptr;
	}
}

Assignment1::~Assignment1() {
}

bool Assignment1::OnCreate() {
	int w, h;
	SDL_GetWindowSize(window, &w, &h);
	//points on the screen. converts from 1280 x 720 resolution to a grid we set
	projectionMatrix = MMath::viewportNDC(w, h) * MMath::orthographic(0.0f, 100.0f, 0.0f, 100.0f, 0.0f, 1.0f);

	IMG_Init(IMG_INIT_PNG);
	//creation of ui elements in scene with respective values and attributes
	//						image name,		position,		turned on/off
	body[0] = new BaseUI("HealthRed.png", Vec3(15.0f, 100.0f, 0.0f), true);
	if (body[0] == nullptr) {
		return false;
	}
	body[1] = new BaseUI("HealthBar.png", Vec3(15.0f, 100.0f, 0.0f), true);
	if (body[1] == nullptr) {
		return false;
	}
	body[2] = new BaseUI("HealthFrame.png", Vec3(15.0f, 100.0f, 0.0f), true);
	if (body[2] == nullptr) {
		return false;
	}
	body[3] = new BaseUI("PlayerIcon2.png", Vec3(0.0f, 100.0f, 0.0f), true);
	if (body[3] == nullptr) {
		return false;
	}
	body[4] = new BaseUI("PlayerIcon1.png", Vec3(0.0f, 100.0f, 0.0f), true);
	if (body[4] == nullptr) {
		return false;
	}
	body[5] = new BaseUI("PlayerFrame.png", Vec3(0.0f, 100.0f, 0.0f), true);
	if (body[5] == nullptr) {
		return false;
	}
	body[6] = new BaseUI("Text.png", Vec3(15.0f, 20.0f, 0.0f), true);
	if (body[6] == nullptr) {
		return false;
	}
	body[7] = new BaseUI("Popup.png", Vec3(0.0f, 90.0f, 0.0f), false);
	if (body[7] == nullptr) {
		return false;
	}
	return true;
}

void Assignment1::OnDestroy() {
	IMG_Quit();
	for (int i = 0; i < NUM_BODIES; i++) {
		if (body[i]) {
			delete body[i];
			body[i] = nullptr;
		}
	}
}
//no particular use for update here
void Assignment1::Update(const float time) {
	
	elapsedTime += time;
	frameCount++;
}

//scotts rendering code we learned and used. not much to say here as it is not my own
void Assignment1::Render() {
	

	SDL_Rect imageRectangle;
	SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xff, 0xff, 0xff));

	for (int i = 0; i < NUM_BODIES; i++) {
		if (body[i]->display == true) {
			Vec3 screenCoords = projectionMatrix * body[i]->pos;


			imageRectangle.h = body[i]->getImage()->h;
			imageRectangle.w = body[i]->getImage()->w;
			imageRectangle.x = screenCoords.x;
			imageRectangle.y = screenCoords.y;


			SDL_BlitSurface(body[i]->getImage(), nullptr, screenSurface, &imageRectangle);

		}
	}
	SDL_UpdateWindowSurface(window);
}

void Assignment1::HandleEvents(const SDL_Event& event) {
	//while the second ui focuses on the use of mouseclicks this ui focuses on testing keypresses
	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == SDLK_5) {
	//simply a test for the keypress, disable or enables the playericon. used again in the logic for the healthbar
			if (body[4]->display == true) { body[4]->display = false; }
			else { body[4]->display = true; }
			
		}
		//pressing p causes lose to player health. showing how the ui can work with ingame stats
		if (event.key.keysym.sym == SDLK_p) {
			//when p is pressed and the player health isnt at 0 remove 4 hp and move the healthbar over by 4 units. this causes the bar to drop
			if (playerHp >= 1) { playerHp -= 4; body[1]->pos.x -= 4; }
			//this stops the health and healthbar to stop lowering once health is at 0
			if (playerHp <= 0) { playerHp = 0; body[4]->display = false; }

		}
		if (event.key.keysym.sym == SDLK_m) {
			//simply a test to create popup menus/windows
			//in proper game easily disable update function and that would cause the game to pause.
			if (body[7]->display == true) { body[7]->display = false; }
			else { body[7]->display = true; }

		}
	}
}

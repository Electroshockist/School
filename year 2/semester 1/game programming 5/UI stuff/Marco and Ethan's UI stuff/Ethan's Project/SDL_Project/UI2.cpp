#include "UI2.h"
#include <SDL.h>
#include <SDL_image.h>
#include "BaseUI.h"
#include "Timer.h"
#include <iostream>
#include <string>

using namespace std;
UI2::UI2(SDL_Window* sdlWindow_) {
	window = sdlWindow_;
	elapsedTime = 0.0f;
	frameCount = 0.0f;
	//body (used this because thats what we did in scott's class making it easier to remember and work with) hold each ui element we create. works as an
	//array for easy use and deletion of specific/all elements
	for (int i = 0; i < NUM_BODIES; i++)
	{
		body[i] = nullptr;
	}
}

UI2::~UI2() {
}

bool UI2::OnCreate() {
	int w, h;
	SDL_GetWindowSize(window, &w, &h);
	//points on the screen. converts from 1280 x 720 resolution to a grid we set
	projectionMatrix = MMath::viewportNDC(w, h) * MMath::orthographic(0.0f, 100.0f, 0.0f, 100.0f, 0.0f, 1.0f);

	IMG_Init(IMG_INIT_PNG);
	//creation of ui elements in scene with respective values and attributes
	//a few unused (but still needed for testing/experimentation) images/ui elements. did not get highlighted buttons to work when mouse was over them
	//static
	//						image name,		position,		turned on/off
	body[0] = new BaseUI("menuBack.png", Vec3(35.0f, 95.0f, 0.0f), true);
	if (body[0] == nullptr) {
		return false;
	}
	body[1] = new BaseUI("x.png", Vec3(47.0f, 24.0f, 0.0f), true);
	if (body[1] == nullptr) {
		return false;
	}
	body[2] = new BaseUI("xHighlight.png", Vec3(47.0f, 24.0f, 0.0f), false);
	if (body[2] == nullptr) {
		return false;
	}
	body[3] = new BaseUI("play.png", Vec3(40.0f, 90.0f, 0.0f), true);
	if (body[3] == nullptr) {
		return false;
	}
	body[4] = new BaseUI("playHighlight.png", Vec3(40.0f, 90.0f, 0.0f), false);
	if (body[4] == nullptr) {
		return false;
	}
	body[5] = new BaseUI("info.png", Vec3(40.0f, 70.0f, 0.0f), true);
	if (body[5] == nullptr) {
		return false;
	}
	body[6] = new BaseUI("infoHighlight.png", Vec3(40.0f, 70.0f, 0.0f), false);
	if (body[6] == nullptr) {
		return false;
	}
	body[7] = new BaseUI("options.png", Vec3(40.0f, 50.0f, 0.0f), true);
	if (body[7] == nullptr) {
		return false;
	}
	body[8] = new BaseUI("optionsHighlight.png", Vec3(40.0f, 50.0f, 0.0f), false);
	if (body[8] == nullptr) {
		return false;
	}
	body[9] = new BaseUI("playPop.png", Vec3(15.0f, 100.0f, 0.0f), false);
	if (body[9] == nullptr) {
		return false;
	}
	body[10] = new BaseUI("infoPop.png", Vec3(15.0f, 100.0f, 0.0f), false);
	if (body[10] == nullptr) {
		return false;
	}
	body[11] = new BaseUI("sliders.png", Vec3(15.0f, 100.0f, 0.0f), false);
	if (body[11] == nullptr) {
		return false;
	}
	return true;
}

//destroys elements on close, removes pointers properly
void UI2::OnDestroy() {
	IMG_Quit();
	for (int i = 0; i < NUM_BODIES; i++) {
		if (body[i]) {
			delete body[i];
			body[i] = nullptr;
		}
	}
}

//no particular use for update here
void UI2::Update(const float time) {

	elapsedTime += time;
	frameCount++;
}

//scotts rendering code we learned and used. not much to say here as it is not my own
void UI2::Render() {


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

void UI2::HandleEvents(const SDL_Event& event) {
	//handling mouse clicks!!!
	if (event.button.button == SDL_BUTTON_LEFT)
	{
			//Get the mouse position when clicked
			int x = event.button.x;
			int y = event.button.y;
			//used these commented code lines to determine location of buttons on screen
			//std::cout << x << endl;
			//std::cout << y << endl;

			//takes the top left and bottom right corners in order to determine the rectangle inwhich the button can be clicked
			//the check for "true" displays make it so that when one popup is active the others cant be turned on. and this will also close any popups
			//doesnt matter which one is open, saves on the use of multiple if statements
			if ((x > 0) && (x < 1280) && (y > 0) && (y < 720) && (body[9]->display == true || body[10]->display == true || body[11]->display == true))
			{
				body[9]->display = false;
				body[10]->display = false;
				body[11]->display = false;
			}
			//again gets two points to form the rectangular area that is the button. simply checks if a mouse click occured within it
			if ((x > 510) && (x < 826) && (y > 70) && (y < 160))
			{
				body[9]->display = true;
			}
			if ((x > 510) && (x < 826) && (y > 215) && (y < 312))
			{
				body[10]->display = true;
			}
			if ((x > 510) && (x < 826) && (y > 362) && (y < 454))
			{
				body[11]->display = true;
			}
			
	}
}

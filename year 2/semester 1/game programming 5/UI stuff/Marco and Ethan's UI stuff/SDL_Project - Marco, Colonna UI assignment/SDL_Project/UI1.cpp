#include "UI1.h"
#include "Body.h"
#include<SDL.h>


UI1::UI1(SDL_Window*sdlWindow_)
{
	Screen = sdlWindow_;
	for (int i = 0; i < NUM_BODIES; i++) 
	{
		body[i] = nullptr;
	}
}


UI1::~UI1()
{
}


bool UI1::oncreate() {
	int w, h;
	SDL_GetWindowSize(Screen, &w, &h);

	body[0] = new Body("Diablo.bmp", 0.0f, Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f));
	if (body[0] == nullptr) {
		return false;
	}
	return true;
}


void UI1::render() {

	SDL_Surface * screenSurface = SDL_GetWindowSurface(Screen); // window surface
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 25, 25, 25));// makes the backround grey
	SDL_Rect imageRectangle = { 0,0,1024,720 };// image rectangle 
	imageRectangle.h = body[0]->getImage()->h; // gets the height 
	imageRectangle.w = body[0]->getImage()->w;// and the width of the image a puts it to the image rectange

	SDL_BlitSurface(body[0]->getImage(), nullptr, screenSurface, &imageRectangle); // draws most of the ui

	SDL_UpdateWindowSurface(Screen); // updates window
}
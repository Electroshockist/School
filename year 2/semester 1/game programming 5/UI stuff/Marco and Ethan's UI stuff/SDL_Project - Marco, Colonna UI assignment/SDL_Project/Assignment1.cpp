#include "Assignment1.h"
#include "Body.h"
#include <SDL.h>

Assignment1::Assignment1(SDL_Window* sdlWindow_){
	window = sdlWindow_;
	elapsedTime = 0.0f;
	body = nullptr;
}

Assignment1::~Assignment1(){
}

bool Assignment1::OnCreate() {
	int w, h;
	SDL_GetWindowSize(window,&w,&h);
	
	projectionMatrix = MMath::viewportNDC(w,h) * MMath::orthographic(0.0f, 30.0f, 0.0f, 15.0f, 0.0f, 1.0f) ;
	
	body = new Body("jetskiSmall.bmp", 1000.0f, Vec3(0.0f, 1.5f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f));
	if (body == nullptr) {
		return false;
	}
	return true;
}

void Assignment1::OnDestroy() {
	if (body) {
		delete body;
		body = nullptr;
		
	}
}

void Assignment1::Update(const float time) {
	elapsedTime += time;

	if (elapsedTime < 5.0f) {
		/// Accelerate for three seconds
		body->ApplyForce(Vec3(400.0f, 0.0f, 0.0f));
	}
	if(elapsedTime > 14.0f){
		/// Apply the brakes until it stops
		if (body->vel.x > 0.0f) {
			body->ApplyForce(Vec3(-600.0f, 0.0f, 0.0f));
		}
		else {
			body->vel.x = 0.0f;

		}
	}
	if (body) body->Update(time);
}

void Assignment1::Render() {

	Vec3 screenCoords = projectionMatrix * body->pos;

	SDL_Rect imageRectangle;
	imageRectangle.h = body->getImage()->h;
	imageRectangle.w = body->getImage()->w;
	imageRectangle.x = screenCoords.x; /// implicit type conversions BAD - probably causes a compiler warning
	imageRectangle.y = screenCoords.y; /// implicit type conversions BAD - probably causes a compiler warning

	SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xff, 0xff, 0xff));
	SDL_BlitSurface(body->getImage(), nullptr, screenSurface, &imageRectangle);
	SDL_UpdateWindowSurface(window);
}
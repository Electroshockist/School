#include "Assignment1.h"
#include "Body.h"
#include "MMath.h"
#include <SDL.h>

using namespace std;

Assignment1::Assignment1(SDL_Window* sdlWindow_, SDL_Renderer* renderer){
	window = sdlWindow_;
	renderer = SDL_CreateRenderer(window,0,0);
	elapsedTime = 0.0f;
	totalFrameCount = 0L;
	frameCount = 0L;
}

Assignment1::~Assignment1(){
}

bool Assignment1::OnCreate() {
	//move all this to scene.cpp
	int w, h;

	points[0] = { 0, 0 };

	SDL_GetWindowSize(window, &w, &h);

	float aspectRatio = (float)h / (float)w;

	projectionMatrix = MMath::viewportNDC(w, h) * MMath::orthographic(-30.0f, 30.0f, -30.0f * aspectRatio, 30.0f * aspectRatio, 0.0f, 1.0f);

	invMat = MMath::inverse(projectionMatrix);

	//moves origin to center of screen
	Vec3 origin(0.0f, 0.0f, 0.0f);
	origin = invMat * origin;

	SDL_RenderDrawLine(renderer, 0, 0, 10, 10);
	return true;
}

void Assignment1::OnDestroy() {
}

void Assignment1::Update(const float time) {

	elapsedTime += time;

	frameCount++;
}

void Assignment1::Render() {
	SDL_Surface *screenSurface = SDL_GetWindowSurface(window);

	//clears screen
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xff, 0xff, 0xff));
	SDL_UpdateWindowSurface(window);
}
void Assignment1::HandleEvents(SDL_Event& event) {
	//get key presses
	if (event.type == SDL_KEYDOWN) {
		printf("key down\n");
	}
}
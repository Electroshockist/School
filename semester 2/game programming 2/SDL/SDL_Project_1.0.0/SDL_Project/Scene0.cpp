#include "Scene0.h"
#include <SDL.h>
Scene0::Scene0(SDL_Window* sdlWindow_){
	window = sdlWindow_;
	jetSkiImage = nullptr;
}

Scene0::~Scene0(){
}

bool Scene0::OnCreate() {
	int w, h;
	SDL_GetWindowSize(window,&w,&h);
	projectionMatrix = MMath::viewportNDC(w,h) * MMath::orthographic(0.0f, 14.0f, 0.0f, 7.0f, 0.0f, 1.0f) ;
	jetSkiImage = SDL_LoadBMP("jetski.bmp");
	if (jetSkiImage == nullptr) {
		return false;
	}
	jetSkiPos.Load(0.0f, 1.5f, 0.0f);
	return true;
}

void Scene0::OnDestroy() {}

void Scene0::Update(const float time) {
	/// This is the physics in the x dimension only
	jetSkiPos.x += 2.25f * time; /// I just made up a velocity 
}

void Scene0::Render() {

	Vec3 screenCoords = projectionMatrix * jetSkiPos;

	jetSkiRect.h = jetSkiImage->h;
	jetSkiRect.w = jetSkiImage->w;
	jetSkiRect.x = screenCoords.x; /// implicit type conversions BAD - probably causes a compiler warning
	jetSkiRect.y = screenCoords.y; /// implicit type conversions BAD - probably causes a compiler warning

	SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xff, 0xff, 0xff));
	SDL_BlitSurface(jetSkiImage, nullptr, screenSurface, &jetSkiRect);
	SDL_UpdateWindowSurface(window);
}
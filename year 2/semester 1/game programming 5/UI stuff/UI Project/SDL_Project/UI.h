#pragma once
#include "SDL.h"

class UI {
	virtual void render(SDL_Surface * screensurface) = 0;
	virtual ~UI() = 0;
};
#pragma once

#include <SDL.h>

class UIRenderInterface {
	public:
		virtual void draw();
};

class UI_SDLRender : UIRenderInterface {
	private:
		SDL_Surface * surface;
	public:
		inline void draw() {}
};
#include "Window.h"

Window::Window(int width, int height){
	this->width = width;
	this->height = height;

	window = nullptr;   ///(use nullptr) 
	screenSurface = nullptr;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL_Error: %s\n", SDL_GetError());
	}
	else {
		/// Create the window
		window = SDL_CreateWindow("One empty boi", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_FULLSCREEN);
		if (window == nullptr) {
			printf("SDL_Error: %s\n", SDL_GetError());
		}
		else {
			screenSurface = SDL_GetWindowSurface(window);
			SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xf2, 0x00, 0xf2));
			SDL_UpdateWindowSurface(window);
			SDL_Rect rect = { 200, 60, 1010, 500 };
			SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0xa3, 0x00, 0x17));
			SDL_UpdateWindowSurface(window);
			SDL_Delay(2000);
		}
	}
}

Window::~Window(){
	{
		/// Kill the window
		SDL_DestroyWindow(window);

		///Exit the SDL subsystems
		SDL_Quit();
	}
}

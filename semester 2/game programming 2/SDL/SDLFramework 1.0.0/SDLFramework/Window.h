#include <SDL.h>
#include <stdio.h>
class Window{
private:
	int width, height;
	SDL_Window* window;
	SDL_Surface* screenSurface;

public:
	Window(int width, int height);
	~Window();
};


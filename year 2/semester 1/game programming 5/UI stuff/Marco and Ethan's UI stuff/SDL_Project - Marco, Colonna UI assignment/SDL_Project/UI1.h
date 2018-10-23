#ifndef UI1_H
#define UI1_H
#include<SDL.h>
#include"UIParent.h"
#define NUM_BODIES 1


class UI1: public UIParent
{

private:
	SDL_Window * Screen;
	class Body * body[NUM_BODIES];

public:
	
	bool oncreate();
	void render();


	UI1(SDL_Window* SDL_Window_);
	~UI1();
};

#endif 
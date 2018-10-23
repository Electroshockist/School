#ifndef UI2_H
#define UI2_H
#include<SDL.h>
#include"UIParent.h"
#define NUM_BODIES 2


class UI2 : public UIParent
{

private:
	SDL_Window * Screen;
	class Body * body[NUM_BODIES];

public:

	bool oncreate();
	void render();


	UI2(SDL_Window* SDL_Window_);
	~UI2();
};

#endif 
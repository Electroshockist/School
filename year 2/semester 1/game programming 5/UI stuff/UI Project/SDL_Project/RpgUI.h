#pragma once
#include "UI.h"
class RpgUI : public UI
{
public:
	RpgUI();
	~RpgUI();

	void render(SDL_Surface * screensurface);
};


#ifndef Assignment1_H
#define Assignment1_H

#include "MMath.h"
#include "Scene.h"
#include <SDL.h>
#include "BaseUI.h"

#define NUM_BODIES 8

using namespace MATH;
class Assignment1 : public Scene{
private:
	SDL_Window *window;
	Matrix4 projectionMatrix;
	class BaseUI* body[NUM_BODIES];
	float elapsedTime;
	long frameCount;
	//to demonstrate player stats and ui functionality
	int playerHp;
	
public:
	Assignment1(SDL_Window* sdlWindow);
	~Assignment1();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();

	virtual void HandleEvents(const SDL_Event& event);
};

#endif


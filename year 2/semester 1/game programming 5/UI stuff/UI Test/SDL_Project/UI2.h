#ifndef UI2_H
#define UI2_H

#include "MMath.h"
#include "Scene.h"
#include <SDL.h>
#include "BaseUI.h"

#define NUM_BODIES 12

using namespace MATH;
class UI2 : public Scene {
private:
	SDL_Window *window;
	Matrix4 projectionMatrix;
	class BaseUI* body[NUM_BODIES];
	float elapsedTime;
	long frameCount;

public:
	UI2(SDL_Window* sdlWindow);
	~UI2();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();

	virtual void HandleEvents(const SDL_Event& event);
};

#endif
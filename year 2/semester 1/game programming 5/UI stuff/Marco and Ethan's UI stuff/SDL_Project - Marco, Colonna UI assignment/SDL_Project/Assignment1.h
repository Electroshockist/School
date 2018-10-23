#ifndef Assignment1_H
#define Assignment1_H

#include "MMath.h"
#include "Scene.h"

#include <SDL.h>

using namespace MATH;
class Assignment1 : public Scene {
private:
	SDL_Window *window;
	Matrix4 projectionMatrix;
	class Body* body;
	float elapsedTime;
public:
	Assignment1(SDL_Window* sdlWindow);
	~Assignment1();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
};

#endif


#ifndef Assignment1_H
#define Assignment1_H

#include "MMath.h"
#include "Scene.h"
#include "Body.h"
#include "Collider.h"

#include <iostream>
#include <SDL.h>
#include <fstream>

using namespace MATH;
using namespace std;

class Assignment1 : public Scene {
private:
	SDL_Window *window;
	SDL_Renderer *renderer;

	Body* bodies[2] = {};

	SDL_Point points[4];

	Matrix4 projectionMatrix;
	Matrix4 invMat;
	float elapsedTime;
	unsigned long totalFrameCount;
	unsigned long frameCount;
	bool clicked;

public:
	Assignment1(SDL_Window* sdlWindow);
	~Assignment1();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
	void HandleEvents(SDL_Event& event);
};

#endif


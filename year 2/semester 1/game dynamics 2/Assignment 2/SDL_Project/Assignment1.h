#ifndef Assignment1_H
#define Assignment1_H

#include "MMath.h"
#include "Scene.h"

#include <SDL.h>
#include <fstream>

#define POINTS_COUNT 4

using namespace MATH;
using namespace std;

class Assignment1 : public Scene {
private:
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Point points[POINTS_COUNT] = {
		{ 3.2, 2 },
		{ 3, 2.4 },
		{ 3.4, 2.4 },
		{ 3.2, 2 }
	};
	Matrix4 projectionMatrix;
	Matrix4 invMat;
	float elapsedTime;
	unsigned long totalFrameCount;
	unsigned long frameCount;

public:
	Assignment1(SDL_Window* sdlWindow, SDL_Renderer* renderer);
	~Assignment1();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
	void HandleEvents(SDL_Event& event);
};

#endif


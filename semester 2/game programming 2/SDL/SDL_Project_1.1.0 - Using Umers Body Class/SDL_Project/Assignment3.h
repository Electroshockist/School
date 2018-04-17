#ifndef Assignment3_H
#define Assignment3_H

#include "MMath.h"
#include "Scene.h"

#include <SDL.h>
#include <fstream>

using namespace MATH;
using namespace std;
#define NUM_BODIES 3

class Assignment3 : public Scene {
private:
	int numBodies = NUM_BODIES;
	SDL_Window * window;
	Matrix4 projectionMatrix;
	class Body* bodies[NUM_BODIES];
	class Vec3* Force[NUM_BODIES];

	bool crashed;
	float elapsedTime;
	unsigned long totalFrameCount;
	unsigned long frameCount;
	Vec3 ToPhysicsCoords(int i);
public:
	Assignment3(SDL_Window* sdlWindow);
	~Assignment3();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
	void HandleEvents(SDL_Event& event);
};

#endif


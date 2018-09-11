#ifndef Assignment1_H
#define Assignment1_H

#include "MMath.h"
#include "Scene.h"

#include <SDL.h>
#include <fstream>

using namespace MATH;
using namespace std;
#define NUM_BODIES 3

class Assignment1 : public Scene {
private:
	SDL_Window *window;
	Matrix4 projectionMatrix;
	class Body* bodies[NUM_BODIES];
	float elapsedTime;
	unsigned long frameCount;
	bool crashed;
public:
	Assignment1(SDL_Window* sdlWindow);
	~Assignment1();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
	//Vec3 toPhysics(int x, int y);
	Vec3 physicsPos[NUM_BODIES];
	Vec3 physicsSize[NUM_BODIES];
};

#endif


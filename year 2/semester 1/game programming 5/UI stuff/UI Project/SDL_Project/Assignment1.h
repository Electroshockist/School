#ifndef Assignment1_H
#define Assignment1_H

#include "MMath.h"
#include "Scene.h"
#include "UI.h"
#include "HackSlashUI.h"

#include <SDL.h>
#include <fstream>

using namespace MATH;
using namespace std;

class Assignment1 : public Scene {
private:
	SDL_Window *window;
	Matrix4 projectionMatrix;
	Matrix4 invMat;

	float elapsedTime;
	unsigned long totalFrameCount;
	unsigned long frameCount;
	HackSlashUI ui;

public:
	Assignment1(SDL_Window* sdlWindow);
	~Assignment1();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
	void HandleEvents(SDL_Event& event);
	void SetUI(UI* ui);
};

#endif


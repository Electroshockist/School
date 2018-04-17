#include "Assignment3.h"
#include "Body.h"
#include "MMath.h"
#include "Matrix.h"
#include <math.h>
#include <SDL.h>

using namespace std;
using namespace MATH;


Assignment3::Assignment3(SDL_Window* sdlWindow_) {
	window = sdlWindow_;
	elapsedTime = 0.0f;
	totalFrameCount = 0L;
	frameCount = 0L;
	for (int i = 0; i < NUM_BODIES; i++) {
		bodies[i] = nullptr;
	}
}

Assignment3::~Assignment3() {
}

bool Assignment3::OnCreate() {
	int w, h;
	SDL_GetWindowSize(window, &w, &h);

	crashed = false;

	projectionMatrix = MMath::viewportNDC(w, h) * MMath::orthographic(0.0f, 30.0f, 0.0f, 30.0f, 0.0f, 1.0f);

	//create 3 bodies
	bodies[0] = new Body("planet.bmp", 1.0f, Vec3(7.0f, 2.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), 0.0f, false, false);
	bodies[1] = new Body("brown dwarf.bmp", 100.0f, Vec3(10.0f, 10.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), 0.0f, false, false);
	bodies[2] = new Body("star.bmp", 150.0f, Vec3(15.0f, 15.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), 0.0f, false, true);

	for (int i = 0; i < NUM_BODIES; i++) {
		if (bodies[i] == nullptr) {
			return false;
		}
	}
	return true;
}

void Assignment3::OnDestroy() {
	for (int i = 0; i < NUM_BODIES; i++) {
		if (bodies[i]) {
			delete bodies[i];
			bodies[i] = nullptr;
		}
	}
}
Vec3 Assignment3::ToPhysicsCoords(int i) {
	Matrix4 tempMat = MMath::inverse(projectionMatrix);
	Vec3 tempVec(bodies[i]->getImage()->w, bodies[i]->getImage()->h, 0.0f);
	tempVec = tempMat * tempVec;
	return  tempVec;
}

void Assignment3::Update(const float time) {

	Vec3 physicsBody = ToPhysicsCoords(0);
	
	Physics(bodies);

	elapsedTime += time;
	printf("Physics coords: [%f, %f] Screen coords: [%d, %d]\n", physicsBody.x, physicsBody.y, bodies[0]->getImage()->w, bodies[0]->getImage()->h);

	if (elapsedTime < 0.1f) {
		//apply force ASAP
		bodies[0]->ApplyForce(Vec3(40.0f, 20.0f, 0.0f));
	}
	
	//updates bodies
	for (int i = 0; i < NUM_BODIES; i++) {
		if (bodies[i]) bodies[i]->Update(time, bodies[i]->gravity);
	}
}

//renders everything
void Assignment3::Render() {
	SDL_Rect imageRectangle;
	SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
	//clears screen
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xff, 0xff, 0xff));

	for (int i = 0; i < NUM_BODIES; i++) {
		Vec3 screenCoords = projectionMatrix * bodies[i]->pos;
		imageRectangle.h = bodies[i]->getImage()->h;
		imageRectangle.w = bodies[i]->getImage()->w;
		imageRectangle.x = screenCoords.x; /// implicit type conversions BAD - probably causes a compiler warning
		imageRectangle.y = screenCoords.y; /// implicit type conversions BAD - probably causes a compiler warning
		SDL_BlitSurface(bodies[i]->getImage(), nullptr, screenSurface, &imageRectangle);
	}
	SDL_UpdateWindowSurface(window);
}
void Assignment3::HandleEvents(SDL_Event& event) {
	if (event.type == SDL_KEYDOWN) {
		//printf("key down\n");
	}
}
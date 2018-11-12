#include "Assignment1.h"

using namespace std;

Assignment1::Assignment1(SDL_Window* sdlWindow_){
	window = sdlWindow_;
	renderer = SDL_CreateRenderer(window,0,0);
	elapsedTime = 0.0f;
	totalFrameCount = 0L;
	frameCount = 0L;
}

Assignment1::~Assignment1(){
}

bool Assignment1::OnCreate() {
	bodies[0] = new Body();
	bodies[1] = new Body();

	bodies[0]->basePoints[0] = { 0, 40 };
	bodies[0]->basePoints[1] = { 0, 0 };
	bodies[0]->basePoints[2] = { 40, 0 };
	bodies[0]->basePoints[3] = { 0, 40 };

	bodies[1]->basePoints[0] = { 15, 40 };
	bodies[1]->basePoints[1] = { 15, 20 };
	bodies[1]->basePoints[2] = { 40, 20 };
	bodies[1]->basePoints[3] = { 15, 40 };

	bodies[0]->pos = Vec3(450, 150, 0);
	bodies[1]->pos = Vec3(450, 150, 0);

	return true;
}

void Assignment1::OnDestroy() {
}

void Assignment1::Update(const float time) {

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < bodies[i]->pointCount; j++) {
			bodies[i]->points[j].x = bodies[i]->basePoints[j].x + (int)bodies[i]->pos.x;
			bodies[i]->points[j].y = bodies[i]->basePoints[j].y + (int)bodies[i]->pos.y;
		}
	}

	Collider::HandleCollision(*bodies[0], *bodies[1]);

	elapsedTime += time;

	frameCount++;
}

void Assignment1::Render() {
	SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);

	for (int i = 0; i < 2; i++) {
		for (int  j = 0; j < bodies[i]->pointCount; j++){

			SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
			SDL_RenderDrawLines(renderer, bodies[i]->points, bodies[i]->pointCount);
		}

	}
	SDL_RenderPresent(renderer);

}

void Assignment1::HandleEvents(SDL_Event& event) {
	//get key presses
	if (event.type == SDL_KEYDOWN) {
		printf("key down\n");
	}
	switch (event.type) {

		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button) clicked = true;
			break;
		case SDL_MOUSEBUTTONUP:
			if (event.button.button) clicked = false;
		default:
			break;
	}

	//move first body when cursor clicked
	if (clicked) {
		//get cursor motion
		Vec3 v((float)event.motion.x, (float)event.motion.y, 0.0f);
		//set first body position to cursor position
		for (int j = 0; j < bodies[0]->pointCount; j++) {
			bodies[0]->pos = v;

			//cout << "\t" << bodies[0]->pos.x << ", " << bodies[0]->pos.y;
		}
	}
}
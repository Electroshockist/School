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
	//move all this to scene.cpp
	int w, h;

	SDL_GetWindowSize(window, &w, &h);

	float aspectRatio = (float)h / (float)w;

	projectionMatrix = MMath::viewportNDC(w, h) * MMath::orthographic(-30.0f, 30.0f, -30.0f * aspectRatio, 30.0f * aspectRatio, 0.0f, 1.0f);

	invMat = MMath::inverse(projectionMatrix);

	//moves origin to center of screen
	Vec3 origin(0.0f, 0.0f, 0.0f);
	origin = invMat * origin;

	bodies[0] = new Body();
	bodies[1] = new Body();

	bodies[0]->basePoints[0] = { 4, 9 };
	bodies[0]->basePoints[1] = { 9, 6 };
	bodies[0]->basePoints[2] = { 4, 3 };
	bodies[0]->basePoints[3] = { 4, 9 };

	bodies[1]->basePoints[0] = { 8, 8 };
	bodies[1]->basePoints[1] = { 12, 8 };
	bodies[1]->basePoints[2] = { 8, 4 };
	bodies[1]->basePoints[3] = { 8, 8 };

	return true;
}

void Assignment1::OnDestroy() {
}

void Assignment1::Update(const float time) {

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < bodies[i]->pointCount; j++) {
			bodies[i]->points[j].x = bodies[i]->basePoints[j].x * 10 + (int)bodies[i]->pos.x;
			bodies[i]->points[j].y = bodies[i]->basePoints[j].y * 10 + (int)bodies[i]->pos.y;
			
		}
	}
	//std::cout << bodies[0]->points[0].x << ", " << bodies[0]->points[0].y << endl;

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
			//Vec3 points = Vec3(bodies[i]->points.x, bodies[i]->points.y, bodies[i]->points.z);
			//bodies[i]->points[j] = projectionMatrix * bodies[i]->points[j];
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
#ifndef BODY_H
#define BODY_H
#include "Vector.h"
#include "SDL.h"
using namespace MATH; 

class Body {
public:
	Vec3 pos;
	Vec3 vel;
	float gravity;
private:
	Vec3 accel;
	float mass;
	SDL_Surface *bodyImage;
	
public:
	Body(char* imageName ,float mass_, Vec3 pos_, Vec3 vel_, Vec3 accel_, float gravity);
	~Body();
	void Update(const float deltaTime, const float gravity);
	void ApplyForce(Vec3 force);

	/// Just a little helper function
	SDL_Surface* getImage();
};


#endif

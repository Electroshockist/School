#version 410 core

out vec3 Position

uniform float gravity;

struct Particle{
	vec3 position;
	vec3 velocity;
	vec3 acceleration;	
}

struct Spring{
	float factor;
	Particle[2] connections;	
}

void main() {
	
}
#version 410 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec3 aTexCoord;
layout (location = 3) in vec3 aVelocity;

out vec3 Position;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
uniform mat4 normalMatrix;
uniform float gravity;

struct Spring{
	float strength;	
};

struct Particle{
	bool isLocked;

	vec3 position;
	vec3 velocity;
	vec3 acceleration;
	
	Spring[8] springs;
};

void main() {
	
}
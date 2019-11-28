#version 410 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec3 aTexCoord;
layout (location = 3) in vec3 inVelocity;
layout (location = 3) out vec3 outVelocity;
layout (location = 4) in float inLocked;

out vec3 Normal;
out vec3 Position;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
uniform mat4 normalMatrix;
uniform float gravity;
uniform float time;
uniform float deltaTime;

struct Spring{
	float strength;	
};

struct Particle{	
	Spring[8] springs;
};

vec3 tempPos = aPos;

void calculateFabric(){
	vec3 acceleration = vec3(0);
	//if(inLocked <= 0){
		acceleration.y = vec3(gravity * time).y;
		outVelocity = inVelocity + (acceleration * deltaTime);
		tempPos.y += vec3(inVelocity + (acceleration * pow(deltaTime, 2))/2).y;
	//}
}

void main() {
	calculateFabric();
	Normal = mat3(transpose(inverse(modelMatrix))) * aNormal;
    Position = vec3(modelMatrix * vec4(tempPos, 1.0));
    gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(tempPos, 1.0);
}
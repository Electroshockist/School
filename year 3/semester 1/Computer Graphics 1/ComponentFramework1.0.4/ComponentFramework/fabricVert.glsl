#version 410 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec3 aTexCoord;
layout (location = 3) in vec3 inVelocity;
layout (location = 3) out vec3 outVelocity;
layout (location = 4) in int inLocked;
//layout (location = ?) in 

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

float gravityPos;
void calculateGravity(){
		float gravityVel = (gravity * time);
		gravityPos = (gravityVel * time);
}

// void calculatefabric(){
	// vec3 acceleration = vec3(0);
	// // if(inlocked <= 0){
		 // outVelocity = inelocity + (acceleration * deltatime);
		 // temppos.y += vec3(invelocity + (acceleration * pow(deltatime, 2))/2).y;
	// //}
// }

void main() {
	if (inLocked == 0){
		//calculateFabric();
		calculateGravity();
	}
	
	vec3 tempPos = aPos;
	tempPos.y = aPos.y + gravityPos;
	Normal = mat3(transpose(inverse(modelMatrix))) * aNormal;
    Position = vec3(modelMatrix * vec4(tempPos, 1.0));
    gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(tempPos,1.0);
}
#version 410
in vec3 texCoords;
out vec4 fragColor;

uniform samplerCube skybox; 

void main() {
	vec3 invertedCoords = vec3(-texCoords.x, texCoords.y, texCoords.z);
	fragColor = texture(skybox, invertedCoords);
} 


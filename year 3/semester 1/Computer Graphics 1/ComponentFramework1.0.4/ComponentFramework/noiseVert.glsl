#version 410 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in  vec2 texCoords;

out vec3 Normal;
out vec3 Position;
out vec4 Offset;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
uniform mat4 normalMatrix;
uniform vec3 lightPos;
uniform float time;
uniform sampler3D noise3D;

void main() {
	float timeMag = 0.25;
	float posMag = 0.25;
	float peakHeaight = 0.5;
	vec3 texPos = vec3(time) * timeMag + aPos * posMag;
	vec4 noise = (normalize(texture(noise3D, texPos)) - vec4(0.5)) * peakHeaight;
	vec3 randN = aNormal * noise.xyz;
	
	Offset = noise;
	
	vec3 p = aPos + randN;
	
    Normal = mat3(transpose(inverse(modelMatrix))) * aNormal;
    Position = vec3(modelMatrix * vec4(p, 1.0));
    gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(p, 1.0);
}
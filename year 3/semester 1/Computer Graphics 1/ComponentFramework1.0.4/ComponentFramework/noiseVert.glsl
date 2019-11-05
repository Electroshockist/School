#version 410 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

out vec3 Normal;
out vec3 Position;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
uniform mat4 normalMatrix;
uniform float time;
uniform sampler3D noise3D;

void main() {
	vec3 texPos = vec3(time, time, time);
	vec4 noise = texture(noise3D, texPos);
	vec3 p = aPos + (noise.xyz * aNormal);
    Normal = mat3(transpose(inverse(modelMatrix))) * aNormal;
    Position = vec3(modelMatrix * vec4(p, 1.0));
    gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(p, 1.0);
}
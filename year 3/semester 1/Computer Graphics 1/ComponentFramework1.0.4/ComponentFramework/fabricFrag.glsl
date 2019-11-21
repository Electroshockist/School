#version 410 core
out vec4 FragColor;

in vec3 Normal;
in vec3 Position;
in vec4 Offset;

void main() {
	FragColor = vec4(texture(skybox, mixed).rgb, 1.0);
}
#version 450 core

in vec3 customColour;

out vec4 color;

void main(){
	color = vec4(customColour, 1.0f);
}

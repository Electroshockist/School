#version 450 core

in vec3 Normal;
in vec2 TexCoords;

out vec4 color;

uniform sampler2D inTexture;

void main(){
	color = vec4(inTexture, TexCoords);
}

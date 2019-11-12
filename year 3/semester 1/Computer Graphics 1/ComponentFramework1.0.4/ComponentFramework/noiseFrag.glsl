#version 410 core
out vec4 FragColor;

in vec3 Normal;
in vec3 Position;
in vec4 Offset;

uniform float time;
uniform vec3 cameraPos;
uniform samplerCube skybox;

void main()
{    
    vec3 I = normalize(Position - cameraPos);
	vec3 RL = reflect(I, normalize(Normal));
    vec3 RR = refract(I, normalize(Normal), 1.3);
	vec3 mixed = mix(RL, RR, 0.5);
	
	vec2 range = vec2(sin(time), cos(time));
	vec4 test = vec4(1);
	
	if(Position.x > range.x - 0.5 && Position.x < range.x + 0.5 && Position.y > range.y - 0.5 && Position.y < range.y + 0.5){
		test = Offset * 255;
	}
	
	
    FragColor = vec4(texture(skybox, mixed).rgb, 1.0) * test;
}
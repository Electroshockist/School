#version 410 core
out vec4 FragColor;

in vec3 Normal;
in vec3 Position;

uniform vec3 cameraPos;
uniform samplerCube skybox;

void main()
{    
    vec3 I = normalize(Position - cameraPos);
	vec3 RL = reflect(I, normalize(Normal));
    vec3 RR = refract(I, normalize(Normal), 1.3);
	vec3 mixed = mix(RL, RR, 0.5);
    FragColor = vec4(texture(skybox, mixed).rgb, 1.0);
}
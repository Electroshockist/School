#version 410
in  vec3 vertNormal;
in  vec3 lightDir;
in  vec3 vertDir;
in vec2 uvCoords;
out vec4 fragColor;

uniform sampler2D myTexture; 

void main() { 
	const float brightness = 1;
	const vec4 ks = vec4(0.6, 0.6, 0.6, 0.0);
	const vec4 kd = vec4(0.6, 0.6, 0.6, 0.0); /// const means it cannot be changed just like C++
	const vec4 ka = 0.0 * kd;
	
	float diff = max(dot(vertNormal, lightDir), 0.0);
	vec4 textureColor = texture(myTexture, uvCoords);
	vec3 reflection = normalize(reflect(lightDir, vertNormal));
	float spec = max(dot(vertDir, reflection), 0.0);
	if(diff > 0.0){
		spec = pow(spec, 900);
	}
	
	vec4 kt = 0.1 * textureColor;
	
	const vec4 tint = vec4(1,1,1,1);
	fragColor = ((ka + (diff * kd) + (spec * ks)) * tint + (diff * textureColor)) * brightness;	
} 


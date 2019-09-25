#version 410
in  vec3 vertNormal;
in  vec3 lightDir;
in  vec3 lightDir1;
in  vec3 vertDir;
in vec2 uvCoords;
out vec4 fragColor;

uniform sampler2D myTexture; 

struct Light{
	vec4 specularScale;
	vec4 kd; /// const means it cannot be changed just like C++
	vec4 ka;	
	float brightness;
};

void main() {

	Light l1 = 
		Light(
			vec4(1, 1, 1, 1),
			vec4(1, 1, 1, 1),
			vec4(1, 1, 1, 1),
			1);
			l1.ka;
			
	const vec4 ks = vec4(1.0, 0.0, 0.0, 1.0);
	const vec4 kd = vec4(1.0, 0.0, 0.0, 1.0); /// const means it cannot be changed just like C++
	const vec4 ka = 0.1 * kd;
	
	const vec4 ks1 = vec4(0.0, 0.0, 1.0, 1.0);
	const vec4 kd1 = vec4(0.0, 0.0, 1.0, 1.0); /// const means it cannot be changed just like C++
	const vec4 ka1 = 0.0 * kd1;
	
	float diff = max(dot(vertNormal, lightDir), 0.0);
	float diff1 = max(dot(vertNormal, lightDir1), 0.0);
	vec4 textureColor = texture(myTexture, uvCoords);
	vec3 reflection = normalize(reflect(lightDir, vertNormal));
	vec3 reflection1 = normalize(reflect(lightDir1, vertNormal));
	float spec = max(dot(vertDir, reflection), 0.0);
	float spec1 = max(dot(vertDir, reflection1), 0.0);
	if(diff > 0.0){
		spec = pow(spec, 900);
	}
	if(diff1 > 0.0){
		spec1 = pow(spec1, 900);
	}
	
	vec4 kt = 0.1 * textureColor;
	
	const vec4 tint = vec4(1,1,1,1);
	
	vec4 k1 = ka + (diff * kd * textureColor) + (spec * ks);
	vec4 k2 = ka + (diff1 * kd1 * textureColor) + (spec1 * ks1);
	
	fragColor = ((k1 + k2) * tint);	
} 


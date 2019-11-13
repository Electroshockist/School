// #version 450 core

// struct light{
	// vec3 pos;
	// vec3 ambient;
	// vec3 diffuse;
// }

// struct Material {
	// Sampler2D diffuseMap;
	// float shine; // ns
	// float transparency;//d

	// vec3 ambient;//ka
	// vec3 diffuse;//kd
	// vec3 specular;//ks
// };

// in vec3 Colour
// in vec3 Normal
// in vec2 TexCoords
// in vec3 Fragpos

// uniform Material material

// void main(){
	// //ambient
	// vec3 ambient = light.ambient * material.ambient * texture(material.diffuseMap,
	// TexCoords).rgb * light.lightColor;
	// //diffuse
	// vec3 norm = normalize(Normal);
	// vec3 lightDir = normalize(light.lightPos - FragPosition);
	// float diff = max(dot(norm, lightDir), 0.0);
	// vec3 diffuse = (diff * material.diffuse) * texture(material.diffuseMap, TexCoords).rgb *
	// light.lightColor;
	// //specular
	// vec3 viewDir = normalize(viewPosition-FragPosition);
	// vec3 reflectDir = reflect(-lightDir, norm);
	// float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
	// vec3 specular = (spec * material.specular) * light.lightColor;
	// vec3 result = ambient + diffuse + specular;
	// color = vec4(result, material.transparency);
// }
#version 450 core

in vec3 Normal;
in vec2 TexCoords;

out vec4 color;

uniform sampler2D inTexture;

void main(){
	color = texture(inTexture, TexCoords);
}
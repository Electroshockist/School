#ifndef MATERIALHANDLER_H
#define MATERIALHANDLER_H

#include <memory>
#include <map>
#include <glm\glm.hpp>
#include <glew.h>

struct Material {
	GLuint diffuseMap;
	float shine; // ns
	float transparency;//d

	glm::vec3 ambient;//ka
	glm::vec3 diffuse;//kd
	glm::vec3 specular;//ks

	inline Material() : diffuseMap(0), shine(0.0f), transparency(0.0f), ambient(glm::vec3(1.0f)), diffuse(glm::vec3(1.0f)), specular(glm::vec3()) {}
};

class MaterialHandler {
	static std::map<std::string, Material> materials;

public:
	void AddMaterial(const std::string& name, Material mat);
	const Material getMaterial(const std::string& name);
	void onDestroy();


	///Singleton

	static MaterialHandler * getInstance();

	//delete constructors for singleton
	MaterialHandler(const MaterialHandler&) = delete;
	MaterialHandler(MaterialHandler&&) = delete;
	MaterialHandler& operator=(const MaterialHandler&) = delete;
	MaterialHandler& operator=(MaterialHandler&&) = delete;

private:
	static std::unique_ptr<MaterialHandler> instance;
	friend std::default_delete<MaterialHandler>;
	MaterialHandler();
	~MaterialHandler();
};
#endif // !MATERIALHANDLER_H
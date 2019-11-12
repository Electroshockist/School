#include "MaterialLoader.h"


void MaterialLoader::LoadMaterial(std::string file) {
	std::ifstream in(file.c_str(), std::ios::in);
	if(!in) {
		Debug::error("Cannot open MTL file " + file, __FILE__, __LINE__);
		return;
	}
	Material m = Material();
	std::string matName = "";
	std::string line;
	while(std::getline(in, line)) {
		if(line.substr(0, 7) == "newmtl ") {
			if(m.diffuseMap != 0) {
				MaterialHandler::getInstance()->AddMaterial(matName, m);
				m = Material();
			}
			matName = line.substr(7);
			m.diffuseMap = LoadTexture(matName);
		}
	}
	if(m.diffuseMap != 0) {
		MaterialHandler::getInstance()->AddMaterial(matName, m);
	}
}


GLuint MaterialLoader::LoadTexture(std::string file) {
	GLuint currentTexture = TextureHandler::getInstance()->getTexture(file);
	if(currentTexture == 0) {
		TextureHandler::getInstance()->createTexture(file, "Resources/Textures/" + file + ".jpg");
		currentTexture = TextureHandler::getInstance()->getTexture(file);
	}
	return currentTexture;
}

MaterialLoader::~MaterialLoader() {}

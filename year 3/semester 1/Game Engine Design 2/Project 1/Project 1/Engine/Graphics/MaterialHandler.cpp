#include "MaterialHandler.h"
#include "../Core/Debug.h"

std::unique_ptr<MaterialHandler> MaterialHandler::instance = nullptr;
std::map<std::string, Material> MaterialHandler::materials = std::map<std::string, Material>();

MaterialHandler::MaterialHandler() {}


MaterialHandler::~MaterialHandler() {
	onDestroy();
}

void MaterialHandler::AddMaterial(const std::string & name, Material mat) {
	materials[name] = mat;
}

const Material MaterialHandler::getMaterial(const std::string & name) {
	if(materials.find(name) != materials.end()) {
		return materials[name];
	}
	Debug::warning("Could not find texture with name " + name, __FILE__, __LINE__);
	return Material();
}

void MaterialHandler::onDestroy() {
	if(materials.size() > 0) {
		materials.clear();
	}
}

MaterialHandler *MaterialHandler::getInstance() {
	if(instance == nullptr) {
		instance.reset(new MaterialHandler);
	}
	return instance.get();
}

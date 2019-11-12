#ifndef MATERIALLOADER_H
#define MATERIALLOADER_H

#include "../Graphics/MaterialHandler.h"
#include "../Graphics/TextureHandler.h"

class MaterialLoader {
public:
	static void LoadMaterial(std::string file);
	static GLuint LoadTexture(std::string file);

	//delete constructors for static class
	MaterialLoader(const MaterialLoader&) = delete;
	MaterialLoader(MaterialLoader&&) = delete;
	MaterialLoader& operator=(const MaterialLoader&) = delete;
	MaterialLoader& operator=(MaterialLoader&&) = delete;
	MaterialLoader() = delete;
	~MaterialLoader();
};
#endif // !MATERIALLOADER_H


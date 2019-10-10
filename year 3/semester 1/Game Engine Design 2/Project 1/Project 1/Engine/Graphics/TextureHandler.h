#ifndef TEXTUREHANDLER_H
#define TEXTUREHANDLER_H

#include <memory>
#include <string>
#include <map>
#include <SDL.h>
#include <SDL_image.h>
#include <glew.h>

#include "../Core/Debug.h"

struct Texture {
	GLuint textureID;
	float width = 0.0f;
	float height = 0.0f;
};

class TextureHandler {

	TextureHandler();
	~TextureHandler();

	static std::unique_ptr<TextureHandler> textureInstance;
	friend std::default_delete<TextureHandler>;
	static std::map<std::string, Texture*> textures;

public:
	//delete constructors for singleton
	TextureHandler(const TextureHandler&) = delete;
	TextureHandler(TextureHandler&&) = delete;
	TextureHandler& operator=(const TextureHandler&) = delete;
	TextureHandler& operator=(TextureHandler&&) = delete;

	void createTexture(const std::string& textureName, const std::string& textureFileName);
	static const GLuint getTexture(const std::string& textureName);
	static const Texture* getTextureData(const std::string& textureName);


	void onDestroy();

	static TextureHandler* getInstance();
};
#endif // !TEXTUREHANDLER_H


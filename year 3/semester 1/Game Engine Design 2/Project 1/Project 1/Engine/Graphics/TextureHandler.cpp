#include "TextureHandler.h"

std::unique_ptr<TextureHandler> TextureHandler::textureInstance = nullptr;
std::map<std::string, Texture*> TextureHandler::textures = std::map<std::string, Texture*>();

TextureHandler::TextureHandler() {}


TextureHandler::~TextureHandler() {
	//onDestroy();
}

void TextureHandler::onDestroy() {	
	if(textures.size() > 0) {
		for(auto t : textures) {
			glDeleteTextures(1, &t.second->textureID);
			delete t.second;
			t.second = nullptr;
		}
	}
	textures.clear();
}

TextureHandler * TextureHandler::getInstance() {
	if(textureInstance == nullptr) {
		textureInstance.reset(new TextureHandler);
	}
	return textureInstance.get();
}

void TextureHandler::createTexture(const std::string & textureName, const std::string & textureFileName) {
	Texture* t = new Texture;
	SDL_Surface* surface = nullptr;

	try {
		surface = IMG_Load(textureFileName.c_str());
	}
	catch(const std::exception e) {
		Debug::error("Failed to load texture " + textureFileName, __FILE__, __LINE__);
		return;
	}
	t->width = static_cast<float>(surface->w);
	t->height = static_cast<float>(surface->h);

	glGenTextures(1, &t->textureID);
	glBindTexture(GL_TEXTURE_2D, t->textureID);
	int mode = surface->format->BytesPerPixel == 4 ? GL_RGBA : GL_RGB;
	glTexImage2D(GL_TEXTURE_2D, 0, mode, surface->w, surface->h, 0, mode, GL_UNSIGNED_BYTE, surface->pixels);

	//texture wrapping
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	//mipmapping
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glGenerateMipmap(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, 0);
	textures[textureName] = t;
	SDL_FreeSurface(surface);
	surface = nullptr;
}

const GLuint TextureHandler::getTexture(const std::string & textureName) {
	if(textures.find(textureName) != textures.end()) {
		return textures[textureName]->textureID;
	}
	return 0;
}

const Texture * TextureHandler::getTextureData(const std::string & textureName) {
	if(textures.find(textureName) != textures.end()) {
		return textures[textureName];
	}
	return nullptr;
}

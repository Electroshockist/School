#include "SkyBox.h"

#include <SDL_image.h>
#include "Mesh.h"
#include "ObjLoader.h"

SkyBox::SkyBox(){
	onCreate();
}


SkyBox::~SkyBox(){

}

bool SkyBox::onCreate(){
	if(ObjLoader::loadOBJ("cube.obj") == false){
		return false;
	}
	mesh = new Mesh(GL_TRIANGLES, ObjLoader::vertices, ObjLoader::normals, ObjLoader::uvCoords);
	ObjLoader::loadOBJ(nullptr);
	return true;
}

bool SkyBox::LoadImage(std::vector<char*>* faces){
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	SDL_Surface * textureSurfaces[6];
	for(int i = faces->size(); i > 0; i--){
		textureSurfaces[i] = IMG_Load(faces->at(i));

		if(textureSurfaces[i] == nullptr){
			return false;
		}
		int mode = (textureSurfaces[i]->format->BytesPerPixel == 4) ? GL_RGBA : GL_RGB;
		glTexImage2D(GL_TEXTURE_2D, 0, mode, textureSurfaces[i]->w, textureSurfaces[i]->h, 0, mode, GL_UNSIGNED_BYTE, textureSurfaces[i]->pixels);
		SDL_FreeSurface(textureSurfaces[i]);
	}

	/// Wrapping and filtering options
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0); /// Unbind the texture
	return true;
}

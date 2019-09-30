//#include "SkyBox.h"
//
//#include <SDL_image.h>
//#include "ObjLoader.h"
//#include "Mesh.h"
//#include "Shader.h"
//
//SkyBox::SkyBox() {
//	onCreate();
//}
//
//
//SkyBox::~SkyBox() {
//
//}
//
//bool SkyBox::onCreate() {
//	glGenTextures(1, &textureID);
//	glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
//
//	LoadTextures("CN Tower/posx.jpg", "CN Tower/negx.jpg", "CN Tower/negx.jpg", "CN Tower/negx.jpg", "CN Tower/negx.jpg", "CN Tower/negx.jpg");
//
//	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
//
//	//unbind texture
//	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
//
//	if(!ObjLoader::loadOBJ("cube.obj")) {
//		return false;
//	}
//	mesh = new Mesh(GL_TRIANGLES, ObjLoader::vertices, ObjLoader::normals, ObjLoader::uvCoords);
//	shader = new Shader("skyVert", "skyFrag");
//
//	return true;
//}
//
//void SkyBox::Render() const {
//
//}
//
//bool SkyBox::LoadTextures(const char * posX, const char * negX, const char * posY, const char * negY, const char * posZ, const char * negZ) {
//	//posX
//	SDL_Surface *textureSurface = IMG_Load(posX);
//	if(textureSurface == nullptr) {
//		return false;
//	}
//	int mode = (textureSurface->format->BytesPerPixel == 4) ? GL_RGBA : GL_RGB;
//	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, mode, textureSurface->w, textureSurface->h, 0, mode, GL_UNSIGNED_BYTE, textureSurface->pixels);
//	SDL_FreeSurface(textureSurface);
//	//negX
//	textureSurface = IMG_Load(negX);
//	if(textureSurface == nullptr) {
//		return false;
//	}
//	mode = (textureSurface->format->BytesPerPixel == 4) ? GL_RGBA : GL_RGB;
//	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, mode, textureSurface->w, textureSurface->h, 0, mode, GL_UNSIGNED_BYTE, textureSurface->pixels);
//	SDL_FreeSurface(textureSurface);
//
//	//posY
//	textureSurface = IMG_Load(posY);
//	if(textureSurface == nullptr) {
//		return false;
//	}
//	mode = (textureSurface->format->BytesPerPixel == 4) ? GL_RGBA : GL_RGB;
//	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, mode, textureSurface->w, textureSurface->h, 0, mode, GL_UNSIGNED_BYTE, textureSurface->pixels);
//	SDL_FreeSurface(textureSurface);
//
//	//negY
//	textureSurface = IMG_Load(negY);
//	if(textureSurface == nullptr) {
//		return false;
//	}
//	mode = (textureSurface->format->BytesPerPixel == 4) ? GL_RGBA : GL_RGB;
//	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, mode, textureSurface->w, textureSurface->h, 0, mode, GL_UNSIGNED_BYTE, textureSurface->pixels);
//	SDL_FreeSurface(textureSurface);
//	//posZ
//	textureSurface = IMG_Load(posZ);
//	if(textureSurface == nullptr) {
//		return false;
//	}
//	mode = (textureSurface->format->BytesPerPixel == 4) ? GL_RGBA : GL_RGB;
//	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, mode, textureSurface->w, textureSurface->h, 0, mode, GL_UNSIGNED_BYTE, textureSurface->pixels);
//	SDL_FreeSurface(textureSurface);
//
//	//negZ
//	textureSurface = IMG_Load(negZ);
//	if(textureSurface == nullptr) {
//		return false;
//	}
//	mode = (textureSurface->format->BytesPerPixel == 4) ? GL_RGBA : GL_RGB;
//	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, mode, textureSurface->w, textureSurface->h, 0, mode, GL_UNSIGNED_BYTE, textureSurface->pixels);
//	SDL_FreeSurface(textureSurface);
//
//	return true;
//}
//

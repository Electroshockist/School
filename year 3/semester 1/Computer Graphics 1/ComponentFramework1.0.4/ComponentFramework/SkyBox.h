#ifndef SKYBOX_H
#define SKYBOX_H
#include <glew.h>
#include <vector>

class Mesh;

class SkyBox {
	GLuint textureID;
	Mesh* mesh;
public:
	SkyBox();
	~SkyBox();
	bool onCreate();
	bool LoadImage(std::vector<char*>* faces);
	inline GLuint getTextureID() const { return textureID; }
};
#endif // !SKYBOX_H


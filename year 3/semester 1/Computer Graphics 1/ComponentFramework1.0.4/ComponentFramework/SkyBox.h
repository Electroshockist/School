#ifndef SKYBOX_H
#define SKYBOX_H
#include <glew.h>
#include "Matrix.h"

class Shader;
class SkyBox {
	GLuint textureID, VAO, modelMatrixID;
	class Mesh* mesh;
	Shader* shader;

	MATH::Matrix4 modelMatrix;

public:
	SkyBox();
	~SkyBox();
	bool onCreate();
	void onDestroy();
	void Render() const;
	inline GLuint getTextureID() const { return textureID; }
	inline Shader* getShader() const { return shader; }

	bool LoadTextures(const char * posX, const char * negX, const char * posY, const char * negY, const char * posZ, const char * negZ);

};
#endif // !SKYBOX_H


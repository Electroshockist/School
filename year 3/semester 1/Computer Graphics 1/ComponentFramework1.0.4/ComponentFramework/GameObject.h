#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <glew.h>
#include "Matrix.h"
using namespace MATH;
class GameObject {
	
private:
	Matrix4 modelMatrix;
	GLuint modelMatrixID;
	GLuint normalMatrixID;
	class ARenderable *renderable;
	class Shader *shader;
	class Texture *texture;
public:
	GameObject(ARenderable *renderable, Shader *shader_, Texture *texture_);
	~GameObject();
	void Render() const;
	void Update(float deltaTime_);
	inline Shader* getShader() const { return shader; }
	inline void setModelMatrix(const Matrix4 &modelMatrix_) { modelMatrix = modelMatrix_; }
	inline Matrix4& getModelMatrix() { return modelMatrix; }
};

#endif


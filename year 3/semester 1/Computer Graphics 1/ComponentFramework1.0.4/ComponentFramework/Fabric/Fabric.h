#ifndef FABRIC_H
#define FABRIC_H

#include "../ARenderable.h"
#include "Particle.h"
#include <glew.h>

class Shader;
class Fabric : public ARenderable{
public:
	Particle particle;

	std::vector<Particle> particles;
	Fabric() {}

	Fabric(GLenum drawmode, std::vector<Vec3>&, std::vector<Vec3>&, std::vector<Vec2>&);

	~Fabric();

	void update(const float deltaTime);

	Shader* getShader() const;

private:
	virtual void setup() override;

	Shader* shader;

	GLuint offset = 0;
	GLuint id = 0;

	void addVertexAttrib(const GLuint size, const void* data, const GLuint count, const GLuint type);

};


//class Fabric : public Mesh{
//public:
//	
//	std::vector<GLubyte> locks;
//	std::vector<Vec3> velocities;
//
//	Fabric(GLenum drawmode, std::vector<Vec3>&, std::vector<Vec3>&, std::vector<Vec2>&, std::vector<Vec3>* velocities = nullptr, std::vector<GLubyte>* locks = nullptr);
//	virtual ~Fabric() {};
//
//	Shader* getShader() const;
//
//private:
//	void setupMesh() override;
//	std::shared_ptr<Shader> shader;
//
//	GLuint offset = 0;
//	GLuint id = 0;
//
//	void addVertexAttrib(const GLuint size, const void* data, const GLuint count, const GLuint type);
//};
#endif // !FABRIC_H
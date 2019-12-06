#ifndef FABRIC_H
#define FABRIC_H

//#include "Mesh.h"
//#include "Shader.h"
//#include <memory>
#include "Vector.h"
#include "Mesh.h"
#include <vector>

using namespace MATH;

struct Particle;
struct Spring {
	Particle* connectedParticles[2];
	float strength;
	Spring() {}
	Spring(float strength, Particle* p1, Particle* p2);
};

struct Particle {
	Vec3* position;
	Vec3 velocity, acceleration;
	float mass;
	bool isLocked = false;

	std::vector<Spring> attachedSprings;

	Particle() {}

	Particle(Vec3& position, float mass);

	inline void update(const float deltaTime);

	inline void addForce(const Vec3 force) {
		acceleration = force / mass;
	}

	void connectTo(Particle* particle);
};


class Shader;
class Fabric {
public:
	Particle particle;

	std::vector<Particle> particles;

	GLenum drawmode;
	std::vector<Vec3> vertices;
	std::vector<Vec3> normals;
	std::vector<Vec2> uvCoords;
	std::vector<GLuint> indices;
	Fabric() {}

	Fabric(GLenum drawmode, std::vector<Vec3>&, std::vector<Vec3>&, std::vector<Vec2>&);

	~Fabric();

	void update(const float deltaTime);

	void Render() const;

	Shader* getShader() const;

private:
	GLuint vao, vbo;
	virtual void setupMesh();

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
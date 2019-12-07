#include "Fabric.h"
#include "../Shader.h"
#include <algorithm>

//Fabric::Fabric(GLenum drawmode_, std::vector<Vec3> &vertices, std::vector<Vec3> &normals_, std::vector<Vec2> &uvCoords_,std::vector<Vec3>* velocities, std::vector<GLubyte>* locks) {
//	drawmode = drawmode_;
//	this->vertices = vertices;
//	this->normals = normals_;
//	this->uvCoords = uvCoords_;
//	if(velocities == nullptr) {
//		for(size_t i = 0; i < vertices.size(); i++) {
//			this->velocities.push_back(Vec3());
//		}
//	}
//	if(locks == nullptr) {
//		for(size_t i = 0; i < vertices.size(); i++) {
//			this->locks.push_back(0);
//		}
//	}
//
//	shader.reset(new Shader("fabricVert.glsl", "fabricFrag.glsl"));
//	this->setupMesh();
//}
//
//void Fabric::setupMesh() {
//#define VERTEX_LENGTH 	(vertices.size() * (sizeof(Vec3)))
//#define VELOCITY_LENGTH (velocities.size() * (sizeof(Vec3)))
//#define NORMAL_LENGTH 	(normals.size() * (sizeof(Vec3)))
//#define TEXCOORD_LENGTH (uvCoords.size() * (sizeof(Vec2)))
//#define LOCK_LENGTH (locks.size() * (sizeof(GLbyte)))
//
//	/// create and bind the VOA
//	glGenVertexArrays(1, &vao);
//	glBindVertexArray(vao);
//	/// Create and initialize vertex buffer object VBO
//	glGenBuffers(1, &vbo);
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	glBufferData(GL_ARRAY_BUFFER, VERTEX_LENGTH + VELOCITY_LENGTH + NORMAL_LENGTH + TEXCOORD_LENGTH + LOCK_LENGTH, NULL, GL_STATIC_DRAW);
//	
//	/// assigns the addr of "points" to be the beginning of the array buffer "sizeof(points)" in length
//	addVertexAttrib(VERTEX_LENGTH, &vertices[0], 3, GL_FLOAT);	
//	/// assigns the addr of "normals" to be "sizeof(points)" offset from the beginning and "sizeof(normals)" in length 
//	addVertexAttrib(NORMAL_LENGTH, &normals[0], 3, GL_FLOAT);	
//	/// assigns the addr of "texCoords" to be "sizeof(points) + sizeof(normals)" offset from the beginning and "sizeof(texCoords)" in length
//	addVertexAttrib(TEXCOORD_LENGTH, &uvCoords[0], 2, GL_FLOAT);	
//	/// assigns the addr of "velicities" to be "sizeof(points) + sizeof(normals) + sizeof(uvCoords)" offset from the beginning and "sizeof(texCoords)" in length  
//	addVertexAttrib(VELOCITY_LENGTH, &velocities[0], 3, GL_FLOAT);
//
//	addVertexAttrib(LOCK_LENGTH, &locks[0], 1, GL_BYTE);
//
//#undef VERTEX_LENGTH
//#undef VELOCITY_LENGTH
//#undef NORMAL_LENGTH
//#undef TEXCOORD_LENGTH
//#undef LOCK_LENGTH
//}

void Fabric::addVertexAttrib(const GLuint size, const void* data, const GLuint count, const GLuint type) {
	glBufferSubData(GL_ARRAY_BUFFER, offset, size, data);
	glEnableVertexAttribArray(id);
	glVertexAttribPointer(id, count, type, GL_FALSE, 0, reinterpret_cast<void*>(offset));
	offset += size;
	id++;
}

Shader * Fabric::getShader() const {
	return shader;
}

void Fabric::setup() {}

Fabric::Fabric(GLenum drawmode, std::vector<Vec3>& vertices, std::vector<Vec3>& normals, std::vector<Vec2>& texPos) {
	for(size_t i = 0; i < vertices.size(); i++) {
		particles.push_back(Particle(vertices.at(i), 1.0f));
	}
	particles.at(0).isLocked = true;
	Vec3 t = Vec3();
	particle = Particle(t, 1.0f);

	shader = new Shader("fabricVert.glsl", "fabricFrag.glsl");
	this->setup();
}

Fabric::~Fabric() {
	delete shader;
	shader = nullptr;
}

void Fabric::update(const float deltaTime) {
	particle.update(deltaTime);
	std::cout << particles.size() << std::endl;
	for(Particle& p : particles) {
		p.update(deltaTime);
	}
}

#include "Fabric.h"
#include "../Shader.h"
#include <algorithm>

using namespace std;
using namespace MATH;

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

//Fabric::Fabric(GLuint size, GLuint divisions) {
//	vector<Vec3> v, n;
//	vector<Vec2> uv;
//
//	const GLuint nodeDistance = size / divisions;
//
//	for(int i = divisions - 1; i >= 0; i--) {
//		for(int j = divisions - 1; j >= 0; j--) {
//			v.push_back(Vec3(nodeDistance * i, nodeDistance * j, size));
//			n.push_back(Vec3(1, 0, size));
//
//			Vec2 tempUV;
//			tempUV.x = nodeDistance * i;
//			tempUV.y = nodeDistance * j;
//			uv.push_back(tempUV);
//		}
//	}
//}

Fabric::Fabric(GLenum drawmode, std::vector<Vec3>& vertices, std::vector<Vec3>& normals, std::vector<Vec2>& uvCoords, std::vector<Face>& faces) {
	this->drawmode = drawmode;
	this->vertices = vertices;
	this->normals = normals;
	this->uvCoords = uvCoords;

	this->velocities = std::vector<Vec3>();
	this->locks = std::vector<GLubyte>();

	for(size_t i = 0; i < vertices.size(); i++) {
		particles.push_back(Particle(&vertices[i], 1.0f));
		velocities.push_back(Vec3());
		locks.push_back(false);
	}

	setupSprings(faces);
	this->setup();
}

Fabric::~Fabric() {
	delete shader;
	shader = nullptr;
}

void Fabric::setupSprings(std::vector<Face>& faces) {
	for(size_t i = 0; i < faces.size(); i++) {
		std::cout << "Face " << i + 1 << std::endl;
		connectFace(faces[i]);
	}

	particles[0].isLocked = true;

	shader = new Shader("textureVert.glsl", "textureFrag.glsl");
}

void Fabric::setup() {
#define VERTEX_LENGTH 	(vertices.size() * (sizeof(Vec3)))
#define VELOCITY_LENGTH (velocities.size() * (sizeof(Vec3)))
#define NORMAL_LENGTH 	(normals.size() * (sizeof(Vec3)))
#define TEXCOORD_LENGTH (uvCoords.size() * (sizeof(Vec2)))
#define LOCK_LENGTH (locks.size() * (sizeof(GLbyte)))

	/// create and bind the VOA
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	/// Create and initialize vertex buffer object VBO
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, VERTEX_LENGTH + VELOCITY_LENGTH + NORMAL_LENGTH + TEXCOORD_LENGTH + LOCK_LENGTH, NULL, GL_DYNAMIC_DRAW);

	loadVertexAttribs();

#undef VERTEX_LENGTH
#undef VELOCITY_LENGTH
#undef NORMAL_LENGTH
#undef TEXCOORD_LENGTH
#undef LOCK_LENGTH
}

void Fabric::loadVertexAttribs() {
#define VERTEX_LENGTH 	(vertices.size() * (sizeof(Vec3)))
#define VELOCITY_LENGTH (velocities.size() * (sizeof(Vec3)))
#define NORMAL_LENGTH 	(normals.size() * (sizeof(Vec3)))
#define TEXCOORD_LENGTH (uvCoords.size() * (sizeof(Vec2)))
#define LOCK_LENGTH (locks.size() * (sizeof(GLbyte)))
	/// assigns the addr of "points" to be the beginning of the array buffer "sizeof(points)" in length
	addVertexAttrib(VERTEX_LENGTH, &vertices[0], 3, GL_FLOAT);
	/// assigns the addr of "normals" to be "sizeof(points)" offset from the beginning and "sizeof(normals)" in length 
	addVertexAttrib(NORMAL_LENGTH, &normals[0], 3, GL_FLOAT);
	/// assigns the addr of "texCoords" to be "sizeof(points) + sizeof(normals)" offset from the beginning and "sizeof(texCoords)" in length
	addVertexAttrib(TEXCOORD_LENGTH, &uvCoords[0], 2, GL_FLOAT);
	/// assigns the addr of "velicities" to be "sizeof(points) + sizeof(normals) + sizeof(uvCoords)" offset from the beginning and "sizeof(texCoords)" in length  
	//addVertexAttrib(VELOCITY_LENGTH, &velocities[0], 3, GL_FLOAT);

	//addVertexAttrib(LOCK_LENGTH, &locks[0], 1, GL_BYTE);

	offset = 0;
	id = 0;
#undef VERTEX_LENGTH
#undef VELOCITY_LENGTH
#undef NORMAL_LENGTH
#undef TEXCOORD_LENGTH
#undef LOCK_LENGTH
}

void Fabric::addVertexAttrib(const GLuint size, const void* data, const GLuint count, const GLuint type) {
	glBufferSubData(GL_ARRAY_BUFFER, offset, size, data);
	glEnableVertexAttribArray(id);
	glVertexAttribPointer(id, count, type, GL_FALSE, 0, reinterpret_cast<void*>(offset));
	offset += size;
	id++;
}

void Fabric::connectFace(Face& f) {
	for(size_t i = 0; i < 2; i++) {
		std::cout << "\tConnected [" << f.vertexIndices[i] + 1 << "]: ";
		particles.at(f.vertexIndices[i]).position->print();
		std::cout << " to\n";

		for(size_t j = i + 1; j < 3; j++) {
			std::cout << "\t\t  [" << f.vertexIndices[j] + 1 << "]: ";
			particles.at(f.vertexIndices[j]).position->print();
			std::cout << "\n";

			Spring* spring = new Spring(1, &particles.at(f.vertexIndices[i]), &particles.at(f.vertexIndices[j]));
		}
		std::cout << "\n";
	}
}

Shader* Fabric::getShader() const {
	return shader;
}

void Fabric::update(const float deltaTime) {
	for(Particle& p : particles) {
		p.update(deltaTime);
	}
	loadVertexAttribs();
}



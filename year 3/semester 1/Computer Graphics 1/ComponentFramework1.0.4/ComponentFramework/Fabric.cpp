#include "Fabric.h"
using namespace MATH;

Fabric::Fabric(GLenum drawmode, std::vector<Vec3>& vertices, std::vector<Vec3>& normals, std::vector<Vec2>& uvCoords, std::vector<Vec3>* velocities = nullptr, std::vector<bool> locks = std::vector<bool>(false)) {
	drawmode = drawmode;
	this->vertices = vertices;
	this->normals = normals;
	this->uvCoords = uvCoords;

	if(velocities == nullptr)
		velocities = new std::vector<Vec3>(vertices.size());


	shader.reset(new Shader("fabricVert.glsl", "fabricFrag.glsl"));
	this->setupMesh();
}

Shader * Fabric::getShader() const {
	return shader.get();
}

void Fabric::setupMesh() {
#define VERTEX_LENGTH 	(vertices.size() * (sizeof(Vec3)))
#define VELOCITY_LENGTH (velocities.size() * (sizeof(Vec3)))
#define NORMAL_LENGTH 	(normals.size() * (sizeof(Vec3)))
#define TEXCOORD_LENGTH (uvCoords.size() * (sizeof(Vec2)))
#define LOCK_LENGTH (locks.size() * (sizeof(bool)))

	const int verticiesID = 0;
	const int normalsID = 1;
	const int uvCoordsID = 2;
	const int velocitiesID = 3;
	const int locksID = 4;

	/// create and bind the VOA
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	/// Create and initialize vertex buffer object VBO
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, VERTEX_LENGTH + VELOCITY_LENGTH + NORMAL_LENGTH + TEXCOORD_LENGTH + LOCK_LENGTH, NULL, GL_STATIC_DRAW);

	/// assigns the addr of "points" to be the beginning of the array buffer "sizeof(points)" in length
	glBufferSubData(GL_ARRAY_BUFFER, 0, VERTEX_LENGTH, &vertices[0]);
	/// assigns the addr of "normals" to be "sizeof(points)" offset from the beginning and "sizeof(normals)" in length  
	glBufferSubData(GL_ARRAY_BUFFER, VERTEX_LENGTH, NORMAL_LENGTH, &normals[0]);
	/// assigns the addr of "texCoords" to be "sizeof(points) + sizeof(normals)" offset from the beginning and "sizeof(texCoords)" in length  
	glBufferSubData(GL_ARRAY_BUFFER, VERTEX_LENGTH + NORMAL_LENGTH, TEXCOORD_LENGTH, &uvCoords[0]);
	/// assigns the addr of "velicities" to be "sizeof(points) + sizeof(normals) + sizeof(uvCoords)" offset from the beginning and "sizeof(texCoords)" in length  
	glBufferSubData(GL_ARRAY_BUFFER, VERTEX_LENGTH + NORMAL_LENGTH + TEXCOORD_LENGTH, VELOCITY_LENGTH, &velocities[0]);

	glBufferSubData(GL_ARRAY_BUFFER, VERTEX_LENGTH + NORMAL_LENGTH + TEXCOORD_LENGTH + VELOCITY_LENGTH, LOCK_LENGTH, &locks[0]);

	glEnableVertexAttribArray(verticiesID);
	glVertexAttribPointer(verticiesID, 3, GL_FLOAT, GL_FALSE, 0, reinterpret_cast<void*>(0));
	glEnableVertexAttribArray(normalsID);
	glVertexAttribPointer(normalsID, 3, GL_FLOAT, GL_FALSE, 0, reinterpret_cast<void*>(VERTEX_LENGTH));
	glEnableVertexAttribArray(uvCoordsID);
	glVertexAttribPointer(uvCoordsID, 2, GL_FLOAT, GL_FALSE, 0, reinterpret_cast<void*>(VERTEX_LENGTH + NORMAL_LENGTH));
	glEnableVertexAttribArray(velocitiesID);
	glVertexAttribPointer(velocitiesID, 2, GL_FLOAT, GL_FALSE, 0, reinterpret_cast<void*>(VERTEX_LENGTH + NORMAL_LENGTH + TEXCOORD_LENGTH));
	glEnableVertexAttribArray(locksID);
	glVertexAttribIPointer(locksID, 1, GL_UNSIGNED_BYTE, 0, reinterpret_cast<void*>(VERTEX_LENGTH + NORMAL_LENGTH + TEXCOORD_LENGTH + VELOCITY_LENGTH));

#undef VERTEX_LENGTH
#undef VELOCITY_LENGTH
#undef NORMAL_LENGTH
#undef TEXCOORD_LENGTH
#undef LOCK_LENGTH
}

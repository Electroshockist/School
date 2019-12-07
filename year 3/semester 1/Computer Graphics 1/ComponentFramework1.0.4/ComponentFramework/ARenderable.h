#ifndef ARENDERABLE_H
#define ARENDERABLE_H


#include "Vector.h"
#include <glew.h>
#include <vector>

using namespace MATH;

struct ARenderable {
	virtual ~ARenderable() {}
	
	GLenum drawmode;
	std::vector<Vec3> vertices;
	std::vector<Vec3> normals;
	std::vector<Vec2> uvCoords;
	std::vector<GLuint> indices;

	inline void Render() const {
		glBindVertexArray(vao);
		glDrawArrays(drawmode, 0, vertices.size());
		glBindVertexArray(0); // Disable the VAO
	};

protected:

	GLuint vao, vbo;
	virtual void setup() = 0;
	
	ARenderable() {}
};


#endif // !ARENDERABLE_H

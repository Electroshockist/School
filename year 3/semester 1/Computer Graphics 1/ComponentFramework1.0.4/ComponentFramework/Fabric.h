#ifndef FABRIC_H
#define FABRIC_H

#include "Mesh.h"
#include "Shader.h"
#include <memory>

class Fabric {
public:
	GLenum drawmode;

	Fabric(GLenum drawmode, std::vector<Vec3>& verticies, std::vector<Vec3>& normals, std::vector<Vec2>& uvCoords, std::vector<Vec3> *velocities, std::vector<bool> locks);
	~Fabric() {
		glDeleteBuffers(1, &vbo);
		glDeleteVertexArrays(1, &vao);
	};

	Shader* getShader() const;

private:
	void setupMesh();
	std::shared_ptr<Shader> shader;

	std::vector<Vec3> vertices;
	std::vector<Vec3> normals;
	std::vector<Vec2> uvCoords;
	std::vector<GLuint> indices;
	std::vector<Vec3> velocities;
	std::vector<float> locks;

	void Render() const;
	GLuint vao, vbo;
	void setupMesh();
};
#endif // !FABRIC_H


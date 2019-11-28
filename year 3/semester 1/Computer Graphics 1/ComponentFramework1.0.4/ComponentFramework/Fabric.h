#ifndef FABRIC_H
#define FABRIC_H

#include "Mesh.h"
#include "Shader.h"
#include <memory>

class Fabric : public Mesh{
public:
	
	std::vector<float> locks;
	std::vector<Vec3> velocities;

	Fabric(GLenum drawmode_, std::vector<Vec3>&, std::vector<Vec3>&, std::vector<Vec2>&);
	virtual ~Fabric() {};

	Shader* getShader() const;

private:
	void setupMesh();
	std::shared_ptr<Shader> shader;
};
#endif // !FABRIC_H


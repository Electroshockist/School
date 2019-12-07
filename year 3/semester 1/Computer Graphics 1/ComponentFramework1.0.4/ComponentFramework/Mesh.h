#ifndef MESH_H
#define MESH_H
#include <Vector>
#include <glew.h>
#include "Vector.h"
#include "ARenderable.h"

using namespace MATH;

struct Mesh : public ARenderable {
	Mesh(GLenum drawmode_, std::vector<Vec3>&, std::vector<Vec3>&, std::vector<Vec2>&);
	virtual ~Mesh();

protected:
	Mesh(){ }
	virtual void setup() override;
};

#endif
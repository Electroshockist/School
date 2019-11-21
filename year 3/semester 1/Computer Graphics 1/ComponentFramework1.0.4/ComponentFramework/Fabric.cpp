#include "Fabric.h"
#include "Shader.h"

Fabric::Fabric(Mesh * mesh) {
	this->mesh = mesh;
	shader = new Shader("fabricVert.glsl", "fabricFrag.glsl");
}


Fabric::~Fabric() {}

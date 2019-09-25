#ifndef MODEL_H
#define MODEL_H

#include "Mesh.h"

class Model {
public:
	Model(GLuint shaderProgram);
	~Model();
	void AddMesh(Mesh* mesh_);
	void Render();
	void OnDestroy();
private:
	GLuint shaderProgram;
	std::vector<Mesh*> subMeshes;
};
#endif // !MODEL_H



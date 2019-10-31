#ifndef LOADOBJMODEL_H
#define LOADOBJMODEL_H

#include "Mesh.h"
#include "../../Graphics/TextureHandler.h"

#include <sstream>

struct LoadObjModel {
	LoadObjModel();
	~LoadObjModel();

	void OnDestroy();
	void loadModel(const std::string& fileName);
	void loadModel(const std::string& fileName, const std::string& matName);
	std::vector<Vertex> getVerts();
	std::vector<int> getIndecies();
	std::vector<SubMesh> getSubMeshes();

private:
	std::vector<glm::vec3> vertices, normals;
	std::vector<glm::vec2> textureCoords;
	std::vector<int> indices, normalIndices, textureIndices;
	std::vector<Vertex> meshVerticies;
	std::vector<SubMesh> meshes;
	void postProcessing();
	void loadMaterial(const std::string& fileName);
	void loadMaterialLibrary(const std::string& matName);
	GLuint currentTexture;
};
#endif // LOADOBJMODEL_H


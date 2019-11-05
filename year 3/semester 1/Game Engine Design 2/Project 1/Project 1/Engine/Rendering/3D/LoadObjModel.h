#ifndef LOADOBJMODEL_H
#define LOADOBJMODEL_H

#include "Mesh.h"
#include "../../Graphics/TextureHandler.h"

#include <memory>
#include <sstream>

struct LoadObjModel {
	struct Face {
		struct Point {
			int vertex, textureCoord, normal;
			Point() {}
			Point(int vertex, int textureCoord, int normal) {
				this->vertex = vertex;
				this->textureCoord = textureCoord;
				this->normal = normal;
			}
		};
		
		Point p[3];
		Face() {}
		Face(Point one, Point two, Point three) {
			p[0] = one;
			p[1] = two;
			p[2] = three;
		}
	};

	LoadObjModel();
	~LoadObjModel();

	void OnDestroy();
	void loadModel(const std::string& fileName);
	void loadModel(const std::string& fileName, const std::string& matName);
	std::vector<Vertex> getVerts();
	std::vector<int> getIndices();
	std::vector<SubMesh> getSubMeshes();

private:
	std::vector<glm::vec3> vertices, normals;
	std::vector<glm::vec2> textureCoords;
	std::vector<int> indices, normalIndices, textureIndices;
	std::vector<Vertex> meshVertices;
	std::vector<SubMesh> meshes;
	void postProcessing();
	void loadMaterial(const std::string& fileName);
	void loadMaterialLibrary(const std::string& matName);
	GLuint currentTexture;

	Face::Point getIndicesFromString(std::string s);
	void pushFaceToVectors(Face f);
};
#endif // LOADOBJMODEL_H


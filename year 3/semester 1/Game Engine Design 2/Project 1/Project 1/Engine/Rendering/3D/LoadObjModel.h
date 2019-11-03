#ifndef LOADOBJMODEL_H
#define LOADOBJMODEL_H

#include "Mesh.h"
#include "../../Graphics/TextureHandler.h"

#include <memory>
#include <sstream>

struct LoadObjModel {
	struct Face {
		struct Point {
			std::shared_ptr<glm::vec3> vertex;
			std::shared_ptr<glm::vec2> textureCoord;
			std::shared_ptr<glm::vec3> normal;
			Point() {}
			Point(glm::vec3 vertex, glm::vec2 textureCoord, glm::vec3 normal) {
				this->vertex.reset(&vertex);
				this->textureCoord.reset(&textureCoord);
				this->normal.reset(&normal);
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
	std::vector<int> getIndecies();
	std::vector<SubMesh> getSubMeshes();

private:
	std::vector<glm::vec3> vertices, normals;
	std::vector<glm::vec2> textureCoords;
	std::vector<Face> faces;
	std::vector<int> indices, normalIndices, textureIndices, faceIndices;
	std::vector<Vertex> meshVerticies;
	std::vector<SubMesh> meshes;
	void postProcessing();
	void loadMaterial(const std::string& fileName);
	void loadMaterialLibrary(const std::string& matName);
	GLuint currentTexture;

	Face::Point getIndicesFromString(std::string s);
};
#endif // LOADOBJMODEL_H


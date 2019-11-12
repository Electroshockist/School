#include "LoadObjModel.h"
#include <algorithm>
#include <iostream>

LoadObjModel::LoadObjModel() : material(Material()) {}

LoadObjModel::~LoadObjModel() {
	OnDestroy();
}

void LoadObjModel::OnDestroy() {
	vertices.clear();
	normals.clear();
	textureCoords.clear();
	indices.clear();
	normalIndices.clear();
	textureIndices.clear();
	meshVertices.clear();
	meshes.clear();
}

void LoadObjModel::loadModel(const std::string & fileName) {
	std::ifstream in(fileName.c_str(), std::ios::in);
	if(!in) {
		Debug::error("Could not load Obj file " + fileName, __FILE__, __LINE__);
		return;
	}
	std::string line;
	while(std::getline(in, line)) {
		//vetex indecies
		if(line.substr(0, 2) == "v ") {
			std::istringstream v(line.substr(2));
			glm::vec3 vert;
			double x, y, z;
			v >> x >> y >> z;
			vert = glm::vec3(x, y, z);
			vertices.push_back(vert);
		}

		//normal data
		if(line.substr(0, 3) == "vn ") {
			std::istringstream vn(line.substr(3));
			glm::vec3 norm;
			double x, y, z;
			vn >> x >> y >> z;
			norm = glm::vec3(x, y, z);
			normals.push_back(norm);
		}
		//texture coodinate data
		if(line.substr(0, 3) == "vt ") {
			std::istringstream vc(line.substr(3));
			glm::vec2 tex;
			double x, y;
			vc >> x >> y;
			tex = glm::vec2(x, y);
			textureCoords.push_back(tex);
		}

		if (line.substr(0, 2) == "f ")
        {
            int vt, vt2, vt3, textIndex, textIndex2, textIndex3 , normal, normal2, normal3;

                char c;

                std::istringstream f(line.substr(2));

                f >> vt >> c >> textIndex >> c >> normal >> vt2 >> c >> textIndex2 >> c >> normal2 >> vt3 >> c >> textIndex3 >> c >> normal3;
                indices.push_back(vt-1);
                indices.push_back(vt2-1);
                indices.push_back(vt3-1);

                textureIndices.push_back(textIndex-1);
                textureIndices.push_back(textIndex2 - 1);
                textureIndices.push_back(textIndex3 - 1);

                normalIndices.push_back(normal - 1);
                normalIndices.push_back(normal2 - 1);
                normalIndices.push_back(normal3 - 1);

        }
		//face data
		//if(line.substr(0, 2) == "f ") {
		//	std::istringstream vc(line.substr(2));
		//	Face face;

		//	//divide string by spaces
		//	std::string s[3];
		//	vc >> s[0] >> s[1] >> s[2];

		//	Face::Point p[3];
		//	for(int i = 0; i < 3; i++) {
		//		p[i] = getIndicesFromString(s[i]);
		//	}
		//	face = Face(p[0], p[1], p[2]);
		//	pushFaceToVectors(face);
		//}

		//new material (new mesh)
		else if(line.substr(0, 7) == "usemtl ") {
			if(indices.size() > 0) {
				postProcessing();
			}
			loadMaterial(line.substr(7));
		}
	}
	postProcessing();
}

void LoadObjModel::loadModel(const std::string & fileName, const std::string & matName) {
	loadMaterialLibrary(matName);
	loadModel(fileName);
}

std::vector<Vertex> LoadObjModel::getVerts() {
	return meshVertices;
}

std::vector<int> LoadObjModel::getIndices() {
	return indices;
}

std::vector<SubMesh> LoadObjModel::getSubMeshes() {
	return meshes;
}

BoundingBox LoadObjModel::getBoundingBox() {
	return b;
}

void LoadObjModel::postProcessing() {
	for(size_t i = 0; i < indices.size(); i++) {
		Vertex vert;
		vert.position = vertices[indices[i]];
		vert.normal = normals[normalIndices[i]];
		vert.texCoords = textureCoords[textureIndices[i]];
		meshVertices.push_back(vert);
	}
	SubMesh mesh;
	mesh.vertexList = meshVertices;
	mesh.meshIndices = indices;
	mesh.material = material;
	meshes.push_back(mesh);
	indices.clear();
	normalIndices.clear();
	textureIndices.clear();
	meshVertices.clear();
	material = Material();
}

void LoadObjModel::loadMaterial(const std::string & fileName) {
	material = MaterialHandler::getInstance()->getMaterial(fileName);

}

void LoadObjModel::loadMaterialLibrary(const std::string & matName) {
	MaterialLoader::LoadMaterial(matName);
}

LoadObjModel::Face::Point LoadObjModel::getIndicesFromString(std::string s) {
	std::string temp = s;

	//replace delimiter with space
	std::replace(temp.begin(), temp.end(), '/', ' ');

	std::istringstream tempStream = std::istringstream(temp);

	int v, t, n;
	//convert string to numbers
	tempStream >> v >> t >> n;

	return Face::Point(v - 1, t - 1, n - 1);
}

void LoadObjModel::pushFaceToVectors(Face f) {
	for(int i = 0; i < 3; i++) {
		indices.push_back(f.p[i].vertex);
		textureIndices.push_back(f.p[i].textureCoord);
		normalIndices.push_back(f.p[i].normal);
	}
}

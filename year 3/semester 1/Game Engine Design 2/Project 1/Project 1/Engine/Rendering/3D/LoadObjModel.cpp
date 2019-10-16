#include "LoadObjModel.h"

LoadObjModel::LoadObjModel() :
	verticies(std::vector<glm::vec3>()),
	normals(std::vector<glm::vec3>()),
	textureCoords(std::vector<glm::vec2>()),
	indicies(std::vector<int>()),
	normalIndicies(std::vector<int>()),
	textureIndicies(std::vector<int>()),
	meshVerticies(std::vector<Vertex>()),
	meshes(std::vector<SubMesh>()) {
}

LoadObjModel::LoadObjModel() {}

LoadObjModel::~LoadObjModel() {
	verticies.clear();
	normals.clear();
	textureCoords.clear();
	indicies.clear();
	normalIndicies.clear();
	textureIndicies.clear();
	meshVerticies.clear();
	meshes.clear();

}

void LoadObjModel::OnDestroy() {}

void LoadObjModel::loadModel(const std::string & fileName) {
	std::ifstream in(fileName.c_str(), std::ios::in);
	if(!in) {
		Debug::error("Could not load Obj file " + fileName, __FILE__, __LINE__);
		return;
	}
	std::string line;
	while(std::getline(in, line)) {
		if(line.substr(0, 2) == "v ") {
			std::istringstream v(line.substr(2));
			glm::vec3 vert;
			double x, y, z;
			v >> x >> y >> z;
			vert = glm::vec3(x, y, z);
			verticies.push_back(vert);
		}

		//normal data
		//texture coodinate data
		//face data
		//vetex indecies/texture indecies/normal indecies


		//new material (new mesh)
		else if(line.substr(0, 7) == "usemtl ") {
			if(indecies.size() > 0) {
				postProcessing();
			}
			loadMaterial(line.substr(0, 7));
		}
	}
	postProcessing();


}

void LoadObjModel::loadModel(const std::string & fileName, const std::string & matName) {
	loadMaterialLibrary(matName);
	loadModel(fileName);
}

std::vector<Vertex> LoadObjModel::getVerts() {
	return verticies;
}

std::vector<int> LoadObjModel::getIndecies() {
	return indecies;
}

std::vector<SubMesh> LoadObjModel::getSubMeshes() {
	return meshes;
}

void LoadObjModel::postProcessing() {
	for(size_t i = 0; i < indecies.size(); i++) {
		Vertex vert;
		vert.position = verticies[indecies[i]];
		vert.normal = normals[normalIndecies[i]];
		vert.texCoords = textureCoords[textureIndecies[i]];
		meshVerticies.push_back(vert);
	}
	SubMesh mesh;
	mesh.vertexList = meshVerticies;
	mesh.meshIndices = indecies;
	mesh.textureID = currentTexture;
	meshes.push_back(mesh);
	indecies.clear();
	normalIndecies.clear();
	textureIndecies.clear();
	meshVerticies.clear();
	currentTexture = 0;
}

void LoadObjModel::loadMaterial(const std::string & fileName) {
	currentTexture = TextureHandler::getInstance()->getTexture(fileName);
	if(currentTexture == 0) {
		TextureHandler::getInstance()->createTexture(fileName, "Resources/Textures/" + fileName + "png");
		currentTexture = TextureHandler::getInstance()->getTexture(fileName);
	}
}

void LoadObjModel::loadMaterialLibrary(const std::string & matName) {
	std::ifstream in(matName.c_str(), std::ios::in);
	if(!in) {
		Debug::error("Cannot open MTL file " + matName, __FILE__, __LINE__);
		return;
	}
	std::string line;
	while(std::getline(in, line)) {
		if(line.substr(0, 7) == "newmtl ") {
			loadMaterial(line.substr(7));
		}
	}
}

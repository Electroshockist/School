#ifndef FABRIC_H
#define FABRIC_H

class Shader;
class Mesh;
class Fabric {
public:
	Fabric() {};
	Fabric(Mesh* model);
	~Fabric();

	inline const Mesh* getMesh() {
		return mesh;
	}

	inline const Shader* getShader() {
		return shader;
	}

private:
	Mesh* mesh;
	Shader* shader;
};
#endif // !FABRIC_H


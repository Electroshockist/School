#ifndef FABRIC_H
#define FABRIC_H

class Shader;
class Mesh;
class Fabric {
public:
	Fabric() {};
	Fabric(Mesh* model);
	~Fabric();

	inline Mesh* getMesh() const {
		return mesh;
	}

	inline Shader* getShader() const {
		return shader;
	}

private:
	Mesh* mesh;
	Shader* shader;
};
#endif // !FABRIC_H


#ifndef FABRIC_H
#define FABRIC_H

class Mesh;
class Fabric {
public:
	Fabric() {};
	Fabric(Mesh* model);
	~Fabric();

	inline const Mesh* getMesh() {
		return mesh;
	}

private:
	Mesh* mesh;
};
#endif // !FABRIC_H


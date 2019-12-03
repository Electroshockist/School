#ifndef OCTTREE_H
#define OCTTREE_H

#include "../Rendering/3D/GameObject.h"
#include "../Math/Ray.h"

class OctNode {
	friend class OctTree;
	BoundingBox* octBounds;
	OctNode* parent;
	OctNode* children[8];
	std::vector<GameObject*> objectList;
	float size;

public:
	static int childNumber;
	enum OctChildren {
		//min, min, min
		OCT_TLF,
		//half, min, min
		OCT_BLF,
		//half, half, min
		OCT_BRF,
		//min, half, min
		OCT_TRF,
		//min, min, half
		OCT_TLR,
		//half, min, half
		OCT_BLR,
		//half, half, half
		OCT_BRR,
		//min, half, half
		OCT_TRR
	};

	OctNode(glm::vec3 position, float size, OctNode* parent);
	~OctNode();
	void Octify(int depth);

	OctNode* getParent();
	OctNode* getChild(OctChildren child);
	void addCollisionObject(GameObject* g);
	size_t getObjectCount() const;
	bool isLeaf() const;
	BoundingBox* getBoundingBox() const;
	int getChildCount() const;
};

class OctTree {
	OctNode* root;
	std::vector<OctNode*> rayIntersectionList;
	void addObjectToCell(OctNode* cell, GameObject* object);
	void prepareCollisionQuery(OctNode* cell, Ray ray);

public:
	OctTree(float worldSize);
	~OctTree();
	void addObject(GameObject* obj);
	GameObject* getCollision(Ray ray);


};
#endif // !OCTTREE_H


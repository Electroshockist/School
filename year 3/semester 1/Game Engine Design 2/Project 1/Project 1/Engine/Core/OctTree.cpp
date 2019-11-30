#include "OctTree.h"

int OctNode::childNumber = 0;

void OctTree::addObjectToCell(OctNode * cell, GameObject * object) {
	if(cell) {
		BoundingBox nodeBox = *cell->getBoundingBox();
		if(nodeBox.intersects(&object->getBoundingBox())) {
			if(cell->isLeaf()) {
				cell->addCollisionObject(object);
			}
			else {
				for(size_t i = 0; i < 8; i++) {
					addObjectToCell(cell->getChild(static_cast<OctNode::OctChildren>(i)), object);
				}
			}
		}
	}
}

void OctTree::prepareCollisionQuery(OctNode * cell, Ray ray) {
	if(cell) {
		if(ray.isColliding(cell->getBoundingBox())) {
			if(cell->isLeaf()) {
				rayIntersectionList.push_back(cell);
			}
			else {
				for(size_t i = 0; i < 8; i++) {
					prepareCollisionQuery(cell->getChild(static_cast<OctNode::OctChildren>(i)), ray);
				}
			}
		}
	}
}

OctTree::OctTree(float worldSize) {
	root = new OctNode(glm::vec3(-(worldSize / 2.0f)), worldSize, nullptr);
	root->Octify(3);
}

OctTree::~OctTree() {
	delete root;
	root = nullptr;

	if(rayIntersectionList.size() > 0) {
		for(auto cell : rayIntersectionList) {
			cell = nullptr;
		}
		rayIntersectionList.clear();
	}
}

void OctTree::addObject(GameObject* object) {
	addObjectToCell(root, object);
}

//homework
GameObject * OctTree::getCollision(Ray ray) {
	rayIntersectionList.clear();
	prepareCollisionQuery(root, ray);

	return nullptr;
}

OctNode::OctNode(glm::vec3 position, float size, OctNode * parent) : parent(nullptr), children(), objectList(std::vector<GameObject*>()) {
	octBounds = new BoundingBox();
	octBounds->min = position;
	octBounds->max = position + glm::vec3(size);
	this->size = size;

	for(size_t i = 0; i < 8; i++) {
		children[i] = 0;
	}

	this->parent = parent;
}

OctNode::~OctNode() {
	delete octBounds;
	octBounds = nullptr;

	if(objectList.size() > 0) {
		for(auto go : objectList) {
			go = nullptr;
		}
		objectList.clear();
	}
	for(size_t i = 0; i < 8; i++) {
		if(children[i] != nullptr) {
			delete children[i];
			children[i] = nullptr;
		}
	}
}

//Homework
void OctNode::Octify(int depth) {
	if(depth  > 0 && this) {
		float half = size / 2.0f;
		children[OCT_TLF] = new OctNode(glm::vec3(octBounds->min.x, octBounds->min.y + half,
												  octBounds->min.z + half), half, this);
		children[OCT_BLF] = new OctNode(glm::vec3(octBounds->min.x, octBounds->min.y + half,
												  octBounds->min.z + half), half, this);
		children[OCT_BRF] = new OctNode(glm::vec3(octBounds->min.x, octBounds->min.y + half,
												  octBounds->min.z + half), half, this);
		children[OCT_TRF] = new OctNode(glm::vec3(octBounds->min.x, octBounds->min.y + half,
												  octBounds->min.z + half), half, this);
		children[OCT_TLR] = new OctNode(glm::vec3(octBounds->min.x, octBounds->min.y + half,
												  octBounds->min.z + half), half, this);
		children[OCT_BLR] = new OctNode(glm::vec3(octBounds->min.x, octBounds->min.y + half,
												  octBounds->min.z + half), half, this);
		children[OCT_BRR] = new OctNode(glm::vec3(octBounds->min.x, octBounds->min.y + half,
												  octBounds->min.z + half), half, this);
		children[OCT_TRR] = new OctNode(glm::vec3(octBounds->min.x, octBounds->min.y + half,
												  octBounds->min.z + half), half, this);

		childNumber += 8;
	}

	if(depth > 0 && this) {
		for(int i = 0; i < 8; i++) {
			children[i]->Octify(depth - 1);
		}
	}
}

OctNode * OctNode::getParent() {
	return parent;
}

OctNode * OctNode::getChild(OctChildren child) {
	return children[child];
}

void OctNode::addCollisionObject(GameObject * g) {
	objectList.push_back(g);
}

size_t OctNode::getObjectCount() const {
	return objectList.size();
}

bool OctNode::isLeaf() const {
	if(children[0] == nullptr) {
		return true;
	}
	return false;
}

BoundingBox * OctNode::getBoundingBox() const {
	return octBounds;
}

int OctNode::getChildCount() const {
	return childNumber;
}

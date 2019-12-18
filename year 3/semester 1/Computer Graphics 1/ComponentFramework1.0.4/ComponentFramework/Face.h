#ifndef FACE_H
#define FACE_H

struct Face {
	unsigned int vertexIndices[3] ;
	unsigned int uvCoordIndices[3];
	unsigned int normalIndices[3];
};

#endif // !FACE_H

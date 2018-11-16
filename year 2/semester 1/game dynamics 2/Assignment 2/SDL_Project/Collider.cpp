#include "Collider.h"
#include "Body.h"
#include "VMath.h"
#include <iostream>

using namespace MATH;

bool Collider::Collided(const Body& b1, const Body& b2) {
	Vec3 origin = Vec3();

	//math functions do not work with SDL_POINTS, must be converted to Vec3
	Vec3 pointHolder[2][3] = { 
		{ 
			Vec3(b1.points[0].x, b1.points[0].y, 0),
			Vec3(b1.points[1].x, b1.points[1].y, 1),
			Vec3(b1.points[2].x, b1.points[2].y, 2)
		},
		{
			Vec3(b2.points[0].x, b2.points[0].y, 0),
			Vec3(b2.points[1].x, b2.points[1].y, 1),
			Vec3(b2.points[2].x, b2.points[2].y, 2)
		} 
	};

	//min point
	Vec3 A[3];

	//max point
	Vec3 B[3];
	
	//direction vectors
	Vec3 D[3];

	Vec3 P[3];
	
	//normal vectors
	Vec3 N[2];

	//dotted vectors
	float dotted[3];

	//get medians
	Vec3 centerA = Vec3(
		(pointHolder[0][0].x + pointHolder[0][1].x + pointHolder[0][2].x) / 3.0f,
		(pointHolder[0][0].y + pointHolder[0][1].y + pointHolder[0][2].y) / 3.0f,
			0.0f);

	Vec3 centerB = Vec3(
		(pointHolder[1][0].x + pointHolder[1][1].x + pointHolder[1][2].x) / 3.0f,
		(pointHolder[1][0].y + pointHolder[1][1].y + pointHolder[1][2].y) / 3.0f,
			0.0f);
	
	//direction vectors
	//positive
	D[0] = centerB - centerA;
	//negative
	D[1] = centerA - centerB;

	// (4,3)
	A[0] = Min(b1, D[0]);
	// (12,8)
	B[0] = Max(b2, D[0]);
	// [-8, -5]
	P[0] = Vec3(A[0] - B[0]);

	//[8,4] 
	A[1] = Min(b1, D[1]);
	//[9,6]
	B[1] = Max(b2, D[1]);
	// [1,2]
	P[1] = Vec3(A[1] - B[1]);

	//[9,6]
	A[2] = Max(b1, D[2]);
	//[8,8]
	B[2] = Min(b2, D[2]);
	//1,-2
	P[2] = Vec3(A[2] - B[2]);

	//line from P[0] to P[1]
	// [-9, -7]
	Vec3 line = Vec3(P[0] - P[1]);

	//[9,-7]
	N[0] = Vec3( line.x, -line.y, line.z);
	//[-9,7]
	N[1] = Vec3(-line.x,  line.y, line.z);

	//center of P line
	Vec3 medianLine = Vec3(P[0] / 2 + P[1] / 2);

	//line from median to origin
	Vec3 originLine = Vec3(origin - medianLine);
	
	//normalized line
	//[9,-7]
	D[2] = Vec3(getCLosestToOrigin(N[0], N[1], originLine));



	dotted[0] = 
		VMath::dot(
			VMath::cross((P[1] - P[0]), (origin - P[0])),
			VMath::cross((P[1] - P[0]), (P[2] - P[0]))
		);
	dotted[1] =
		VMath::dot(
			VMath::cross((P[2] - P[1]),(origin - P[1])),
			VMath::cross((P[2] - P[1]), (P[0] - P[1]))
		);
	dotted[2] = 
		VMath::dot(
			VMath::cross((P[0] - P[2]), (origin - P[2])),
			VMath::cross((P[0] - P[2]), (P[1] - P[2]))
		);

	//Checks collisions
	if (dotted[0] >= VERY_SMALL && dotted[1] >= VERY_SMALL && dotted[2] >= VERY_SMALL) return true;
	else return false;
}

void Collider::HandleCollision(Body& b1, Body& b2) {
	if (Collided(b1, b2)) std::cout << "Collided!" << std::endl;
	else std::cout << "Not Collided!" << std::endl;
}

//gets largest point
Vec3 Collider::Max(const Body & body, Vec3 D){
	//math functions do not work with SDL_POINTS, must be converted to Vec3
	Vec3 pointHolder[3] = {
		Vec3(body.points[0].x, body.points[0].y, 0),
		Vec3(body.points[1].x, body.points[1].y, 0),
		Vec3(body.points[2].x, body.points[2].y, 0)
	};
	//tempvec
	Vec3 tv = Vec3(VMath::dot(D, pointHolder[0]),VMath::dot(D, pointHolder[1]),VMath::dot(D, pointHolder[2]));
	if (tv.x > tv.y && tv.x > tv.z) {
		//std::cout << pointHolder[0].x << ", " << pointHolder[0].y << std::endl;
		return pointHolder[0];
	}
	else if (tv.y > tv.x && tv.y > tv.z) {
		//std::cout << pointHolder[1].x << ", " << pointHolder[1].y << std::endl;
		return pointHolder[1];
	}
	else if (tv.z > tv.x && tv.z > tv.y) {
		//std::cout << pointHolder[2].x << ", " << pointHolder[2].y << std::endl;
		return pointHolder[2];
	}
	else {
		//std::cout << "null" << std::endl;
		return NULL;
	}
}

//gets smallest point
Vec3 Collider::Min(const Body & body, Vec3 D) {
	//math functions do not work with SDL_POINTS, must be converted to Vec3
	Vec3 pointHolder[3] = {
		Vec3(body.points[0].x, body.points[0].y, 0),
		Vec3(body.points[1].x, body.points[1].y, 0),
		Vec3(body.points[2].x, body.points[2].y, 0)
	};
	//tempvec
	Vec3 tv = Vec3(VMath::dot(D, pointHolder[0]), VMath::dot(D, pointHolder[1]), VMath::dot(D, pointHolder[2]));
	if (tv.x < tv.y && tv.x < tv.z) {
		//std::cout << pointHolder[0].x << ", " << pointHolder[0].y << std::endl;
		return pointHolder[0];
	}
	else if (tv.y < tv.x && tv.y < tv.z) {
		//std::cout << pointHolder[1].x << ", " << pointHolder[1].y << std::endl;
		return pointHolder[1];
	}
	else if (tv.z < tv.x && tv.z < tv.y) {
		//std::cout << pointHolder[2].x << ", " << pointHolder[2].y << std::endl;
		return pointHolder[2];
	}
	else {
		//std::cout << "null" << std::endl;
		return NULL;
	}
}

Vec3 Collider::getCLosestToOrigin(Vec3 N1, Vec3 N2, Vec3 orginLine) {
	float temp[2] = { 
		VMath::dot(N1, orginLine), 
		VMath::dot(N2, orginLine)
	};
	//std::cout << temp[0] << std::endl;
	if (temp[0] > temp[1]) return N1;
	return N2;
}

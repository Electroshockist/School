#include "Collider.h"
#include "Body.h"
#include "VMath.h"
#include <iostream>

using namespace MATH;

bool Collider::Collided(const Body& b1, const Body& b2) {
	Vec3 origin = (0, 0, 0);

	//math functions do not work with SDL_POINTS, must be converted to Vec3
	Vec3 pointHolder[2][3] = {};

	Vec3
		//min point
		A[4],
		//max point
		B[4],
		//direction vectors
		D[3],
		P[3],
		//normal vectors
		N[2];

	//dotted vectors
	float dotted[3], totalX, totalY;

	pointHolder[0][0] = Vec3(b1.points[0].x, b1.points[0].y, 0);
	pointHolder[0][1] = Vec3(b1.points[1].x, b1.points[1].y, 1);
	pointHolder[0][2] = Vec3(b1.points[2].x, b1.points[2].y, 2);

	pointHolder[1][0] = Vec3(b2.points[0].x, b2.points[0].y, 0);
	pointHolder[1][1] = Vec3(b2.points[1].x, b2.points[1].y, 1);
	pointHolder[1][2] = Vec3(b2.points[2].x, b2.points[2].y, 2);

	//get medians
	A[0] = Vec3(
		(pointHolder[0][0].x + pointHolder[0][1].x + pointHolder[0][2].x) / 3.0f,
		(pointHolder[0][0].y + pointHolder[0][1].y + pointHolder[0][2].y) / 3.0f,
			0.0f);

	B[0] = Vec3(
		(pointHolder[1][0].x + pointHolder[1][1].x + pointHolder[1][2].x) / 3.0f,
		(pointHolder[1][0].y + pointHolder[1][1].y + pointHolder[1][2].y) / 3.0f,
			0.0f);

	D[0] = B[0] - A[0];
	D[1] = A[0] - B[0];
	
	A[1] = Min(b2, D[0]);
	B[1] = Max(b1, D[0]);
	P[0] = Vec3(A[1] - B[1]);

	A[2] = Min(b2, D[1]);
	B[2] = Max(b1, D[1]);
	P[1] = Vec3(A[2] - B[2]);

	Vec3 line = Vec3(P[0] - P[1]);

	//talk to marco about math here
	N[0] = Vec3(-line.y, line.x, line.z);
	N[1] = Vec3(line.y, -line.x, line.z);

	Vec3 medianLine = Vec3(P[0] / 2 + P[0] / 2);
	Vec3 originLine = Vec3(origin - medianLine);
	
	D[2] = Vec3(getNorm(N[0], N[1], originLine));

	A[3] = Min(b2, D[2]);
	B[3] = Max(b1, D[2]);
	P[2] = Vec3(A[3] - B[3]);

	dotted[0] = VMath::dot(VMath::cross((P[1] - P[0]), (origin - P[0])), VMath::cross((P[1] - P[0]), (P[2] - P[0])));
	dotted[1] = VMath::dot(VMath::cross((origin - P[1]), (P[2] - P[1])), VMath::cross((P[2] - P[1]), (P[0] - P[1])));
	dotted[2] = VMath::dot(VMath::cross((P[0] - P[2]), (origin - P[0])), VMath::cross((P[0] - P[2]), (P[1] - P[2])));

	std::cout << dotted[0] << " " << dotted[1] << " " << dotted[2] << std::endl;

	//Checks collisions
	if (dotted[0] >= 0 && dotted[1] >= 0 && dotted[2] >= 0) return true;
	else return false;
}

void Collider::HandleCollision(Body& b1, Body& b2) {
	if (Collided(b1, b2)) std::cout << "Collided!" << std::endl;
	else std::cout << "Not Collided!" << std::endl;
}

//gets largest point
Vec3 Collider::Max(const Body & body, Vec3 D){
	//std::cout << body.points[0].x << " " << body.points[0].y << std::endl;
	//math functions do not work with SDL_POINTS, must be converted to Vec3
	Vec3 pointHolder[3] = {
		Vec3(body.points[0].x, body.points[0].y, 0),
		Vec3(body.points[1].x, body.points[1].y, 0),
		Vec3(body.points[2].x, body.points[2].y, 0)
	};
	//std::cout << VMath::dot(D, pointHolder[0]) << std::endl;
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

Vec3 Collider::getNorm(Vec3 N1, Vec3 N2, Vec3 orginLine) {
	float temp[2] = { 
		VMath::dot(N1, orginLine), 
		VMath::dot(N2, orginLine)
	};

	if (temp[0] > temp[1]) return N1;
	else if (temp[0] < temp[1]) return N2;
	else return NULL;
	
}

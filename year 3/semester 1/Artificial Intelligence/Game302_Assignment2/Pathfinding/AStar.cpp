#include "AStar.h"
#include "Map.h"
#include "SDL.h"
#include <iostream>

AStar::AStar(Map* m)
	:map(m),
	isSearching(false) {
	graph = m->GetGraph();
}

AStar::~AStar() {}

bool AStar::IsSearching() {
	return isSearching;
}

void AStar::Search(Node* start, Node* goal) {
	isSearching = true;
	startNode = start;
	goalNode = goal;

	thread = SDL_CreateThread(SearchThread, "", this);
}

void AStar::OnSearchDone() {
	isSearching = false;

	// Draw the shortest path
	for(auto p : pathFound) {
		map->SetPathMap(p->position, Map::RESULT_PATH_FOUND); // the second param value '2' means that it will draw
	}

	//clear lists
	pathFound.clear();
	visited.clear();
	unvisited.clear();
	predecessorDict.clear();
}

int AStar::SearchThread(void * data) {
	AStar* astar = static_cast<AStar*>(data);

	if(!astar->startNode || !astar->goalNode) {
		astar->OnSearchDone();
		return 0;
	}

	// To do: Complete this function.	

	//loop through all nodes in map
	for (auto& n : astar->map->GetGraph()->GetAllNodes()) {

		//set value at each node to max
		astar->distanceDict[&n] = std::numeric_limits<float>::max();
		astar->actualDistanceDict[&n] = std::numeric_limits<float>::max();

		//set all nodes in map to unvisited
		astar->unvisited.push_back(&n);
	}

	astar->distanceDict[astar->startNode] = 0;
	astar->actualDistanceDict[astar->startNode] = 0;

	while(astar->unvisited.size() > 0) {
		SDL_Delay(100);
		//set u to closest unvisited node
		Node* u = astar->GetClosestFromUnvisited();

		astar->map->SetPathMap(u->position, Map::SEARCH_IN_PROGRESS);

		//quit if u is goal
		if(u == astar->goalNode) {
			break;
		}

		//add u to visited nodes
		astar->visited.push_back(u);

		//loop through adjacent nodes
		for(auto & v : astar->map->GetGraph()->GetAdjacentNodes(u)) {
			//if visited contains current node, continue to next node
			if(std::find(astar->visited.begin(), astar->visited.end(), v) != astar->visited.end()) {
				continue;
			}

			//astar heuristic distance vs real distance calculation
			auto a = astar->map->GetGraph()->GetDistance(u, v) + astar->map->GetGraph()->GetDistance(u, astar->goalNode);
			if(astar->distanceDict.at(v) > astar->actualDistanceDict.at(u) + a) {
				astar->distanceDict[v] = astar->actualDistanceDict.at(u) + a;
				astar->actualDistanceDict[v] = astar->actualDistanceDict.at(u) + astar->map->GetGraph()->GetDistance(u, v);
			}
			astar->predecessorDict[v] = u;
		}
	}
	astar->pathFound.push_back(astar->goalNode);
	Node* p = astar->predecessorDict.at(astar->goalNode);

	while(p != astar->startNode) {
		astar->pathFound.push_back(p);
		p = astar->predecessorDict.at(p);
	}
	astar->pathFound.push_back(p);
	std::reverse(astar->pathFound.begin(), astar->pathFound.end());

	astar->OnSearchDone();
	return 0;
}

Node * AStar::GetClosestFromUnvisited() {
	float shortest = std::numeric_limits<float>::max();
	Node* shortestNode = nullptr;

	// To do: Complete this function.
	for (auto& tempNode : unvisited) {
		if(shortest > distanceDict.at(tempNode)) {
			shortest = distanceDict.at(tempNode);
			shortestNode = tempNode;
		}
	}
	//remove the shortest node from the unvisited
	unvisited.erase(std::find(unvisited.begin(), unvisited.end(), shortestNode));

	return shortestNode;
}

void AStar::ValidateDistanceDict(Node * n) {
	float max = std::numeric_limits<float>::max();
	if(distanceDict.find(n) == distanceDict.end()) {
		distanceDict[n] = max;
	}
	if(actualDistanceDict.find(n) == actualDistanceDict.end()) {
		actualDistanceDict[n] = max;
	}
}

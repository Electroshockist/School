#include "AStar.h"
#include "Map.h"
#include "SDL.h"

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

}

int AStar::SearchThread(void * data) {
	AStar* astar = static_cast<AStar*>(data);

	///shorthand variables
	Map* map = astar->map;
	Graph* graph = map->GetGraph();
	std::vector<Node*>* visited = &astar->visited;
	std::vector<Node*>* unvisited = &astar->unvisited;


	if(!astar->startNode || !astar->goalNode) {
		astar->OnSearchDone();
		return 0;
	}

	// To do: Complete this function.	

	//clear lists
	visited->clear();
	unvisited->clear();
	astar->predecessorDict.clear();

	//loop through all nodes in map
	for(int i = graph->GetAllNodes().size() - 1; i > 0; i--) {
		Node* node = &graph->GetAllNodes().at(i);

		//set value at each node to max
		astar->distanceDict[node] = std::numeric_limits<float>::max();
		astar->actualDistanceDict[node] = std::numeric_limits<float>::max();

		//set all nodes in map to unvisited
		unvisited->push_back(node);
	}

	astar->distanceDict[astar->startNode] = 0;
	astar->actualDistanceDict[astar->startNode] = 0;

	while(unvisited->size() > 0) {
		//set u to closest unvisited node
		Node* u = astar->GetClosestFromUnvisited();

		//quit if u is goal
		if(u == astar->goalNode) {
			break;
		}

		//add u to visited nodes
		visited->push_back(u);

		//loop through adjacent nodes
		for each (auto node in graph->GetAdjacentNodes(u)) {
			//if visited contains current node, continue to next node
			if(std::find(visited->begin(), visited->end(), node) != visited->end()) {
				continue;
			}

			//astar heuristic distance vs real distance calculation
			if(astar->distanceDict[node] > astar->actualDistanceDict[node] + graph->GetDistance(u, node) + graph->GetDistance(node, astar->goalNode)) {
				astar->distanceDict[node] = astar->actualDistanceDict[u] + graph->GetDistance(u, node) + graph->GetDistance(node, astar->goalNode);
				astar->actualDistanceDict[node] = astar->actualDistanceDict[u] + graph->GetDistance(u, node);
			}
			astar->predecessorDict[node] = u;
		}
	}
	astar->pathFound.push_back(astar->goalNode);
	Node* p = astar->predecessorDict[astar->goalNode];

	while(p != astar->startNode) {
		astar->pathFound.push_back(p);
		p = astar->predecessorDict[p];
	}

	astar->OnSearchDone();
	return 0;
}

Node * AStar::GetClosestFromUnvisited() {

	float shortest = std::numeric_limits<float>::max();
	Node* shortestNode = nullptr;

	// To do: Complete this function.
	int i = 0;
	for each (auto var in unvisited) {
		Node* tempNode = &map->GetGraph()->GetAllNodes().at(i);
		if(shortest > distanceDict[tempNode]) {
			shortest = distanceDict[tempNode];
			shortestNode = tempNode;
		}
		i++;
	}

	//remove the shortest node from the unvisited
	unvisited.erase(unvisited.begin() + i - 1);

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

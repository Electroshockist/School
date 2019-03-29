#include <iostream>

#include "Graphs.h"

using namespace std;

int main(int args, char **argc)
{
	int result;
	Graph<char> demoGraph(7);

	demoGraph.push('A');
	demoGraph.push('B');
	demoGraph.push('C');
	demoGraph.push('D');
	demoGraph.push('E');
	demoGraph.push('F');
	demoGraph.push('G');

	demoGraph.attachEdge('A', 'B');
	demoGraph.attachEdge('A', 'D');
	demoGraph.attachEdge('A', 'E');

	demoGraph.attachEdge('B', 'A');
	demoGraph.attachEdge('B', 'C');
	demoGraph.attachEdge('B', 'E');

	demoGraph.attachEdge('C', 'B');
	demoGraph.attachEdge('C', 'E');
	demoGraph.attachEdge('C', 'F');

	demoGraph.attachEdge('D', 'A');
	demoGraph.attachEdge('D', 'E');

	demoGraph.attachEdge('E', 'A');
	demoGraph.attachEdge('E', 'B');
	demoGraph.attachEdge('E', 'C');

	demoGraph.attachEdge('F', 'C');
	demoGraph.attachEdge('F', 'E');
	demoGraph.attachEdge('F', 'G');

	demoGraph.attachEdge('G', 'C');
	demoGraph.attachEdge('G', 'F');

	// Perform depth first search for a path from A to D.
	cout << "DepthFirstSearch Nodes Visited: ";

	result = demoGraph.depthFirstSearch('A', 'G');
	cout << endl << endl;

	if (result == 1)
		cout << "Path found!";
	else
		cout << "Path NOT found!";

	cout << endl << endl;

	getchar();

	return 1;
}
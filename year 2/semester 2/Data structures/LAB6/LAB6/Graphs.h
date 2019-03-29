#ifndef GRAPHS_H
#define GRAPHS_H

#include <vector>
#include <iterator>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <cassert>

using namespace std;

template<typename T>
class Graph
{
	template<typename T>
	class Vertex
	{
		friend Graph;

	public:
		Vertex(T n) : node(n)
		{ }

		T getNode()
		{
			return node;
		}

	private:
		T node;
	};

	class EdgeInfo
	{
		friend Graph;

	public:
		EdgeInfo() : index1(0), index2(0), weight(0)
		{ }

		bool operator<(const EdgeInfo &e2) const
		{
			return (weight < e2.weight);
		}

		bool operator==(const EdgeInfo &e2) const
		{
			return (index2 == e2.index2);
		}

		int index1, index2;
		int weight;
	};

public:
	Graph(int numVerts, bool weighted = false) : maxVertices(numVerts), adjacencyMatrix(NULL), isWeighted(weighted)
	{
		assert(numVerts > 0);

		vertices.reserve(maxVertices);

		adjacencyMatrix = new char*[maxVertices];
		assert(adjacencyMatrix != NULL);

		vertexVisits = new char[maxVertices];
		assert(vertexVisits != NULL);

		//memset does the same thing as the for loop
		//memset(vertexVisits, 0, maxVertices);
		for (int i = 0; i < maxVertices; i++)
		{
			vertexVisits[i] = NULL;
		}

		for (int i = 0; i < maxVertices; i++)
		{
			adjacencyMatrix[i] = new char[maxVertices];

			assert(adjacencyMatrix[i] != NULL);

			//memset does the same thing as the for loop
			//memset(adjacencyMatrix[i], 0, maxVertices);
			for (int j = 0; j < maxVertices; j++)
			{
				adjacencyMatrix[i][j] = NULL;
			}
		}
	}

	~Graph()
	{
		if (adjacencyMatrix != NULL)
		{
			for (int i = 0; i < maxVertices; i++)
			{
				if (adjacencyMatrix[i] != NULL)
				{
					delete[] adjacencyMatrix[i];

					adjacencyMatrix[i] = NULL;
				}
			}

			delete[] adjacencyMatrix;

			adjacencyMatrix = NULL;
		}

		if (vertexVisits != NULL)
		{
			delete[] vertexVisits;

			vertexVisits = NULL;
		}
	}

	bool push(T n)
	{
		if ((int)vertices.size() >= maxVertices)
			return false;

		vertices.push_back(Vertex<T>(n));

		return true;
	}

	int findIndex(char value)
	{
		assert(adjacencyMatrix != NULL);

		for (int i = 0; i < (int)vertices.size(); i++)
		{
			if (vertices[i].getNode() == value)
				return i;
		}

		return -1;
	}

	void attachEdge(int index1, int index2, int weight = 0)
	{
		assert(adjacencyMatrix != NULL);

		if (isWeighted)
		{
			adjacencyMatrix[index1][index2] = weight;
			adjacencyMatrix[index2][index1] = weight;
		}
		else
		{
			adjacencyMatrix[index1][index2] = 1;
			adjacencyMatrix[index2][index1] = 1;
		}
	}

	void attachEdge(char startPoint, char endPoint, int weight = 0)
	{
		assert(adjacencyMatrix != NULL);

		int index1, index2;

		index1 = findIndex(startPoint);
		index2 = findIndex(endPoint);

		assert(index1 != -1);
		assert(index2 != -1);

		if (isWeighted)
		{
			adjacencyMatrix[index1][index2] = weight;
			adjacencyMatrix[index2][index1] = weight;
		}
		else
		{
			adjacencyMatrix[index1][index2] = 1;
			adjacencyMatrix[index2][index1] = 1;
		}
	}

	void attachDirectedEdge(int index1, int index2, int weight = 0)
	{
		assert(adjacencyMatrix != NULL);

		if (isWeighted)
			adjacencyMatrix[index1][index2] = weight;
		else
			adjacencyMatrix[index1][index2] = 1;
	}

	void attachDirectedEdge(char startPoint, char endPoint, int weight = 0)
	{
		assert(adjacencyMatrix != NULL);

		int index1, index2;

		index1 = findIndex(startPoint);
		index2 = findIndex(endPoint);

		assert(index1 != -1);
		assert(index2 != -1);

		if (isWeighted)
			adjacencyMatrix[index1][index2] = weight;
		else
			adjacencyMatrix[index1][index2] = 1;
	}

	int getNextUnvisitedVertex(int index)
	{
		assert(adjacencyMatrix != NULL);
		assert(vertexVisits != NULL);

		for (int i = 0; i < (int)vertices.size(); i++)
			if (adjacencyMatrix[index][i] == 1 && vertexVisits[i] == 0)
				return i;

		return -1;
	}

	bool breadthFirstSearch(int startIndex, int endIndex)
	{
		assert(adjacencyMatrix != NULL);
		assert(vertexVisits != NULL);

		vertexVisits[startIndex] = 1;

		cout << vertices[startIndex].getNode();

		queue<int> searchQueue;
		int vert1 = 0, vert2 = 0;

		searchQueue.push(startIndex);

		while (searchQueue.empty() != true)
		{
			vert1 = searchQueue.front();
			searchQueue.pop();

			if (vert1 == endIndex)
			{
				//memset(vertexVisits, 0, maxVertices);
				for (int i = 0; i < maxVertices; i++)
				{
					vertexVisits[i] = NULL;
				}

				return true;
			}

			while ((vert2 = getNextUnvisitedVertex(vert1)) != -1)
			{
				vertexVisits[vert2] = 1;

				cout << vertices[vert2].getNode();

				searchQueue.push(vert2);
			}
		}

		//memset(vertexVisits, 0, maxVertices);
		for (int i = 0; i < maxVertices; i++)
		{
			vertexVisits[i] = NULL;
		}

		return false;
	}

	bool breadthFirstSearch(char startVertex, char endVertex)
	{
		assert(adjacencyMatrix != NULL);
		assert(vertexVisits != NULL);

		int startIndex = findIndex(startVertex);
		int endIndex = findIndex(endVertex);

		assert(startIndex != -1);
		assert(endIndex != -1);

		vertexVisits[startIndex] = 1;

		cout << vertices[startIndex].getNode() << " ";

		queue<int> searchQueue;
		int vert1 = 0, vert2 = 0;

		searchQueue.push(startIndex);

		while (searchQueue.empty() != true)
		{
			vert1 = searchQueue.front();
			searchQueue.pop();

			if (vert1 == endIndex)
			{
				//memset(vertexVisits, 0, maxVertices);
				for (int i = 0; i < maxVertices; i++)
				{
					vertexVisits[i] = NULL;
				}

				return true;
			}

			while ((vert2 = getNextUnvisitedVertex(vert1)) != -1)
			{
				vertexVisits[vert2] = 1;

				cout << vertices[vert2].getNode() << " ";

				searchQueue.push(vert2);
			}
		}

		//memset(vertexVisits, 0, maxVertices);
		for (int i = 0; i < maxVertices; i++)
		{
			vertexVisits[i] = NULL;
		}

		return false;
	}

	//Depth First Traversal
	bool depthFirstSearch(int startIndex, int endIndex)
	{
		//Assert whether the adjacency matrix exists and is not NULL
		assert(adjacencyMatrix != NULL);
		//Assert whether the vertices visited exists and is not NULL
		assert(vertexVisits != NULL);		
		//Assert whether startIndex is not equal to -1
		assert(startIndex != -1);
		//Assert whether endIndex is not equal to -1
		assert(endIndex != -1);		

		//Begin the traversal at the starting index
		vertexVisits[startIndex] = 1;
		//Print the value at the start index
		cout << vertices[startIndex].getNode() << " ";		

		//Declare a stack for searching
		stack<int> searchStack
		//Declare and initialize a starting vertex point to 0
		int vert1 = 0;		

		//Push start index into stack
		searchStack.push(startIndex);	

		//Loop while stack is not empty
		while (!searchStack.empty) {
			//Assign end point vertex to the next unvisited vertex - use getNextUnvisitedVertex method
			vert1 = getNextUnvisitedVertex(searchStack.top());

			//If vertex is -1 pop from stack
			if (vert1 == -1) {
				searchStack.pop();
			}

			//If vertex is not -1
			else {

				//Set visited vertex to 1
				vertexVisits[vert1] = 1;

				//Print the value of the current node visited
				cout << vertices[vert1].getNode();


				//Push vertex index into stack
				searchStack.push(vert1);
								
			}


			//If vertex reach end point
			if (vert1 == endIndex) {
				//Loop through vertexVisits and set value equal to 0
				for (int i = 0; i < maxVertices; i++) {
					vertexVisits[i] = NULL;
				}

				//Return true
				return true;
			}
		}
		

		//Loop through vertexVisits and set value equal to 0
		for (int i = 0; i < maxVertices; i++)
		{
			vertexVisits[i] = NULL;
		}

		//Return false
		return false;
		
	}

	//Depth First Traversal
	//Variables to be used:
	//adjacencyMatrix - is a pointer to the adjacency matrix
	//vertexVisits - is a character array
	//vertices - is a vector of graph vertices
	//maxVertices - the maximum number of vertices
	bool depthFirstSearch(char startVertex, char endVertex)
	{
		//Assert whether the adjacency matrix exists and is not NULL
		assert(adjacencyMatrix != NULL);

		//Assert whether the vertices visited exists and is not NULL
		assert(vertexVisits != NULL);


		//Find index for start vertex
		int startIndex = findIndex(startVertex);

		//Find index for end vertex		
		int endIndex = findIndex(endVertex);

		//Assert whether startIndex is not equal to -1
		assert(startIndex != -1);

		//Assert whether endIndex is not equal to -1
		assert(endIndex != -1);

		//Begin the traversal at the starting index
		vertexVisits[startIndex] = 1;

		//Print the value at the start index
		cout << vertices[startIndex].getNode() << " ";

		//Declare a stack for searching
		stack<int> searchStack;

		//Declare and initialize a starting vertex point to 0
		int vert1 = 0;

		//Push start index into stack
		searchStack.push(startIndex);

		//Loop while stack is not empty
		while (!searchStack.empty()) {

			//Assign end point vertex to the next unvisited vertex - use getNextUnvisitedVertex method
			vert1 = getNextUnvisitedVertex(searchStack.top());

			//If vertex is -1 pop from stack
			if (vert1 == -1) {
				searchStack.pop();
			}

			//If vertex is not -1
			else {

				//Set visited vertex to 1
				vertexVisits[vert1] = 1;

				//Print the value of the current node visited
				cout << vertices[vert1].getNode();


				//Push vertex index into stack
				searchStack.push(vert1);

			}

			//If vertex reach end point
			if (vert1 == endIndex) {
				//Loop through vertexVisits and set value equal to 0
				for (int i = 0; i < maxVertices; i++) {
					vertexVisits[i] = NULL;
				}

				//Return true
				return true;
			}
		}


		//Loop through vertexVisits and set value equal to 0
		for (int i = 0; i < maxVertices; i++)
		{
			vertexVisits[i] = NULL;
		}

		//Return false
		return false;


	}

	//Topological Sort
	bool topologicalSort(list<T> &output)
	{
		//Flag to record cycles
		bool hasCycles = false;

		//Temp vector of vertices
		vector<Vertex<T> > tempVerts(vertices);

		//Temp size of vertices
		int tempSize = (int)tempVerts.size();

		//Array of characters to record vertex labels
		char **tempAdjMat = new char*[maxVertices];

		//Assert if temp is null
		assert(tempAdjMat != NULL);

		//Iterate through all vertices
		for (int i = 0; i < maxVertices; i++)
		{
			//Create new character
			tempAdjMat[i] = new char[maxVertices];

			//Assert if null
			assert(tempAdjMat[i] != NULL);

			//Copy memory from adjacency matrix to temp
			//memcpy does the same thing as the for loop
			//memcpy(tempAdjMat[i], adjacencyMatrix[i], maxVertices);
			for (int j = 0; j < maxVertices; j++)
			{
				tempAdjMat[i][j] = adjacencyMatrix[i][j];
			}
		}

		//If size greater than 0
		while (tempSize > 0)
		{
			//Fine vertices with no successor
			int v = getVertNoSuccessor(tempAdjMat, tempSize);

			//If no cycles exit
			if (v == -1)
			{
				hasCycles = true;
				break;
			}

			//Store node in output
			output.push_front(tempVerts[v].getNode());

			//If successor cannot be found, delete vertex from list and matrix
			if (v != (tempSize - 1))
			{
				//Erase all vertices from from temp
				tempVerts.erase(tempVerts.begin() + v);

				//Delete from rows in adjacency matrix
				for (int row = v; row < tempSize - 1; row++)
				{
					for (int c = 0; c < tempSize; c++)
					{
						tempAdjMat[row][c] = tempAdjMat[row + 1][c];
					}
				}

				//Delete from columns in adjacency matrix
				for (int col = v; col < tempSize - 1; col++)
				{
					for (int r = 0; r < tempSize; r++)
					{
						tempAdjMat[r][col] = tempAdjMat[r][col + 1];
					}
				}
			}

			//Decrease size
			tempSize--;
		}

		//If temp adjacency matrix is null delete
		if (tempAdjMat != NULL)
		{
			for (int i = 0; i < maxVertices; i++)
			{
				if (tempAdjMat[i] != NULL)
				{
					delete[] tempAdjMat[i];
					tempAdjMat[i] = NULL;
				}
			}

			delete[] tempAdjMat;
			tempAdjMat = NULL;
		}

		//Return whether has cycles
		return !hasCycles;
	}

	void displayMST(string &output)
	{
		if (isWeighted)
		{
			//Assert whether graph is NULL
			assert(adjacencyMatrix != NULL);

			//Assert whether vertices visited are NULL
			assert(vertexVisits != NULL);

			//Start at first vertex
			int currentVertex = 0;
			//Set total visited nodes to 0
			int totalChecked = 0;
			//Set size to size of the vertex vector
			int size = (int)vertices.size();

			//Create a vector to contain edge info
			vector<EdgeInfo> edgeInfo;

			//Loop while the number of checked vertices does not equal the total number of vertices
			while (totalChecked < size - 1)
			{
				//Set current vertex to visited (true)
				vertexVisits[currentVertex] = 1;
				//Add to total number of visited vertices
				totalChecked++;

				//Loop through and add all unchecked adjacent vertices and their weights to a priority queue
				for (int i = 0; i < size; i++)
				{
					//If counter is equal to current vertex goto next iteration
					//If vertex visited is true goto next iteration
					//If adjacency matrix does not have an edge at current vertex goto next iteration
					if (i == currentVertex || vertexVisits[i] == 1 || adjacencyMatrix[currentVertex][i] == 0)
						continue;

					//Create an edgeinfo
					EdgeInfo edge;
					//Set first vertex to start point of edge
					edge.index1 = currentVertex;
					//Set second vertex to end point of edge
					edge.index2 = i;
					//Set weight from the current vertex stored in adjacency matrix
					edge.weight = adjacencyMatrix[currentVertex][i];

					//Create vector iterator to search for the edge from the begining to end of the vector containing edgeinfo
					vector<EdgeInfo>::iterator it = find(edgeInfo.begin(), edgeInfo.end(), edge);

					//If end of the vector push edge
					if (it == edgeInfo.end())
						edgeInfo.push_back(edge);
					//If weight found within the iterator is greater than the edge weight
					//Reassign new weight to iterator edge
					else
					{
						if (edge.weight <= (*it).weight)
						{
							(*it).index1 = edge.index1;
							(*it).index2 = edge.index2;
							(*it).weight = edge.weight;
						}
					}
				}

				//If vector of edgeinfo is empty print error
				if (edgeInfo.empty() == true)
				{
					output = "Error: Graph is not connected.";
					return;
				}

				// Orders from greatest to least
				sort(edgeInfo.rbegin(), edgeInfo.rend());

				int endIndex = (int)edgeInfo.size() - 1;
				int v1 = edgeInfo[endIndex].index1;
				currentVertex = edgeInfo[endIndex].index2;

				//Output vertices
				output += vertices[v1].getNode();
				output += ":";
				output += vertices[currentVertex].getNode();
				output += " ";

				//Remove minimum, which was placed at the back.
				edgeInfo.pop_back();
			}

			//Set memory for vertices visited
			//memset(vertexVisits, 0, maxVertices);
			for (int i = 0; i < maxVertices; i++)
			{
				vertexVisits[i] = 0;
			}
		}
		else
		{
			output = "Cannot solve Minimum Spanning Tree since no weights are assigned.";
		}
	}

private:
	vector<Vertex<T>> vertices;
	int maxVertices;

	char **adjacencyMatrix;
	char *vertexVisits;

	bool isWeighted;

	//Find the vetices with no successors
	int getVertNoSuccessor(char **adjMat, int size)
	{
		//Set flag to determine whether successor exists
		bool edgeFound = false;

		//Traverse all edges and find vertices with no successor
		//End traversal when found
		//Traverse Rows
		for (int row = 0; row < size; row++)
		{
			//Set flag to false
			edgeFound = false;

			//Traverse Columns
			for (int col = 0; col < size; col++)
			{
				//If cell is not null
				//Edge is found
				if (adjMat[row][col] != 0)
				{
					edgeFound = true;
					break;
				}
			}

			//If edge not found
			//Return row
			if (edgeFound == false)
				return row;
		}

		//Return
		return -1;
	}
};

#endif
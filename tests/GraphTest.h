#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>
#include <list>
#include <iomanip>

using namespace std;

class Graph
{
public:
	int numVertices;
	bool isDirected;
	vector<list<pair<int, int>>> adjList;
	vector<Edge> edges;

private:
	Graph(int vertices, bool directed = false)
	{
		numVertices = vertices;
		isDirected = directed;
		adjList.resize(vertices);
	}
};

#endif
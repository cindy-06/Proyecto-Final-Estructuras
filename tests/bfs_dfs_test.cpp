#include "GraphTest.h"
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

void bfs(Graph& g, int startVertex) {
	int v = g.getNumVertices();
	vector <bool> visited(v, false);
	queue<int> q;

	visited[startVertex] = true;
	q.push(startVertex);
}
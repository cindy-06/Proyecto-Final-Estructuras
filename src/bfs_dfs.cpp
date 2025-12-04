#include "Graph.h"
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

void bfs(Graph &g, int startVertex)
{
	int v = g.getNumVertices();
	vector<bool> visited(v, false);
	queue<int> q;

	visited[startVertex] = true;
	q.push(startVertex);

	cout << "BFS iniciando en " << startVertex << ": ";

	while (!q.empty())
	{
		int current = q.front();
		q.pop();
		cout << current << " ";

		const auto &adj = g.getAdjListRaw();
		for (auto const &edge : adj[current])
		{
			int neighbor = edge.first;
			if (!visited[neighbor])
			{
				visited[neighbor] = true;
				q.push(neighbor);
			}
		}
	}
	cout << "\n";
}

void dfsUtil(int v, const vector<list<pair<int, int>>> &adj, vector<bool> &visited)
{
	visited[v] = true;
	cout << v << " ";

	for (auto const &edge : adj[v])
	{
		int neighbor = edge.first;
		if (!visited[neighbor])
		{
			dfsUtil(neighbor, adj, visited);
		}
	}
}

void dfs(Graph &g, int startVertex)
{
	int v = g.getNumVertices();
	vector<bool> visited(v, false);

	cout << "Recorrido DFS iniciando en " << startVertex << ": ";
	const auto& adj = g.getAdjListRaw();
	dfsUtil(startVertex, adj, visited);
	cout << "\n";
}
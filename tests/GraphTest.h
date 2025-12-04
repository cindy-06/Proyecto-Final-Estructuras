#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>
#include <list>
#include <iomanip>

using namespace std;

struct Edge
{
	int src, dest, weight;
};

class Graph
{
protected:
	int numVertices;
	bool isDirected;
	vector<list<pair<int, int>>> adjList;
	vector<Edge> edges;

public:
	Graph(int vertices, bool directed = false)
	{
		numVertices = vertices;
		isDirected = directed;
		adjList.resize(vertices);
	}

	void addEdge(int src, int dest, int weight = 1)
	{
		adjList[src].push_back({dest, weight});
		edges.push_back({src, dest, weight});

		if (!isDirected)
		{
			adjList[dest].push_back({src, weight});
		}
	}

	int getNumVertices() const { return numVertices; }
	
	const vector<list<pair<int, int>>> &getAdjListRaw() const { return adjList; }

	void printAdjList()
	{
		cout << "\n--- Lista de Adyacencia ---\n";
		for (int i = 0; i < numVertices; ++i)
		{
			cout << "Vertice " << i << ":";
			for (auto const &edge : adjList[i])
			{
				cout << " -> (" << edge.first << ", peso: " << edge.second << ")";
			}
			cout << endl;
		}
	}

	vector<vector<int>> getAdjMatrix()
	{
		vector<vector<int>> matrix(numVertices, vector<int>(numVertices, 0));

		for (int i = 0; i < numVertices; i++)
		{
			for (auto const &edge : adjList[i])
			{
				int dest = edge.first;
				int weight = edge.second;
				matrix[i][dest] = weight;
			}
		}
		return matrix;
	}

	vector<vector<int>> getIncidenceMatrix()
	{
		int numEdges = edges.size();
		vector<vector<int>> matrix(numVertices, vector<int>(numEdges, 0));

		for (int j = 0; j < numEdges; j++)
		{
			int u = edges[j].src;
			int v = edges[j].dest;

			if (isDirected)
			{
				matrix[u][j] = 1;
				matrix[v][j] = -1;
			}
			else
			{
				matrix[u][j] = 1;
				matrix[v][j] = 1;
			}
		}
		return matrix;
	}
};
class BipartiteGraph : public Graph {
	private:
		enum Color { red = 42, blu = 24, non = -1 };

		vector<bool> visited;
		vector<int> color;
		vector<int> predecesor;

	public:
		BipartiteGraph(int vertices, bool directed = false) : Graph(vertices, directed) {
			visited = vector<bool>(vertices, false);
			color = vector<int>(vertices, non);
			predecesor = vector<int>(vertices, -1);
		}

		bool color_graph(int v) {
			visited[v] = true;
			for (auto const &edge : adjList[v]) {
				int neighbor = edge.first;
				if (!visited[neighbor]) {
					color[neighbor] = (color[v] == red ? blu : red);
					predecesor[neighbor] = v;
					if (!color_graph(neighbor)) return false;
				} else if (color[neighbor] == color[v]) {
					return false; // conflicto detectado
				}
			}
			return true;
		}

		bool isBipartite() {
			for (int i = 0; i < numVertices; i++) {
				if (!visited[i]) {
					color[i] = red;
					predecesor[i] = -1;
					if (!color_graph(i)) return false;
				}
			}
			return true;
		}
};
#endif
#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>
#include <list>
#include <iomanip>
#include <algorithm>
#include "UnionFind.h"

using namespace std;

struct Edge
{
	int src, dest, weight;

	bool operator<(const Edge &other) const{
		return weight < other.weight;
	}

	bool operator>(const Edge &other) const{
		return weight > other.weight;
	}
};

class Graph
{
protected:
	int numVertices;
	bool isDirected;
	vector<list<pair<int, int>>> adjList;
	vector<Edge> edges;

public:

	static int INF() 
	{
    	return 1000000000; // 1e9
	}

	vector<vector<int>> getAdjMatrixFloyd() 
	{
		int INF_VAL = INF();
		vector<vector<int>> matrix(numVertices, vector<int>(numVertices, INF_VAL));

		for (int i = 0; i < numVertices; i++)
			matrix[i][i] = 0;

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

	vector<Edge> kruskalMST(){
		vector<Edge> result;

		vector<Edge> sortedEdges = edges;

		sort(sortedEdges.begin(), sortedEdges.end(), [](const Edge &a, const Edge &b){
			return a.weight < b.weight;
		});

		UnionFind uf = UnionFind(numVertices);
		
		for(auto &edge: sortedEdges){
			int u = edge.src;
			int v = edge.dest;

			if(uf.find(u) != uf.find(v)) {
				result.push_back(edge);
				uf.unite(u, v);
			}
		}

		return result;
	}

	void printMST(const vector<Edge> &mst) {
    
		cout << "\n--- Árbol de Expansión Mínima (Kruskal) ---\n";
	
		int totalWeight = 0;
    
		for (auto &edge : mst) {
            cout << edge.src << " -- " << edge.dest
                 << " (peso: " << edge.weight << ")\n";
            totalWeight += edge.weight;
        }
    
		cout << "Peso total del MST: " << totalWeight << endl;
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
#include <vector>
#include <queue>
#include <iostream>
#include "../include/GraphTest.h"
#include <string>

using namespace std;

vector<int> dijkstra(const Graph& g, int origen, vector<string>& rutas) {
    int N = g.getNumVertices();
    auto adj = g.getAdjListRaw();

    const int INF = 999999;

    vector<int> dist(N, INF);
    vector<bool> visit(N, false);
    rutas.assign(N, "-");

    dist[origen] = 0;
    rutas[origen] = "a";

    for (int step = 0; step < N; step++) {
        int u = -1, best = INF;

        for (int i = 0; i < N; i++)
            if (!visit[i] && dist[i] < best)
                best = dist[i], u = i;

        visit[u] = true;

        for (auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (!visit[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                rutas[v] = rutas[u] + char('a' + v);
            }
        }
    }

    return dist;
}

#include <iostream>
#include "../include/GraphTest.h"
#include "../include/dijkstra.h"
#include <string>
#include <vector>
using namespace std;

#define INF 999999

int main() {

    Graph g1(6, false); // no dirigido

    g1.addEdge(0, 1, 4);
    g1.addEdge(0, 2, 2);
    g1.addEdge(1, 2, 1);
    g1.addEdge(1, 3, 5);
    g1.addEdge(2, 3, 8);
    g1.addEdge(2, 4, 10);
    g1.addEdge(3, 4, 2);
    g1.addEdge(3, 5, 6);
    g1.addEdge(4, 5, 3);

    int N = g1.getNumVertices();

    vector<int> dist(N, INF);
    vector<bool> visited(N, false);
    vector<string> ruta(N, "-");

    dist[0] = 0;
    ruta[0] = "a";

    auto adj = g1.getAdjListRaw();

    // ----- CABECERA -----
    cout << "Desde\t";
    for (int i = 0; i < N; i++) cout << char('a' + i) << "\t";
    cout << "Peso\tPermanente\tRuta\n";
    cout << "---------------------------------------------------------------\n";

    for (int it = 0; it < N; it++) {

        int u = -1, best = INF;

        // Seleccionar nodo no visitado con menor distancia
        for (int i = 0; i < N; i++)
            if (!visited[i] && dist[i] < best)
                best = dist[i], u = i;

        visited[u] = true;

        // ----- IMPRIMIR FILA DE TABLA EXACTA -----
        cout << char('a' + u) << "\t";

        for (int i = 0; i < N; i++) {
            if (dist[i] == INF) cout << "inf\t";
            else cout << dist[i] << "\t";
        }

        cout << dist[u] << "\t";
        cout << char('a' + u) << "\t";

        // Construir ruta con flechas
        string rb = ruta[u];
        string rutaBonita = "";
        for (int k = 0; k < rb.size(); k++) {
            rutaBonita += rb[k];
            if (k < rb.size() - 1) rutaBonita += " -> ";
        }
        cout << rutaBonita << "\n";

        // ----- RELAJACIÓN -----
        for (auto &edge : adj[u]) {
            int v = edge.first, w = edge.second;

            if (!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                ruta[v] = ruta[u] + char('a' + v);
            }
        }
    }

    return 0;
}

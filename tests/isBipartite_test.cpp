#include "GraphTest.h"
#include <iostream>

#define rojo 42
#define azul 24

using namespace std;

void color_graph(int, const vector<list<pair<int, int>>>&, vector<bool>&,  vector<int> &, vector<int> &);

int main(){ //Prueba de funcion de coloreo y revision

    int vertex1 = 3;
    int vertex2 = 3;

    BipartiteGraph g1 = BipartiteGraph(vertex1); //Grafo que ES bipartito

    g1.addEdge(0, 1); //Se agrega una arista desde 0 a 1
    g1.addEdge(0, 2); //Se agrega una arista desde 0 a 2

    BipartiteGraph g2 = BipartiteGraph(vertex2);  //Grafo que NO ES bipartito

    //Este es un grafo de 3 aristas y 3 vertices, por lo que no es bipartito
    g2.addEdge(0, 1); //Arista de 0 a 1
    g2.addEdge(1, 2); //Arista de 1 a 2
    g2.addEdge(2, 0); //Arista de 2 a 0

    cout << "El grafo 1 " << (g1.isBipartite() ? "es bipartito" : "no es bipartito") << endl;

    cout << "El grafo 2 " << (g2.isBipartite() ? "es bipartito" : "no es bipartito") << endl;

}
#include "GraphTest.h"
#include <iostream>

using namespace std;

int main() {
    Graph g(4, false);
    
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    vector<Edge> mst = g.kruskalMST();
    g.printMST(mst);

    return 0;
}
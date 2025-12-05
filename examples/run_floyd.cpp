#include <iostream>
#include "../include/GraphTest.h"
#include "../include/floyd.h"
using namespace std;

int main()
{
    Graph g(6, false);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 5, 9);
    g.addEdge(1, 2, 5);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 13);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 5, 3);
    g.addEdge(3, 4, 2);
    g.addEdge(3, 5, 5);
    g.addEdge(4, 5, 15);

    vector<vector<int>> matrix = g.getAdjMatrix();

    floydWarshall(matrix);

    return 0;
}

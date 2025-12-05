#include <iostream>
#include "../include/GraphTest.h"
#include "../include/floyd.h"
using namespace std;

int main()
{
    Graph g1(5, false); // no dirigido

    g1.addEdge(0, 1, 2);
    g1.addEdge(0, 2, 5);
    g1.addEdge(1, 2, 3);
    g1.addEdge(1, 3, 4);
    g1.addEdge(2, 3, 1);
    g1.addEdge(3, 4, 7);


    vector<vector<int>> matrix = g1.getAdjMatrix();

    floydWarshall(matrix);

    return 0;
}

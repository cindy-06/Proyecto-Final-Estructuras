#include <iostream>
#include "../include/GraphTest.h"
#include "../include/floyd.h"
using namespace std;

int main()
{
    Graph g2(6, true); // dirigido

    g2.addEdge(0, 1, 3);
    g2.addEdge(0, 2, 8);
    g2.addEdge(1, 3, 2);
    g2.addEdge(2, 4, 1);
    g2.addEdge(3, 2, 4);
    g2.addEdge(3, 5, 6);
    g2.addEdge(4, 5, 2);



    vector<vector<int>> matrix = g2.getAdjMatrix();

    floydWarshall(matrix);

    return 0;
}

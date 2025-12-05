#include <iostream>
#include "../include/GraphTest.h"
#include "../include/floyd.h"
using namespace std;

int main()
{
    Graph g3(4, false); // no dirigido

g3.addEdge(0, 1);
g3.addEdge(0, 2);
g3.addEdge(1, 2);
g3.addEdge(2, 3);




    vector<vector<int>> matrix = g3.getAdjMatrix();

    floydWarshall(matrix);

    return 0;
}

#include "../include/floyd.h"
#include <iostream>
using namespace std;

#define INF 999999

void floydWarshall(vector<vector<int>> matrix)
{
    int n = matrix.size();

    // Convertir ceros a infinito (menos diagonal)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && matrix[i][j] == 0)
                matrix[i][j] = INF;
        }
    }

    // Algoritmo Floyd–Warshall (referencia exacta a tu código)
    for (int k = 0; k < n; k++)       // Nodo intermedio
    {
        for (int i = 0; i < n; i++)   // Nodo origen
        {
            for (int j = 0; j < n; j++) // Nodo destino
            {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    // Mostrar resultado
    cout << "\n===== MATRIZ DE DISTANCIAS MINIMAS (FLOYD-WARSHALL) =====\n\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == INF)
                cout << "INF\t";
            else
                cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
}

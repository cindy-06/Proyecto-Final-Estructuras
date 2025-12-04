#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>
#include <string>
class Graph; // Declaración adelantada

// Devuelve distancias mínimas desde un origen y actualiza rutas
std::vector<int> dijkstra(const Graph& g, int origen, std::vector<std::string>& rutas);

#endif
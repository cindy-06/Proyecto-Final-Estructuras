# Proyecto Final Estructura de Datos

# Graph Library (Graph.h)

Esta librería implementa una clase `Graph` en C++ que permite representar grafos mediante **listas de adyacencia**, **matrices de adyacencia** y **matrices de incidencia**.  
Además, incluye métodos y algoritmos clásicos de grafos: **BFS, DFS, Dijkstra, Floyd–Warshall y Kruskal**.

---

## 📌 Características principales
- Representación de grafos dirigidos y no dirigidos.
- Almacenamiento mediante lista de adyacencia.
- Generación de:
  - Matriz de adyacencia.
  - Matriz de incidencia.
- Recorridos fundamentales: BFS y DFS.
- Algoritmos de caminos mínimos: Dijkstra y Floyd–Warshall.
- Árbol de expansión mínima: Kruskal (con Union-Find).

---

## 🚀 Uso básico

### 1. Incluir la librería
```{cpp}
#include "Graph.h"

//Crear Grafos
Graph g(5, false); // grafo no dirigido con 5 vértices
Graph gDir(4, true); // grafo dirigido con 4 vértices

//Agregar aristas
g.addEdge(0, 1, 10);
g.addEdge(0, 2, 5);
g.addEdge(1, 3, 2);
g.addEdge(2, 4, 7);

```

## 📖 Sección 2: Dijkstra

### Descripción
Encuentra las distancias mínimas desde un vértice origen hacia todos los demás.  
Complejidad: \(O(N^2 + E)\).

# 📖 Sección 3: Floyd–Warshall
### Descripción
Calcula las distancias mínimas entre todos los pares de vértices.
Complejidad: O\(V^3\).

# 📖 Sección 4: Union-Find (para Kruskal)
### Descripción
Estructura de conjuntos disjuntos usada en el algoritmo de Kruskal para construir el árbol de expansión mínima (MST).
Operaciones casi constantes gracias a compresión de caminos y unión por rango.

# 📌 Conclusiones
Con esta librería puedes:
- Representar grafos en distintas formas.
- Recorrerlos con BFS y DFS.
- Calcular caminos mínimos con Dijkstra y Floyd–Warshall.
- Construir árboles de expansión mínima con Kruskal y Union-Find.



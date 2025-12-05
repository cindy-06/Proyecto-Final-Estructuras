# Proyecto-Final-Estructuras

# 📘 Proyecto: Algoritmos de Grafos en C++

Este proyecto implementa múltiples estructuras y algoritmos clásicos de grafos utilizando C++.
Incluye representaciones de grafos, algoritmos de recorrido, caminos mínimos, árboles de expansión mínima y detección de bipartición.

# 🛠️ Requisitos

Compilador compatible con C++11 o superior
(g++, clang++, MinGW, etc.)

No se requiere ninguna librería externa.

⭐ ¿Cómo funcionan los programas?

A continuación se explica lo que hace cada uno de los módulos, cómo funciona internamente el algoritmo y qué se puede esperar como salida.

# 🔹 1. Estructuras base
### 🧩 Graph.h

Define un grafo usando listas de adyacencia.
Permite:

Agregar aristas (dirigidas o no dirigidas).

Generar:

Matriz de adyacencia

Matriz de incidencia

Obtener todas las aristas

Estructuras auxiliares como Edge y UnionFind

También incluye:

### 🟦 BipartiteGraph

Clase derivada usada para verificar si un grafo es bipartito, coloreando el grafo usando DFS.

# 🔹 2. BFS y DFS — bfs_dfs.cpp
### 🟩 ¿Qué hace BFS?

Recorre el grafo por niveles, utilizando una cola:

Inicia en un vértice dado.

Visita primero todos los vecinos directos.

Luego los vecinos de esos vecinos.

### 📤 Salida:
Imprime el orden en que los vértices son visitados, por ejemplo:

BFS iniciando en 0: 0 1 2 3

### 🟦 ¿Qué hace DFS?

Recorre el grafo en profundidad utilizando recursión:

Entra a un nodo.

Sigue avanzando por un vecino no visitado hasta donde pueda.

Retrocede (backtracking).

### 📤 Salida:

Recorrido DFS iniciando en 0: 0 2 3 1

# 🔹 3. Algoritmo de Dijkstra — dijkstra.cpp

Calcula las distancias mínimas desde un nodo origen hacia todos los demás.

### 🧠 ¿Cómo funciona?

Inicializa todas las distancias como infinito.

Selecciona el nodo no visitado con la menor distancia.

Relaja sus aristas.

Guarda una cadena que representa la ruta seguida (por ejemplo, "abc").

### 📤 Salida esperada (depende del grafo):

Vector de distancias mínimas.

Vector de rutas como cadenas (si lo integras en un main).

# 🔹 4. Floyd–Warshall — floyd.cpp

Calcula todas las distancias mínimas entre todos los pares de vértices.

### 🧠 ¿Cómo funciona?

Convierte ceros no diagonal en infinito.

Para cada nodo intermedio k:

Intenta mejorar el camino i → j usando i → k → j.

### 📤 Salida:

Una matriz impresa como:

===== MATRIZ DE DISTANCIAS MINIMAS (FLOYD-WARSHALL) =====

0   5   7
5   0   3
7   3   0


Los valores INF indican que no existe camino.

# 🔹 5. Kruskal — kruskal_test.cpp

Construye un Árbol de Expansión Mínima (MST) usando el algoritmo de Kruskal.

### 🧠 ¿Cómo funciona?

Ordena todas las aristas por peso.

Las recorre en orden ascendente.

Usa Union-Find para evitar ciclos.

Agrega al MST solo las aristas seguras.

### 📤 Salida:

--- Árbol de Expansión Mínima (Kruskal) ---
2 -- 3 (peso: 4)
0 -- 3 (peso: 5)
0 -- 1 (peso: 10)
Peso total del MST: 19

# 🔹 6. Verificación de Bipartición — bipartite_test.cpp

Prueba la clase BipartiteGraph.

### 🧠 ¿Cómo funciona?

Intenta colorear el grafo con 2 colores usando DFS.

Si encuentra un vértice vecino del mismo color → no es bipartito.

Detecta ciclos impares.

### 📤 Salida:

El grafo 1 es bipartito
El grafo 2 no es bipartito
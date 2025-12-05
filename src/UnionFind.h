#ifndef UNIONFIND_H
#define UNIONFIND_H

#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
    private:
        vector<int> parent;
        vector<int> rank;

    public:
        // Constructor: inicializa n conjuntos disjuntos
        UnionFind(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; i++) {
                parent[i] = i; // cada nodo es su propio padre
            }
        }

        // Encuentra el representante del conjunto con compresión de caminos
        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]); // compresión de caminos
            }
            return parent[x];
        }

        // Une dos conjuntos por rango
        void unite(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);

            if (rootX == rootY) return; // ya están en el mismo conjunto

            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }   
};

#endif
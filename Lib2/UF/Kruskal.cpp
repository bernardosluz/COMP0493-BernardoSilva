// kruskal.cpp

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge {
public:
    int u, v, weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

class UnionFind {
    vector<int> parent, rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

bool compareEdges(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}

void kruskal(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), compareEdges);

    UnionFind uf(V);
    int mstWeight = 0;

    for (auto& edge : edges) {
        int u = edge.u;
        int v = edge.v;

        if (uf.find(u) != uf.find(v)) {
            uf.unionSets(u, v);
            mstWeight += edge.weight;
            cout << "Aresta incluída: (" << u << ", " << v << ") com peso " << edge.weight << endl;
        }
    }

    cout << "Peso total da Árvore Geradora Mínima: " << mstWeight << endl;
}

int main() {
    vector<Edge> edges = {
        Edge(0, 1, 10),
        Edge(0, 2, 6),
        Edge(0, 3, 5),
        Edge(1, 3, 15),
        Edge(2, 3, 4)
    };

    kruskal(4, edges);
    return 0;
}

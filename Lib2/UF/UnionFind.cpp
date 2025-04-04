// union_find.cpp

#include <iostream>
#include <vector>
using namespace std;

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
            parent[x] = find(parent[x]); // Path compression
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

int main() {
    UnionFind uf(5);
    uf.unionSets(0, 1);
    uf.unionSets(1, 2);

    cout << "Elemento 0 e 2 estão na mesma componente? " << (uf.find(0) == uf.find(2) ? "Sim" : "Não") << endl;
    cout << "Elemento 0 e 3 estão na mesma componente? " << (uf.find(0) == uf.find(3) ? "Sim" : "Não") << endl;

    return 0;
}

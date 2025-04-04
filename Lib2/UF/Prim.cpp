// prim.cpp

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Graph {
    int V;
    vector<vector<pair<int, int>>> adj;

public:
    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    void prim() {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> key(V, INT_MAX), parent(V, -1);
        vector<bool> inMST(V, false);

        pq.push({0, 0});
        key[0] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            inMST[u] = true;

            for (auto& edge : adj[u]) {
                int v = edge.first, weight = edge.second;

                if (!inMST[v] && key[v] > weight) {
                    key[v] = weight;
                    pq.push({key[v], v});
                    parent[v] = u;
                }
            }
        }

        int totalWeight = 0;
        for (int i = 1; i < V; i++) {
            if (parent[i] != -1) {
                cout << "Aresta incluída: (" << parent[i] << ", " << i << ") com peso " << key[i] << endl;
                totalWeight += key[i];
            }
        }
        cout << "Peso total da Árvore Geradora Mínima: " << totalWeight << endl;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 2, 3);
    g.addEdge(2, 3, 5);
    
    g.prim();
    return 0;
}

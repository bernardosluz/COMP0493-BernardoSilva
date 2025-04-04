// ford_fulkerson.cpp

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> capacity;
    vector<vector<int>> adj;

    Graph(int V) {
        this->V = V;
        capacity.resize(V, vector<int>(V, 0));
        adj.resize(V);
    }

    void addEdge(int u, int v, int cap) {
        capacity[u][v] = cap;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int bfs(int source, int sink, vector<int>& parent) {
        vector<bool> visited(V, false);
        visited[source] = true;
        parent[source] = -1;

        vector<int> queue;
        queue.push_back(source);

        while (!queue.empty()) {
            int u = queue.front();
            queue.erase(queue.begin());

            for (int v : adj[u]) {
                if (!visited[v] && capacity[u][v] > 0) {
                    queue.push_back(v);
                    parent[v] = u;
                    visited[v] = true;
                    if (v == sink)
                        return true;
                }
            }
        }
        return false;
    }

    int fordFulkerson(int source, int sink) {
        vector<int> parent(V, -1);
        int maxFlow = 0;

        while (bfs(source, sink, parent)) {
            int pathFlow = INT_MAX;
            for (int v = sink; v != source; v = parent[v]) {
                int u = parent[v];
                pathFlow = min(pathFlow, capacity[u][v]);
            }

            for (int v = sink; v != source; v = parent[v]) {
                int u = parent[v];
                capacity[u][v] -= pathFlow;
                capacity[v][u] += pathFlow;
            }

            maxFlow += pathFlow;
        }
        return maxFlow;
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1, 16);
    g.addEdge(0, 2, 13);
    g.addEdge(1, 2, 10);
    g.addEdge(1, 3, 12);
    g.addEdge(2, 1, 4);
    g.addEdge(2, 4, 14);
    g.addEdge(3, 2, 9);
    g.addEdge(3, 5, 20);
    g.addEdge(4, 3, 7);
    g.addEdge(4, 5, 4);

    cout << "Max Flow: " << g.fordFulkerson(0, 5) << endl;

    return 0;
}

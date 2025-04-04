// dinic.cpp

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> capacity;
    vector<vector<int>> adj;
    vector<int> level;

    Graph(int V) {
        this->V = V;
        capacity.resize(V, vector<int>(V, 0));
        adj.resize(V);
        level.resize(V);
    }

    void addEdge(int u, int v, int cap) {
        capacity[u][v] = cap;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool bfs(int source, int sink) {
        fill(level.begin(), level.end(), -1);
        level[source] = 0;

        queue<int> q;
        q.push(source);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (level[v] < 0 && capacity[u][v] > 0) {
                    level[v] = level[u] + 1;
                    if (v == sink) return true;
                    q.push(v);
                }
            }
        }
        return false;
    }

    int dfs(int u, int sink, int flow) {
        if (u == sink) return flow;

        for (int v : adj[u]) {
            if (level[v] == level[u] + 1 && capacity[u][v] > 0) {
                int curFlow = min(flow, capacity[u][v]);
                int tempFlow = dfs(v, sink, curFlow);

                if (tempFlow > 0) {
                    capacity[u][v] -= tempFlow;
                    capacity[v][u] += tempFlow;
                    return tempFlow;
                }
            }
        }
        return 0;
    }

    int dinic(int source, int sink) {
        int maxFlow = 0;

        while (bfs(source, sink)) {
            while (true) {
                int flow = dfs(source, sink, INT_MAX);
                if (flow == 0) break;
                maxFlow += flow;
            }
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

    cout << "Max Flow: " << g.dinic(0, 5) << endl;

    return 0;
}

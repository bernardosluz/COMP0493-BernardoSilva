#include <iostream>
#include <list>
#include <utility>
#include <unordered_map>

using namespace std;

/*
*   Estrutura para representar um Grafo.
*   Vai conter o vértice e uma lista com
*   os vizinhos dele e o peso dessa aresta
*/ 
struct Graph {
    unordered_map<char, list<pair<char, int>>> graph;
};

// Função para imprimir o grafo
void printGraph(const Graph& g) {
    for (const auto& vertice : g.graph) { 
        cout << vertice.first << " -> ";
        
        for (const auto& neighbor : vertice.second) {  
            cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
        }
        
        cout << endl;
    }
}

// Função para adicionar uma aresta não direcionada entre dois vértices
void addAresta(Graph &g, char vertice1, char vertice2, int weight) {
    g.graph[vertice1].push_back(make_pair(vertice2, weight)); // Aresta de vertice1 para vertice2
    g.graph[vertice2].push_back(make_pair(vertice1, weight)); // Aresta de vertice2 para vertice1
}

int main() {
    Graph g;
    // Adicionando arestas
    addAresta(g, 'A', 'B', 1);
    addAresta(g, 'A', 'C', 1);
    addAresta(g, 'B', 'D', 1);
    addAresta(g, 'C', 'D', 1);

    // Exibindo o grafo
    printGraph(g);

    return 0;
}

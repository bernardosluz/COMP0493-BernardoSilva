#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

struct Graph {
    unordered_map<char, pair<bool, list<pair<char, int>>>> graph;
};

// Função para imprimir o grafo
void printGraph(const Graph& g) {
    for (const auto& vertice : g.graph) { 
        cout << vertice.first << " -> ";
        
        // Acessamos a lista de adjacência que está no par do vértice
        for (const auto& neighbor : vertice.second.second) {  
            cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
        }
        
        cout << endl;
    }
}

// Função para adicionar uma aresta não direcionada entre dois vértices
void addAresta(Graph &g, char vertice1, char vertice2, int weight) {
    // Se o vértice ainda não existir, inicializamos a lista de adjacência corretamente
    // No unordered_map graph.end indica o final do mapa
    if (g.graph.find(vertice1) == g.graph.end()) {
        g.graph[vertice1] = make_pair(false, list<pair<char, int>>());
    }
    if (g.graph.find(vertice2) == g.graph.end()) {
        g.graph[vertice2] = make_pair(false, list<pair<char, int>>());
    }
    
    // Adicionamos as arestas
    g.graph[vertice1].second.push_back(make_pair(vertice2, weight)); // Aresta de vertice1 para vertice2
    g.graph[vertice2].second.push_back(make_pair(vertice1, weight)); // Aresta de vertice2 para vertice1
}

void listDeepFirstSearch(Graph &g, char begin, char ancestral){
    g.graph[begin].first = true;
    auto &it = g.graph[begin].second; 
    for(auto &neighbor : it){
        if(!g.graph[neighbor.first].first){
            //visitar aresta de árvore;
            cout << "visitar aresta de arvore: " << begin << "->" << neighbor.first << endl;
            listDeepFirstSearch(g, neighbor.first, begin);
        } else if(neighbor.first != ancestral){
            if(ancestral != ' '){
                //visitar aresta de retorno;
                cout << "visitar aresta de retorno: " << begin << "->" << neighbor.first << endl;
            }
        }
    }
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
    listDeepFirstSearch(g, 'A', ' ');

    return 0;
}

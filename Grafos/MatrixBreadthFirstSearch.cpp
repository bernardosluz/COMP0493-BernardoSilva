#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void printMatrix(vector<vector<int>> &mat){
    int V = mat.size();
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            cout << mat[i][j]<< " ";
        }
        cout << endl;
    }
}

void breadthFirstSearch(vector<vector<int>> &g, int begin){
    deque<int> searchDeque;
    vector<bool> visited(g.size(), false); // Vetor para marcar os vértices visitados

    searchDeque.push_back(begin);
    visited[begin] = true; // Marca o vértice inicial como visitado

    while (!searchDeque.empty()){
        int vertice = searchDeque.front();
        searchDeque.pop_front();

        for (int i = 0; i < g.size(); i++){
            if (g[vertice][i] != 0 && !visited[i]){ // Se há aresta e o vértice não foi visitado
                //Visitar aresta
                cout << "Visitar aresta " << vertice << "->" << i << endl;
                visited[i] = true;  // Marca como visitado
                searchDeque.push_back(i); // Adiciona o vértice à fila para explorar depois
            }
        }
    }
}

int main(){
    // Cria um grafo com 4 vértices
    vector<vector<int>> graph = {
    {0, 1, 0, 0}, 
    {1, 0, 1, 0}, 
    {0, 1, 0, 1}, 
    {0, 0, 1, 0}
};

    cout << "Matriz de Adjacencia" << endl;
    printMatrix(graph);

    cout << "\nExecutando BFS a partir do vertice 0:\n";
    breadthFirstSearch(graph, 0);

    return 0;
}

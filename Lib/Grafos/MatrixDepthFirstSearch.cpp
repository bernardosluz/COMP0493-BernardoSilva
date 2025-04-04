#include <iostream>
#include <vector>

using namespace std;

// Matriz que representa um grafo não direcionado e sem peso
void addEdge(vector<vector<int>> &mat, int i, int j)
{
    mat[i][j] = 1;
    mat[j][i] = 1;
}

void printMatrix(vector<vector<int>> &mat)
{
    int V = mat.size();
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

// Busca em profundidade corrigida (DFS)
void deepFirstSearch(vector<vector<int>> &g, int begin, int ancestral, vector<bool> &explored)
{
    explored[begin] = true; // Marca o vértice como explorado

    for (int i = 0; i < g.size(); i++)
    {
        if (g[begin][i] != 0) // Existe uma aresta entre 'begin' e 'i'
        {
            if (!explored[i])
            {
                // Visitar aresta de árvore
                cout << "Visitar aresta de arvore: " << begin << " -> " << i << endl;
                deepFirstSearch(g, i, begin, explored);
            }
            else if (i != ancestral)
            {
                // Visitar aresta de retorno
                cout << "Visitar aresta de retorno: " << begin << " -> " << i << endl;
            }
        }
    }
}

int main()
{
    // Cria um grafo com 4 vértices
    vector<vector<int>> graph = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 0}};

    cout << "Matriz de Adjacencia" << endl;
    printMatrix(graph);

    vector<bool> explored(graph.size(), false); 
    deepFirstSearch(graph, 0, -1, explored);   

    return 0;
}

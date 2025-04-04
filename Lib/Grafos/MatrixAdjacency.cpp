#include <iostream>
#include <vector>

using namespace std;

// Matriz que representa um grafo não direcionado e sem peso
void addEdge(vector<vector<int>> &mat, int i, int j)
{
    mat[i][j] = 1;
    mat[j][i] = 1;
}

/*
// Para grafos direcionados e sem peso
void addEdge(vector<vector<int>> &mat, int i, int j)
{
    mat[i][j] = 1;
}
*/

/*
// Para grafos não direcionados e com peso
void addEdge(vector<vector<int>> &mat, int i, int j, int weigh)
{
    mat[i][j] = weigh;
    mat[j][i] = weigh;
}
*/

/*
// Para grafos direcionados e com peso
void addEdge(vector<vector<int>> &mat, int i, int j, int weigh)
{
    mat[i][j] = weigh;
}
*/
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

int main()
{
    //Cria um grafo com 4 vértices
    int vertices = 4;
    vector<vector<int>> graph(vertices, vector<int>(vertices, 0));

    // Now add edges one by one
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

/*
*   Modo alternativo para criar a matriz
*   que representa o grafo:
*   vector<vector<int>> graph = {{ 0, 1, 0, 0 },
*                              { 1, 0, 1, 0 },
*                              { 0, 1, 0, 1 },
*                              { 0, 0, 1, 0 } };
*/

    cout << "Matriz de Adjacencia" << endl;
    printMatrix(graph);

    return 0;
}
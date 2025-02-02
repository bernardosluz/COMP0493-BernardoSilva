#include <iostream>
#include <vector>
#include <algorithm> // Para usar o std::max

using namespace std;

// Função para resolver o problema da mochila (Knapsack)
int knapsack(const vector<int>& weights, const vector<int>& values, int n, int capacity) {

    // Criando a tabela de Programação Dinâmica (DP)
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Preenchendo a tabela usando o algoritmo de Programação Dinâmica
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= capacity; j++) {
            if (weights[i - 1] <= j) { // Se o item pode ser adicionado à mochila
                dp[i][j] = max(dp[i - 1][j], values[i - 1] + dp[i - 1][j - weights[i - 1]]);
            } else {
                dp[i][j] = dp[i - 1][j]; // Caso contrário, não adicionamos o item
            }
        }
    }

    // O valor máximo estará na célula dp[n][capacity]
    return dp[n][capacity];
}

int main() {
    // Definindo os dados diretamente (sem precisar de entrada do usuário)
    int n = 4; // Número de itens
    int capacity = 5; // Capacidade da mochila

    // Pesos dos itens
    vector<int> weights = {2, 3, 4, 5};

    // Valores dos itens
    vector<int> values = {3, 4, 5, 6};

    // Chama a função para calcular o valor máximo da mochila
    cout << "O valor maximo obtido = " << knapsack(weights, values, n, capacity) << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm> // Para usar a função max

using namespace std;

// Função para calcular a máxima coleta de moedas no grid
int robotCoinCollection(const vector<vector<int>>& grid, int rows, int cols) {
    // Cria uma matriz para armazenar o valor máximo de coleta de moedas
    vector<vector<int>> dp(rows, vector<int>(cols));

    // Inicializa o valor inicial (primeira célula)
    dp[0][0] = grid[0][0];

    // Preenche a primeira linha, pois o robô só pode mover-se para a direita
    for (int j = 1; j < cols; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    // Preenche a primeira coluna, pois o robô só pode mover-se para baixo
    for (int i = 1; i < rows; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    // Preenche o restante da matriz dp, levando em consideração as duas direções possíveis (direita e para baixo)
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }

    // Retorna o valor máximo encontrado na célula inferior direita
    return dp[rows - 1][cols - 1];
}

int main() {
    // Definindo um grid de exemplo com valores de moedas
    vector<vector<int>> grid = {
        {0, 2, 4, 1},
        {3, 4, 0, 2},
        {1, 2, 5, 6},
        {2, 3, 2, 0}
    };

    int rows = grid.size();    // Número de linhas
    int cols = grid[0].size(); // Número de colunas

    // Exibe o grid
    cout << "Grid de moedas:" << endl;
    for (const auto& row : grid) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Chama a função para calcular a máxima coleta de moedas
    int result = robotCoinCollection(grid, rows, cols);

    // Exibe o resultado final
    cout << "\nMaxima coleta de moedas: " << result << endl;

    return 0;
}
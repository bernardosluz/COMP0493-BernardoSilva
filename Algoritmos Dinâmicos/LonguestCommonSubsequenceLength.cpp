#include <iostream>
#include <vector>

using namespace std;

// Estrutura que contém o valor e a direção da célula na tabela
struct Cell {
    int value;
    int direction; // 9 = diagonal, 8 = cima, 6 = esquerda
};

// Função para calcular a Longest Common Subsequence (LCS)
vector<vector<Cell>> lcsLength(const vector<int>& X, const vector<int>& Y, int m, int n) {
    // Criando a tabela para armazenar os valores e as direções
    vector<vector<Cell>> table(m + 1, vector<Cell>(n + 1));

    // Inicializando a primeira linha e primeira coluna
    for (int i = 0; i <= m; ++i) {
        table[i][0].value = 0;
        table[i][0].direction = 5; // Valor arbitrário para representar "não usado"
    }
    for (int j = 0; j <= n; ++j) {
        table[0][j].value = 0;
        table[0][j].direction = 5;
    }

    // Preenchendo a tabela de acordo com a comparação dos elementos
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (X[i - 1] == Y[j - 1]) { // Se os elementos são iguais
                table[i][j].value = table[i - 1][j - 1].value + 1;
                table[i][j].direction = 9; // Direção diagonal
            } else if (table[i - 1][j].value >= table[i][j - 1].value) {
                table[i][j].value = table[i - 1][j].value;
                table[i][j].direction = 8; // Direção cima
            } else {
                table[i][j].value = table[i][j - 1].value;
                table[i][j].direction = 6; // Direção esquerda
            }
        }
    }

    return table;
}

// Função recursiva para imprimir a Longest Common Subsequence (LCS)
void printLCS(const vector<vector<Cell>>& table, const vector<int>& X, int i, int j) {
    if (i == 0 || j == 0) {
        return; // Caso base: se chegamos à borda da tabela, interrompemos a recursão
    }
    if (table[i][j].direction == 9) { // Se a direção for diagonal
        printLCS(table, X, i - 1, j - 1); // Chamamos recursivamente
        cout << X[i - 1] << " "; // Imprime o valor da LCS
    } else if (table[i][j].direction == 8) {
        printLCS(table, X, i - 1, j); // Move para cima
    } else {
        printLCS(table, X, i, j - 1); // Move para a esquerda
    }
}

int main() {
    // Inicializando as sequências X e Y
    vector<int> X = {1, 0, 0, 1, 0, 1, 0, 1, 0};
    vector<int> Y = {0, 1, 0, 1, 1, 0, 1, 1};
    int m = X.size();
    int n = Y.size();

    // Calcula a tabela LCS
    vector<vector<Cell>> result = lcsLength(X, Y, m, n);

    // Imprime a sequência Y acima da tabela
    cout << "   ";
    for (int j = 0; j < n; ++j) {
        cout << " " << Y[j] << " ";
    }
    cout << endl;

    // Imprime a tabela com os valores e as direções
    for (int i = 0; i <= m; ++i) {
        if (i > 0)
            cout << X[i - 1] << " "; // Imprime X na lateral
        else
            cout << "  ";
        for (int j = 0; j <= n; ++j) {
            cout << "(" << result[i][j].value << ", " << result[i][j].direction << ") ";
        }
        cout << endl;
    }

    // Imprime a Longest Common Subsequence (LCS)
    cout << "\nLCS: ";
    printLCS(result, X, m, n);
    cout << endl;

    return 0;
}
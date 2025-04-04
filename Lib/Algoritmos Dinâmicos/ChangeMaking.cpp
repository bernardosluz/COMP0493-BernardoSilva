#include <iostream>
#include <vector>
#include <climits>

#define min(a,b) ((a) < (b) ? (a) : (b))

using namespace std;

const int INF = INT_MAX;  // Definindo infinito como o valor máximo possível de um inteiro

// Função de otimização para o problema de troco (change making problem)
// F(n) = min {F(n - dj)} + 1 para n > 0, n >= dj
// F(0) = 0
int changeMaking(const vector<int>& denominations, int numDenominations, int amount) {
    vector<int> dp(amount + 1, INF);  // Vetor para armazenar o número mínimo de cédulas para cada valor de troco
    dp[0] = 0;  // F(0) = 0, ou seja, nenhum valor de troco precisa de cédulas

    // Preenche a tabela dp com o número mínimo de cédulas para cada valor de troco
    for (int i = 1; i <= amount; i++) {
        for (int j = 1; j < numDenominations; j++) {
            // Se o valor atual de troco é maior ou igual ao valor da cédula, tentamos usá-la
            if (i >= denominations[j]) {
                dp[i] = min(dp[i], dp[i - denominations[j]] + 1);
            }
        }
        // Exibe o valor de dp[i] a cada iteração
        cout << dp[i] << " ";
    }

    return dp[amount];  // Retorna o número mínimo de cédulas para o valor de troco desejado
}

int main() {
    // Definindo valores fixos para as cédulas e o valor a ser feito
    vector<int> denominations = {0, 1, 5, 10, 25}; // Cédulas disponíveis: 1, 5, 10, 25
    int amount = 63; // Valor a ser feito

    // Número de cédulas (ajustado para incluir a posição 0)
    int numDenominations = denominations.size();

    // Chama a função para calcular o número mínimo de cédulas
    int result = changeMaking(denominations, numDenominations, amount);

    // Exibe o resultado final
    cout << "\nNumero minimo de cedulas: " << result << endl;

    return 0;
}
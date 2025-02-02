#include <iostream>
#include <vector>
#include <algorithm>  // Para utilizar a função max

using namespace std;

// Função para resolver o problema do corte de haste
int rodCutting(const vector<int>& prices, int n) {
    // Vetor para armazenar os valores máximos possíveis para cada comprimento de haste
    vector<int> dp(n + 1, 0);
    
    // Itera sobre todos os comprimentos possíveis de haste
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i] = max(dp[i], prices[j - 1] + dp[i - j]);
        }
    }
    
    // Exibe os valores máximos de cada comprimento (apenas para visualização)
    for (int i = 0; i <= n; ++i) {
        cout << dp[i] << " ";
    }
    cout << endl;

    // Retorna o valor máximo para o comprimento total da haste
    return dp[n];
}

int main() {
    // Definindo os preços das hastes (preços para comprimentos 1, 2, 3, ...)
    vector<int> prices = {2, 5, 7, 3, 9};  // Exemplo de preços para cada comprimento de haste
    
    // Definindo o comprimento da haste
    int length = 5;
    
    // Calculando o valor máximo que pode ser obtido
    int result = rodCutting(prices, length);
    
    // Exibindo o resultado final
    cout << "Maximo valor obtido: " << result << endl;
    
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm> // Para usar a função max

using namespace std;

// F(n) = max {cn + F(n-2), F(n-1)} for n > 1,
// F(0) = 0 , F(1) = c1

int coinRow(const vector<int>& C, int n) {
    vector<int> F(n); // Vetor para armazenar os valores de F

    F[0] = 0; // F(0) = 0
    F[1] = C[1]; // F(1) = c1 (primeiro valor da sequência de moedas)

    cout << F[0] << " " << F[1] << " "; // Imprime os dois primeiros valores de F

    // Preenche o vetor F com o valor máximo para cada índice
    for (int i = 2; i < n; i++) {
        F[i] = max(C[i] + F[i - 2], F[i - 1]); // Calcula F(i) com a fórmula
        cout << F[i] << " "; // Imprime o valor de F[i]
    }

    return F[n - 1]; // Retorna o valor final de F(n-1)
}

int main() {
    // Exemplo fixo de valores de moedas
    vector<int> coins = {0, 5, 1, 10, 2, 3}; // O valor da primeira posição é 0 (não vale nada)
    
    int result = coinRow(coins, coins.size()); // Chama a função coinRow
    cout << "\n" << result << endl; // Imprime o resultado final

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> // para usar o round

using namespace std;

/*
*
*   A função round() em C++ é usada para arredondar valores de ponto flutuante (float ou double)
*   para o inteiro mais próximo. Se o número estiver exatamente no meio (por exemplo, 2.5),
*   ele será arredondado para o número inteiro mais próximo no sentido positivo ou negativo,
*   dependendo da direção.
*   Funcionamento:
*   Se a parte decimal for menor que 0.5, o valor será arredondado para baixo.
*   Exemplo: round(2.3) resulta em 2.
*
*/

// Função para imprimir o vetor de forma legível, mostrando os elementos e sua quantidade
template <typename T>
void printVector(const vector<T>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i != vec.size() - 1) {
            cout << ", "; // Adiciona vírgula entre os elementos
        }
    }
    cout << "]" << endl;
    cout << "Quantidade do troco: " << vec.size() << endl; // Mostra o número de moedas ou notas utilizadas
}

// Função de comparação para ordenar o vetor de moedas/notas em ordem decrescente
bool compare(const double& coin1, const double& coin2) {
    return coin1 > coin2; 
}

// Função que calcula o troco
vector<double> coinChange(vector<double> change, double value) {
    int size = change.size();
    int i = 0; 
    vector<double> exchanged; 

    // Enquanto o valor restante for diferente de 0 e ainda houver moedas disponíveis
    while (value > 0 && i < size) {
        if (change[i] <= value) {
            exchanged.push_back(change[i]); // Adiciona a moeda/note ao troco
            value -= change[i]; // Reduz o valor restante
            value = round(value * 100) / 100; // Corrige possíveis erros de ponto flutuante
        } else {
            i++; // Passa para a próxima moeda/nota
        }
    }

    // Verifica se o valor não foi zerado (caso o troco não seja possível)
    if (value > 0) {
        cout << "Troco total impossivel" << endl;
        exchanged.push_back(value);
        return exchanged;
    }

    return exchanged;
}

int main() {
    // Vetor de moedas/notas disponíveis
    vector<double> change = {0.1, 0.25, 0.5, 1, 2, 5, 10, 20, 50, 100, 200};
    double value = 225.99; // Valor do troco que deve ser calculado

    // Ordena as moedas
    sort(change.begin(), change.end(), compare);

    // Calcula o troco
    vector<double> exchanged = coinChange(change, value);

    // Notas usadas e a quantidade do troco
    printVector(exchanged);

    return 0;
}

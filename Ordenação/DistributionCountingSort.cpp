#include <iostream>
#include <vector>

using namespace std;

// Função de ordenação por contagem de distribuição
vector<int> distributionCountingSort(const vector<int>& inputArray, int lowerBound, int upperBound) {
    int range = upperBound - lowerBound + 1;

    // Vetor auxiliar para contar a frequência de cada elemento
    vector<int> frequency(range, 0);

    // Contando a frequência de cada elemento no intervalo [lowerBound, upperBound]
    for (int value : inputArray) {
        frequency[value - lowerBound]++;
    }

    // Calculando os índices cumulativos no vetor de frequência
    for (int i = 1; i < range; i++) {
        frequency[i] += frequency[i - 1];
    }

    // Vetor para armazenar o resultado ordenado
    vector<int> sortedArray(inputArray.size());

    // Preenchendo o vetor ordenado a partir do final do vetor original
    for (int i = inputArray.size() - 1; i >= 0; i--) {
        int index = inputArray[i] - lowerBound;
        sortedArray[frequency[index] - 1] = inputArray[i];
        frequency[index]--; // Reduz o contador para o próximo elemento igual
    }

    return sortedArray;
}

int main() {
    // Exemplo de uso
    vector<int> array = {5, 2, 9, 7, 2, 3, 7};
    int lowerBound = 2; // Menor valor no intervalo
    int upperBound = 9; // Maior valor no intervalo

    vector<int> sortedArray = distributionCountingSort(array, lowerBound, upperBound);

    cout << "Array ordenado: ";
    for (int value : sortedArray) {
        cout << value << " ";
    }

    return 0;
}

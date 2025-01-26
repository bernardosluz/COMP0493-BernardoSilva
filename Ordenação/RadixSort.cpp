#include <iostream>
#include <vector>

using namespace std;

// Função para pegar o maior número de um vetor
int biggestNumber(vector<int> &vetor) {
    int number = vetor[0];
    for (int num : vetor) {
        if (num > number) {
            number = num;
        }
    }
    return number;
}

// Função de ordenação por contagem de distribuição
vector<int> distributionCountingSort(const vector<int>& inputArray, int exponent) {
    int range = 10;

    // Vetor auxiliar para contar a frequência de cada elemento
    vector<int> frequency(range, 0);

    // Contando a frequência de cada elemento no intervalo [lowerBound, upperBound]
    for (int value : inputArray) {
        frequency[(value/exponent) % 10]++;
    }

    // Calculando os índices cumulativos no vetor de frequência
    for (int i = 1; i < range; i++) {
        frequency[i] += frequency[i - 1];
    }

    // Vetor para armazenar o resultado ordenado
    vector<int> sortedArray(inputArray.size());

    // Preenchendo o vetor ordenado a partir do final do vetor original
    for (int i = inputArray.size() - 1; i >= 0; i--) {
        int index = (inputArray[i] /exponent) % 10;
        sortedArray[frequency[index] - 1] = inputArray[i];
        frequency[index]--; // Reduz o contador para o próximo elemento igual
    }

    return sortedArray;
}

void radixsort(vector<int> &vetor){

    // Encontro o maior número
    int bigger = biggestNumber(vetor);

    // Fazer o couting sort para cada digito
    for (int exponent = 1; bigger / exponent > 0; exponent *= 10)
        vetor = distributionCountingSort(vetor, exponent);
}


int main()
{
    vector<int> vetor = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int size = vetor.size();

    radixsort(vetor);

    for (int i = 0; i < size; i++)
        cout << vetor[i] << " ";
    return 0;
}
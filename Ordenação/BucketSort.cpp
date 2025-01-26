#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double smallestNumber(vector<double> &vetor) {
    double number = vetor[0];
    for (double num : vetor) {
        if (num < number) {
            number = num;
        }
    }
    return number;
}

double biggestNumber(vector<double> &vetor) {
    double number = vetor[0];
    for (double num : vetor) {
        if (num > number) {
            number = num;
        }
    }
    return number;
}

void insertionSort(vector<double>& vetor) {
    // Itera sobre os elementos a partir do segundo
    for (size_t i = 1; i < vetor.size(); i++) {
        double key = vetor[i]; // Elemento a ser inserido
        size_t j = i;

        // Desloca os elementos maiores para frente
        while (j > 0 && vetor[j - 1] > key) {
            vetor[j] = vetor[j - 1];
            j--;
        }

        // Insere o elemento na posição correta
        vetor[j] = key;
    }
}

void bucketSort(vector<double> &vetor) {
    int numBuckets = vetor.size();
    if (numBuckets <= 1) return;

    // Encontrar o menor e o maior número
    double small = smallestNumber(vetor);
    double bigger = biggestNumber(vetor);

    // Calcular o intervalo
    double interval = (bigger - small) / numBuckets;
    if (interval == 0) {
        insertionSort(vetor);
        return;
    }

    // Criar os buckets
    vector<vector<double>> buckets(numBuckets);

    // Distribuir os números nos buckets
    for (const double &num : vetor) {
        int index = (int)((num - small) / interval); // Mapear o número ao índice
        if (index == numBuckets) index--; // Garante que o maior número caia no último bucket
        buckets[index].push_back(num);
    }

    // Ordenar individualmente cada bucket
    for (auto &bucket : buckets) {
        if (!bucket.empty()) {
            bucketSort(bucket);
        }
    }

    // Concatenar os buckets no vetor original
    int idx = 0;
    for (const auto &bucket : buckets) {
        for (double num : bucket) {
            vetor[idx++] = num;
        }
    }

    for (int i = 0; i < numBuckets; i++) {
        cout << "Bucket " << i << ": ";
        for (double value : buckets[i]) {
            cout << value << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<double> vetor = {3.4, 2.1, 5.7, 8.9, 7.2};
    cout << "Vetor original:" << endl;
    for (double num : vetor) {
        cout << num << " ";
    }
    cout << endl;

    bucketSort(vetor);

    cout << "Vetor ordenado:" << endl;
    for (double num : vetor) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

int numSwitchs = 0;
// Função para mesclar dois subvetores ordenados
void merge(vector<int>& leftVetor, vector<int>& rigthVetor, vector<int>& vetor) {
    int i = 0, j = 0, k = 0;
    int p = leftVetor.size(), q = rigthVetor.size();
    vetor.resize(p + q);

    // Mesclando os elementos dos dois vetores
    while (i < p && j < q) {
        if (leftVetor[i] <= rigthVetor[j]) {
            vetor[k] = leftVetor[i];
            i++;
        } else {
            vetor[k] = rigthVetor[j];
            numSwitchs += p - i;
            j++;
        }
        k++;
    }

    // Copiar os elementos restantes de leftVetor, se houver
    while (i < p) {
        vetor[k] = leftVetor[i];
        i++;
        k++;
    }

    // Copiar os elementos restantes de rigthVetor, se houver
    while (j < q) {
        vetor[k] = rigthVetor[j];
        j++;
        k++;
    }
}

// Função recursiva auxiliar
void mergeSortHelper(vector<int>& vetor, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Vetores auxiliares para dividir a lista
        vector<int> vetorLeft(vetor.begin() + left, vetor.begin() + mid + 1);
        vector<int> vetorRight(vetor.begin() + mid + 1, vetor.begin() + right + 1);

        mergeSortHelper(vetorLeft, 0, vetorLeft.size() - 1);
        mergeSortHelper(vetorRight, 0, vetorRight.size() - 1);

        // Mesclar os vetores ordenados
        merge(vetorLeft, vetorRight, vetor);
    }
}

void mergeSort(vector<int>& A) {
    mergeSortHelper(A, 0, A.size() - 1);
}

int main() {
    //vector<int> A = {3, 5, 34, 10, 8, 7, 1};
    vector<int> A = {4, 3, 2, 1};
    cout << "Vetor original: ";
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;

    mergeSort(A);

    cout << "Vetor ordenado: ";
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;
    cout << numSwitchs << endl;

    return 0;
}
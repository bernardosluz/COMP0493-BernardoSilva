#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(const vector<int>& array, int numSearch) {
    int left = 0;
    int right = array.size() - 1;
    int result = -1; // Armazena o menor índice encontrado

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (array[mid] == numSearch) {
            result = mid; // Valor encontrado
            return result;
        } else if (array[mid] > numSearch) {
            right = mid - 1; // Atualiza o limite superior
        } else {
            left = mid + 1; // Atualiza o limite inferior
        }
    }

    return result; // Retorna o menor índice encontrado ou -1 se não existir
}


int main() {
    // Vetor de exemplo
    vector<int> array = {1, 3, 3, 3, 5, 7, 9, 9, 10};

    // Ordena o vetor
    sort(array.begin(), array.end());

    cout << "Array ordenado: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;

    // Testa a busca binária com diferentes números
    vector<int> searchNumbers = {3, 9, 6, 1, 10, 15};
    for (int num : searchNumbers) {
        int index = binarySearch(array, num);
        if (index != -1) {
            cout << num << " found at index " << index << "." << endl;
        } else {
            cout << num << " not found in the array." << endl;
        }
    }

    return 0;
}
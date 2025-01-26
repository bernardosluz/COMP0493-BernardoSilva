#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Função para obter a mediana de três elementos
int medianOfThree(const vector<int>& array, int left, int right) {
    int mid = left + (right - left) / 2;
    if ((array[left] >= array[mid] && array[left] <= array[right]) || (array[left] <= array[mid] && array[left] >= array[right])) {
        return left;
    } else if ((array[mid] >= array[left] && array[mid] <= array[right]) || (array[mid] <= array[left] && array[mid] >= array[right])) {
        return mid;
    } else {
        return right;
    }
}

// Função de partição de Hoare
int hoarePartition(vector<int>& array, int left, int right) {
    int medianIndex = medianOfThree(array, left, right);
    int pivot = array[medianIndex];
    int i = left, j = right + 1;

    // Coloca o pivô no início para a partição
    swap(array[left], array[medianIndex]);

    while (true) {
        do {
            i++;
        } while (i <= right && array[i] < pivot);
        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j) { break; }
        swap(array[i], array[j]);
    }

    // Coloca o pivô na posição correta
    swap(array[left], array[j]);
    return j;
}

// Função QuickSort
void quickSortHelper(vector<int>& array, int left, int right) {
    if (left < right) {
        int pivotIndex = hoarePartition(array, left, right);
        quickSortHelper(array, left, pivotIndex - 1);
        quickSortHelper(array, pivotIndex + 1, right);
    }
}

void quickSort(vector<int> &array)
{
    quickSortHelper(array, 0, array.size() - 1);
}

int main() {
    vector<int> array = {5, 34, 10, 5, 7, 5, 8, 7, 1};

    cout << "Array original: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;

    quickSort(array);

    cout << "Array ordenado: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
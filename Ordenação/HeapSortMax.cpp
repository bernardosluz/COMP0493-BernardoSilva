#include <iostream>
#include <vector>

using namespace std;

// Função para reorganizar a heap (heapify) garantindo a propriedade de Max-Heap
void maxHeapify(vector<int> &heap, int n, int i) {
    int largest = i;       // Assume que a raiz é o maior elemento
    int left = 2 * i + 1;   // Índice do filho esquerdo
    int right = 2 * i + 2;  // Índice do filho direito

    // Se o filho esquerdo for maior que a raiz
    if (left < n && heap[left] > heap[largest])
        largest = left;

    // Se o filho direito for maior que o maior encontrado até agora
    if (right < n && heap[right] > heap[largest])
        largest = right;

    // Se o maior elemento não for a raiz, troca e continua corrigindo a heap
    if (largest != i) {
        swap(heap[i], heap[largest]);
        maxHeapify(heap, n, largest);
    }
}

// Função para construir um Max-Heap a partir de um vetor desordenado
void buildMaxHeap(vector<int> &heap) {
    int n = heap.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(heap, n, i);
}

// Função Heap Sort usando Max-Heap
void heapSort(vector<int> &arr) {
    int n = arr.size();

    // Construção do Max-Heap
    buildMaxHeap(arr);

    // Extrai elementos um por um da heap ordenando o vetor
    for (int i = n - 1; i > 0; i--) {
        // Move o maior elemento para o final do vetor
        swap(arr[0], arr[i]);
        
        // Reorganiza a heap sem o último elemento já ordenado
        maxHeapify(arr, i, 0);
    }
}

// Função para imprimir um vetor
void printArray(const vector<int> &arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {7, 2, 5, 1, 9, 3};

    cout << "Array original: ";
    printArray(arr);

    heapSort(arr);

    cout << "Array ordenado (Heap Sort): ";
    printArray(arr);

    return 0;
}

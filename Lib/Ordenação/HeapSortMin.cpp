#include <iostream>
#include <vector>

using namespace std;

//Função para reorganizar a heap (heapify)
//Garante que a propriedade de min-heap seja mantida a partir do índice 'i'
void minHeapify(vector<int> &heap, int n, int i) {
    int smallest = i;       // Assume que a raiz é o menor elemento
    int left = 2 * i + 1;   // Índice do filho esquerdo
    int right = 2 * i + 2;  // Índice do filho direito

    // Se o filho esquerdo for menor que a raiz
    if (left < n && heap[left] < heap[smallest])
        smallest = left;

    // Se o filho direito for menor que o menor encontrado até agora
    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    // Se o menor elemento não for a raiz, troca e continua corrigindo a heap
    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        minHeapify(heap, n, smallest);
    }
}

//Função para construir um Min-Heap a partir de um vetor desordenado
void buildMinHeap(vector<int> &heap) {
    int n = heap.size();
    // Começamos a reorganizar a heap a partir do último nó pai
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(heap, n, i);
}

//Função Heap Sort usando Min-Heap
void heapSort(vector<int> &arr) {
    int n = arr.size();

    // Construção do Min-Heap a partir do vetor
    buildMinHeap(arr);

    // Extrai elementos um por um da heap ordenando o vetor
    for (int i = n - 1; i > 0; i--) {
        // Move o menor elemento para o final do vetor
        swap(arr[0], arr[i]);
        
        // Reorganiza a heap sem o último elemento já ordenado
        minHeapify(arr, i, 0);
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

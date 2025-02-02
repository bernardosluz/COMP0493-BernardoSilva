#include <iostream>
#include <vector>
#include <algorithm>  // Para make_heap e sort_heap
#include <functional> // Para greater

using namespace std;
/*
*   Por padrão, make_heap e sort_heap usam o max-heap.
*   Se você quiser um min-heap (onde o menor valor fica na raiz), pode passar uma função de comparação personalizada
*   Mas a ordenação pelo sort_heap ficará errada;
*   Assinatura:
*   make_heap(begin, end);
*   make_heap(vec.begin(), vec.end(), greater<int>());
*   sort_heap(vec.begin(), vec.end());
*
*   Resumo das funções:
*   make_heap: Converte um vetor em um heap (max-heap ou min-heap, dependendo da função de comparação).
*   sort_heap: Ordena os elementos do heap em ordem crescente.
*   Função de Comparação: Permite personalizar a ordem do heap,
*   seja para criar um min-heap (menor valor na raiz) ou max-heap (maior valor na raiz).
*/

/*
bool compare(int a, int b) {
    return a > b;  // Para criar um min-heap
}
    Criar um min-heap usando a função de comparação
    make_heap(vec.begin(), vec.end(), compare);

    cout << "Min-Heap: ";
    for (int n : vec) cout << n << " ";
    cout << endl;
*/

int main() {
    vector<int> vec = {10, 20, 5, 7, 3};

    make_heap(vec.begin(), vec.end());
    cout << "Max-Heap: ";
    for (int n : vec) cout << n << " ";
    cout << endl;
    // Ordenar o heap
    sort_heap(vec.begin(), vec.end());

    cout << "Vetor ordenado: ";
    for (int n : vec) cout << n << " ";
    cout << endl;

    return 0;
}
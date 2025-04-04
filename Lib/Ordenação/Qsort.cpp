#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

/*
*   Função de comparação adaptada para o qsort
*   se o elemento deve vir antes do outro então retornamos um valor negativo
*   caso contrário retornamos um valor positivo
*   e se forem equivalente retornamos 0
*/
int compare(const void *param1, const void *param2)
{
    // Cast para os tipos corretos
    int *parametro1 = (int *)param1;
    int *parametro2 = (int *)param2;

    // Comparação ascendente
    if (*parametro1 < *parametro2) {
        return -1;
    }
    else if (*parametro1 == *parametro2) {
        return 0;
    }
    else {
        return 1;
    }
}

int main()
{

    vector<int> vetor = {5, 4, 3, 2, 1};
    /*
     *    void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *));
     *    void *base: Ponteiro para o primeiro elemento do array que será ordenado.
     *    size_t nitems: Número de elementos no array.
     *    size_t size: Tamanho, em bytes, de cada elemento no array.
     *    int (*compar)(const void *, const void *): Ponteiro para a função de comparação, que define a ordem dos elementos.
     */
    qsort(&vetor[0], vetor.size(), sizeof(int), compare);

    for (int num : vetor)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

/*
*   O std::sort é uma função de ordenação presente na biblioteca padrão do C++ (<algorithm>).
*   Ela permite ordenar os elementos de um container (como std::vector, std::array, ou até mesmo um array C)
*   de forma eficiente.
*
*   Como funciona o std::sort:
*   Assinatura:
*
*   template< class RandomIt >
*    void sort(RandomIt first, RandomIt last, Funcion compare);
*
*   first: Um iterador que aponta para o primeiro elemento do container.
*   last: Um iterador que aponta para o elemento após o último elemento do container
*   compare: seria uma função que aceita dois parâmetros e retorna um valor booleano.
*/

using namespace std;

// Função de comparação para ordenar em ordem crescente
template <typename AnyType>
bool compare(const AnyType& param1, const AnyType& param2)
{
    return param1 < param2; // Ordenação crescente
}

int main()
{
    // Vetor de strings
    vector<string> vetor_strings = {"Arthur", "Bernardo", "Anderson"};
    
    // Vetor de inteiros
    vector<int> vetor_ints = {5, 4, 3, 2, 1};
    
    // Vetor de doubles
    vector<double> vetor_doubles = {3.14, 2.71, 1.41, 1.73};

    // Usando std::sort para ordenar os vetores
    sort(vetor_strings.begin(), vetor_strings.end(), compare<string>);
    sort(vetor_ints.begin(), vetor_ints.end(), compare<int>);
    sort(vetor_doubles.begin(), vetor_doubles.end(), compare<double>);

    // Imprimindo os vetores após ordenação
    std::cout << "Vetor de strings ordenado: ";
    for (const std::string& str : vetor_strings)
    {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    std::cout << "Vetor de inteiros ordenado: ";
    for (const int& num : vetor_ints)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Vetor de doubles ordenado: ";
    for (const double& num : vetor_doubles)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
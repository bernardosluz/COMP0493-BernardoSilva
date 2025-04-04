#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

/*
std::min_element: Encontra o ponto mais baixo.
std::sort: Ordena os pontos com base no ângulo polar calculado com atan2.
Se precisar da ordem horária (CW), basta inverter a comparação no std::sort.

A função std::min_element vem da biblioteca <algorithm> do C++ e é usada para encontrar o menor elemento dentro de um intervalo (como um std::vector).
A assinatura da função é:
template< class ForwardIt >
ForwardIt min_element( ForwardIt first, ForwardIt last );
Ou, se usarmos um comparador personalizado:

template< class ForwardIt, class Compare >
ForwardIt min_element( ForwardIt first, ForwardIt last, Compare comp );
first, last: Definem o intervalo de busca (begin() e end() do vetor).
comp: Uma função que compara dois elementos e retorna true se o primeiro for menor.
A função retorna um iterador apontando para o menor elemento.
*/
struct Ponto {
    double x, y;
};

// Função auxiliar para calcular o ângulo polar
double anguloPolar(const Ponto &ref, const Ponto &p) {
    return atan2(p.y - ref.y, p.x - ref.x);
}

// Ordenação dos pontos no sentido anti-horário (CCW)
void ordenarPontos(std::vector<Ponto> &pontos) {
    // Passo 1: Encontrar o ponto mais baixo (ou mais à esquerda)
    Ponto ref = *std::min_element(pontos.begin(), pontos.end(), [](const Ponto &a, const Ponto &b) {
        return (a.y < b.y) || (a.y == b.y && a.x < b.x);
    });

    // Passo 2: Ordenar por ângulo polar
    std::sort(pontos.begin(), pontos.end(), [&ref](const Ponto &a, const Ponto &b) {
        return anguloPolar(ref, a) < anguloPolar(ref, b);
    });
}

// Impressão dos pontos ordenados
void imprimirPontos(const std::vector<Ponto> &pontos) {
    for (const auto &p : pontos) {
        std::cout << "(" << p.x << ", " << p.y << ")\n";
    }
}

int main() {
    std::vector<Ponto> pontos = {{0, 0}, {1, 1}, {2, 2}, {0, 2}, {2, 0}};
    
    ordenarPontos(pontos);
    
    std::cout << "Pontos ordenados no sentido anti-horário:\n";
    imprimirPontos(pontos);
    
    return 0;
}

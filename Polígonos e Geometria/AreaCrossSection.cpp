#include <iostream>
#include <cmath>  // Para a constante M_PI

using namespace std;
/*
*   A fórmula da área do círculo é dada por:
*   A = π * r^2
*   Onde:
*   A é a área do círculo
*   π (pi) é uma constante aproximadamente igual a 3.14159
*   r é o raio do círculo
*/

// Função para calcular a área da seção transversal de um círculo
double areaOfCrossSection(double radius) {
    return M_PI * pow(radius, 2);
}

int main() {
    double radius = 5.0;  // Raio do círculo
    
    double area = areaOfCrossSection(radius);
    cout << "Area da secao transversal do circulo: " << area << endl;

    return 0;
}

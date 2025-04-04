#include <iostream>
#include <cmath>  // Para a função sqrt

using namespace std;
/*
*   A fórmula para a distância entre dois pontos
*   𝑃1(𝑥1,𝑦1) e 𝑃2(𝑥2,𝑦2)
*   no plano cartesiano é dada por:
*   𝑑 = sqrt((𝑥2 − 𝑥1)^2 + (𝑦2 − 𝑦1)^2)
*/

// Função para calcular a distância entre dois pontos
double distancePoints(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    double x1 = 1.0, y1 = 2.0;
    double x2 = 4.0, y2 = 6.0;
    
    double dist = distancePoints(x1, y1, x2, y2);
    cout << "Distancia entre os pontos: " << dist << endl;

    return 0;
}

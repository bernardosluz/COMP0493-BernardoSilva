#include <iostream>
#include <cmath>  // Para a função fabs e sqrt

using namespace std;
/*
*   A fórmula da distância entre ponto (x1, y1)
*   e a reta ax + by + c = 0 é:
*   d = |a * x1 + b * y1 + c| / sqrt(a^2 + b^2)
*/

// Função para calcular a distância entre um ponto e uma reta
double distanceBetweenPointAndLine(double x1, double y1, double a, double b, double c) {
    return fabs(a * x1 + b * y1 + c) / sqrt(pow(a, 2) + pow(b, 2));
}

int main() {
    
    double x1 = 1.0, y1 = 2.0;
    double a = 1.0, b = -1.0, c = -1.0;  // Equação da reta x - y - 1 = 0
    
    double dist = distanceBetweenPointAndLine(x1, y1, a, b, c);
    cout << "Distancia entre o ponto e a reta: " << dist << endl;

    return 0;
}

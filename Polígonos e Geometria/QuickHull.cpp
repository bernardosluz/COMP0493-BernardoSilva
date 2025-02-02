#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct Point {
    double x;
    double y;
};

vector<Point> convexHull;

// Ordena os pontos em ordem crescente pela coordenada x. Em caso de empate, pela coordenada y
bool compare(const Point &point1, const Point &point2) {
    if (point1.x != point2.x) {
        return point1.x < point2.x;
    }
    return point1.y < point2.y;
}

// Determinante para calcular a orientacao dos pontos
// Retorna > 0 se o ponto estiver no sentido anti-horário, 0 se colinear, < 0 se no sentido horário
double determinant(const Point &p1, const Point &p2, const Point &p3) {
    return p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y);
}

// Função recursiva para o algoritmo QuickHull
void quickHull(const vector<Point> &points, const Point &leftMostPoint, const Point &rightMostPoint, bool isUpperHull) {
    int size = points.size();
    if (size < 1) {
        return; // Caso base: sem pontos a considerar
    }

    // Encontra o ponto mais distante da linha formada por leftMostPoint e rightMostPoint
    Point farthestPoint;
    double maxDistance = 0;
    vector<Point> remainingPoints;

    for (const Point &p : points) {
        double currentDet = determinant(leftMostPoint, rightMostPoint, p);
        if ((isUpperHull && currentDet > 0) || (!isUpperHull && currentDet < 0)) {
            double distance = abs(currentDet);
            if (distance > maxDistance) {
                maxDistance = distance;
                farthestPoint = p;
            }
            remainingPoints.push_back(p);
        }
    }

    if (maxDistance == 0) {
        return; // Nenhum ponto encontrado para esta parte do casco convexo
    }

    // Adiciona o ponto mais distante ao casco convexo
    convexHull.push_back(farthestPoint);

    // Divide os pontos restantes em dois subconjuntos
    vector<Point> leftSubset;
    vector<Point> rightSubset;

    for (const Point &p : remainingPoints) {
        if (determinant(leftMostPoint, farthestPoint, p) > 0) {
            leftSubset.push_back(p);
        } else if (determinant(farthestPoint, rightMostPoint, p) > 0) {
            rightSubset.push_back(p);
        }
    }

    // Recursão nos subconjuntos esquerdo e direito
    quickHull(leftSubset, leftMostPoint, farthestPoint, isUpperHull);
    quickHull(rightSubset, farthestPoint, rightMostPoint, isUpperHull);
}

int main() {
    vector<Point> points = {{1, 1}, {2, 2}, {3, 3}, {4, 0}, {2, 10}, {-1, 20}};

    // Ordena os pontos para garantir que o primeiro e o último sejam os extremos
    sort(points.begin(), points.end(), compare);

    cout << "Pontos Ordenados:" << endl;
    for (const Point &p : points) {
        cout << "{" << p.x << ", " << p.y << "}" << endl;
    }

    // Adiciona os extremos ao casco convexo
    Point leftMostPoint = points.front();
    Point rightMostPoint = points.back();
    convexHull.push_back(leftMostPoint);
    convexHull.push_back(rightMostPoint);

    // Divide os pontos em subconjuntos superior e inferior
    vector<Point> upperPoints;
    vector<Point> lowerPoints;

    for (const Point &p : points) {
        double det = determinant(leftMostPoint, rightMostPoint, p);
        if (det > 0) {
            upperPoints.push_back(p);
        } else if (det < 0) {
            lowerPoints.push_back(p);
        }
    }

    // Calcula o casco convexo para os subconjuntos superior e inferior
    quickHull(upperPoints, leftMostPoint, rightMostPoint, true);
    quickHull(lowerPoints, leftMostPoint, rightMostPoint, false);

    // Imprime o casco convexo
    cout << "\nPolígono Convexo:" << endl;
    for (const Point &p : convexHull) {
        cout << "{" << p.x << ", " << p.y << "}" << endl;
    }

    return 0;
}

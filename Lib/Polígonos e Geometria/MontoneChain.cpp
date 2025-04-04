#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

// Estrutura para armazenar um ponto 2D
struct Point {
    long long x, y;
};

// Função de comparação para ordenar primeiro por x, depois por y
bool compare(const Point &a, const Point &b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

// Produto vetorial (cross product) entre os vetores (A->B) e (A->C)
// Se > 0 => C está à esquerda de A->B (giro anti-horário)
// Se < 0 => C está à direita de A->B (giro horário)
// Se = 0 => A, B, C são colineares
long long cross(const Point &A, const Point &B, const Point &C) {
    return (B.x - A.x) * (C.y - A.y) 
         - (B.y - A.y) * (C.x - A.x);
}

// Constrói o casco convexo usando o método Monotone Chain (Andrew’s Algorithm)
vector<Point> buildConvexHull(vector<Point> pts) {
    // 1) Ordenar os pontos
    sort(pts.begin(), pts.end(), compare);

    // 2) Remover pontos duplicados (opcional, mas evita problemas de repetição)
    pts.erase(unique(pts.begin(), pts.end(), 
                     [](const Point &p1, const Point &p2) {
                         return (p1.x == p2.x && p1.y == p2.y);
                     }), 
              pts.end());

    // Se após remover duplicados sobrar < 2 pontos, não há muito o que fazer
    if (pts.size() < 2) {
        return pts;
    }

    // 3) Construir a parte inferior (lower hull)
    vector<Point> hull;
    for (int i = 0; i < (int)pts.size(); i++) {
        // Enquanto a última curva formada for “giro à direita” ou colinear
        // (para manter pontos colineares, use cross(...) < 0; 
        //  se quiser excluir colineares, use <= 0)
        while (hull.size() >= 2 
            && cross(hull[hull.size()-2], hull[hull.size()-1], pts[i]) <= 0) 
        {
            hull.pop_back();
        }
        hull.push_back(pts[i]);
    }

    // 4) Construir a parte superior (upper hull)
    // Vamos percorrer de trás para a frente e repetir o processo
    for (int i = (int)pts.size() - 2, t = hull.size() + 1; i >= 0; i--) {
        while ((int)hull.size() >= t 
            && cross(hull[hull.size()-2], hull[hull.size()-1], pts[i]) <= 0) 
        {
            hull.pop_back();
        }
        hull.push_back(pts[i]);
    }

    // O último ponto é igual ao primeiro (fechando o polígono), então removemos
    hull.pop_back();

    return hull;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N; // lê o número de pontos
    vector<Point> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
    }

    // Constrói o casco convexo
    vector<Point> hull = buildConvexHull(points);

    // Imprime o casco convexo
    cout << "Casco convexo:\n";
    for (auto &p : hull) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <math.h>
#include <stack>


using namespace std;

struct Point {
    double coord_x;
    double coord_y;
};

Point point0;

// Função que pega o elemento depois do topo em uma pilha
Point nextToTop(stack<Point> &S)
{
    Point pointTop = S.top();
    S.pop();
    Point nextPointTop = S.top();
    S.push(pointTop);
    return nextPointTop;
}

void swap(Point &p1, Point &p2){
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

int find_smallest_y (const vector<Point> &points){

    // Inicializa o menor ponto como primero ponto do vetor
    int smallest_y = 0;

    // Percorrer os pontos para encontrar o menor y
    for(int i=1; i < points.size(); i++){
        if(points[smallest_y].coord_y > points[i].coord_y){
            smallest_y = i;
        }
    }

    return smallest_y;
}

double distancePoint (Point point, Point pointX){
    double distance = sqrt((point.coord_x-pointX.coord_x)*(point.coord_x-pointX.coord_x)
                        + (point.coord_y-pointX.coord_y)*(point.coord_y-pointX.coord_y));
    return distance;
}

// Orientação dos vetores
int orientation(Point p0, Point p1, Point p2){
 
    //Fórmula: A X B = (p1.x - p1.x)* (p1.y - p0.y)
    
    int value = (p1.coord_x - p0.coord_x)*(p2.coord_y - p1.coord_y)
                - (p2.coord_x - p1.coord_x)*(p1.coord_y - p0.coord_y);

    if(value == 0) return 0; // Colinear

    return (value > 0) ? -1 : 1; // Sentido anti-horário e Sentido horário, respectivamente
}

int compare(const void *point1, const void* point2){
    Point *p1 = (Point *)point1;
    Point *p2 = (Point *)point2;

    // Encontra a orientação com base no menor y
    int sense = orientation(point0, *p1, *p2);

    if (sense == 0)
    return (distancePoint(point0, *p2) >= distancePoint(point0, *p1)) ? -1 : 1;

    return (sense == -1) ? -1 : 1;
}

void convexHull(vector<Point> &points, int sizeVector){
   
   int min = find_smallest_y(points);

   // Coloca o menor y na posição incial
   swap(points[0], points[min]);

    // Ordena sizeVector - 1 em relação ao ponto inicial.
    // Um ponto p1 vem antes de p2 se p2
    // tem um angulo polar maior que p1 (em sentido anti-horário)
    point0 = points[0];

    qsort(&points[1], sizeVector-1, sizeof(Point), compare);


    int m = 1; // Inicializa o tamanho do array modificado
    vector<Point> convex (sizeVector);
    convex[0] = points[0];
    for (int i=1; i<sizeVector; i++)
    {
       // Remove os pontos colineares em relação a point0
        while (i < sizeVector-1 && orientation(point0, points[i],
                                    points[i+1]) == 0)
          i++;

       convex[m] = points[i];
       m++;  // Aumento o tamaanho
   }

    convex.resize(m);
    // Se o vetor tiver menos que 3 elementos convexHull não é possível
    if (m < 3) return;

    // Cria um pilha e adiciona os primeiros 3 elementos nela
    stack<Point> S;
    S.push(convex[0]);
    S.push(convex[1]);
    S.push(convex[2]);

    // Processo para os restantes dos pontos
    for (int i = 3; i < m; i++)
    {
        // Remove o topo enquanto o sentido dos pontos é para não esquerda
        while (S.size()>1 && orientation(nextToTop(S), S.top(), convex[i]) == 1){
            S.pop();
        }
         
        S.push(convex[i]);
   }

   // Conjunto do polígono convexo
   while (!S.empty())
   {
       Point p = S.top();
       cout << "(" << p.coord_x << ", " << p.coord_y <<")" << endl;
       S.pop();
   }
}

int main()
{
    vector<Point> points = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
                      {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    int sizeVector = points.size();
    convexHull(points, sizeVector);
    return 0;
}
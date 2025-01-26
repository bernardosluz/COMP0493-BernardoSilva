#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

struct Item {
    int cust;
    int weight;
    double cost_benefit;
};

int fractionalKnapsack(vector<Item>& items, int itemCount, int capacity) {
    int totalValue = 0; // Valor total acumulado
    int i = 0;          // Índice para iterar pelos itens

    // Enquanto houver capacidade e o peso do item for menor ou igual à capacidade disponível
    while (i < itemCount && items[i].weight <= capacity) {
        totalValue += items[i].cust;      // Adiciona o valor total do item
        capacity -= items[i].weight;      // Reduz a capacidade disponível
        i++;                              // Passa para o próximo item
    }

    // Se ainda houver capacidade, adiciona uma fração do próximo item
    if (i < itemCount) {
        totalValue += (items[i].cust / (double)items[i].weight) * capacity;
    }

    return totalValue;
}

int compare(const void *num1, const void *num2){
    Item *item1 = (Item *) num1;
    Item *item2 = (Item *) num2;

    if(item1->cost_benefit >= item2->cost_benefit){
        return -1;
    } else {
        return 1;
    }
    return 0;
}

void printItems(const vector<Item>& items) {
    cout << "[";
    for (size_t i = 0; i < items.size(); i++) {
        cout << "{Custo: " << items[i].cust << ", Peso: " << items[i].weight << ", Custo-beneficio: " << items[i].cost_benefit << "}";
        if (i != items.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}
int main() {
    // Vetor que armazena os itens, onde cada item é uma estrutura com valor, peso e custo-benefício
    vector<Item> items = {
        {60, 10, 0},  // {Valor, Peso, Custo-benefício}
        {100, 20, 0},
        {120, 30, 0},
        {80, 15, 0},
        {150, 25, 0},
        {200, 40, 0}
    };
    
    int itemCount = items.size();    // Número total de itens
    int capacity = 50;               // Capacidade máxima da mochila

    // Calcula o custo-benefício de cada item
    for (int i = 0; i < itemCount; i++) {
        items[i].cost_benefit = (double)items[i].cust / items[i].weight;
    }

    qsort(&items[0], itemCount, sizeof(Item), compare);

    // Exibe os itens ordenados
    cout << "Itens com custo-beneficio ordenado: ";
    printItems(items);

    // Calcula o valor máximo que pode ser colocado na mochila
    int maxValue = fractionalKnapsack(items, itemCount, capacity);

    // Exibe o resultado
    cout << "Valor maximo que pode ser carregado: " << maxValue << endl;

    return 0;
}

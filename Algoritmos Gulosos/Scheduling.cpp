#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Estrutura para representar os horários de início e término
struct Time {
    int beginHours;  
    int beginMinutes; 
    int endHours;     
    int endMinutes;   
};

// Função de comparação para ordenar atividades pelo horário de término
bool compare(const Time &num1, const Time &num2) {
    if (num1.endHours < num2.endHours) {
        return true;
    } else if (num1.endHours == num2.endHours) {
        return num1.endMinutes < num2.endMinutes;
    } else {
        return false;
    }
}

// Função de escalonamento para selecionar atividades que não se sobrepõem
vector<Time> scheduling(const vector<Time> &vetor) {
    int size = vetor.size();
    vector<Time> schedul(size);

    if (size == 0) return schedul; // Se não há atividades, retorna vazio

    // A primeira atividade sempre será selecionada
    schedul[0] = vetor[0];
    int index = 0;
    for (int i = 1; i < size; i++) {
        // Verifica se a atividade atual não conflita com a última adicionada
        Time lastScheduled = schedul[index];
        if ((vetor[i].beginHours > lastScheduled.endHours) ||
            (vetor[i].beginHours == lastScheduled.endHours && vetor[i].beginMinutes >= lastScheduled.endMinutes)) {
            index++;
            schedul[index] = vetor[i];
        }
    }
    index++;
    schedul.resize(index);
    return schedul;
}

int main() {

    // Vetor com as atividades, incluindo horários de início e término
    vector<Time> vetor = {
        {9, 0, 10, 30}, // Atividade 1: Início às 9:00, término às 10:30
        {10, 0, 11, 0}, // Atividade 2: Início às 10:00, término às 11:00
        {10, 30, 11, 30}, // Atividade 3: Início às 10:30, término às 11:30
        {12, 0, 13, 0}, // Atividade 4: Início às 12:00, término às 13:00
        {11, 30, 12, 30} // Atividade 5: Início às 11:30, término às 12:30
    };

    // Ordena as atividades pelo horário de término
    sort(vetor.begin(), vetor.end(), compare);

    // Realiza o escalonamento
    vector<Time> scheduled = scheduling(vetor);

    // Imprime as atividades selecionadas
    cout << "Atividades selecionadas:" << endl;
    for (const Time &activity : scheduled) {
        cout << "Inicio: " << activity.beginHours << ":" << activity.beginMinutes
             << ", Termino: " << activity.endHours << ":" << activity.endMinutes << endl;
    }

    return 0;
}

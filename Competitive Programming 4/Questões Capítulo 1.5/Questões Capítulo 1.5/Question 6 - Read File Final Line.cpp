#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Abre o arquivo
    ifstream file("C:\\Users\\berna\\Downloads\\teste.txt");

    // Verifica se o arquivo foi aberto corretamente
    if (!file.is_open()) {
        cout << "Error: Could not open file." << endl;
        return 1;
    }

    string line;
    bool foundLineWithPeriods = false;

    // Ler linha por linha
    while (getline(file, line)) {
        // Verifica se começa com "......."
        if (line.find(".......") == 0) {
            foundLineWithPeriods = true;
            // Pula para a próxima linha (que será a última)
            continue;
        }

        if (foundLineWithPeriods) {
            // Conta o número de caracteres na última linha
            cout << "Number of characters in the last line: " << line.length() << endl;
            break;
        }
    }

    // Fecha o arquivo
    file.close();

    return 0;
}
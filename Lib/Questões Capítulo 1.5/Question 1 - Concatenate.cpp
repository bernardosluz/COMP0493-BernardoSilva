#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string readAndConcatenate(const string& fileReceived) {
    ifstream file(fileReceived); // Abre o arquivo
    if (!file.is_open()) {
        cerr << "Error: Could not open file." << endl;
        return "";
    }

    string result; // String concatenada
    string line;   // Armazena cada linha
    bool firstLine = true; // Para lidar com os epaços entre as linhas

    while (getline(file, line)) {
        // Checa se a linha começa com "......."
        if (line.rfind(".......", 0) == 0) {
            break; // Para de ler se a linha começa com "......."
        }

        // Adiciona um espaço se não encontrar "......." na primeira linha
        if (!firstLine) {
            result += " ";
        }
        result += line; // Adiciona a linha atual a result
        firstLine = false;
    }

    file.close(); // Fecha o arquivo
    return result; // Retorna a string final concatenada - result
}

int main() {
    string file = "C:\\Users\\berna\\Downloads\\Text Question 1.txt"; // Abrir o arquivo para leitura
    string concatenatedString = readAndConcatenate(file);

    // Saída da string concatenada
    cout << concatenatedString << endl;

    return 0;
}

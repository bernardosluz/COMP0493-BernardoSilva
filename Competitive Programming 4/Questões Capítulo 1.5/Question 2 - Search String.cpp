#include <iostream>
#include <string>
#include <vector>

using namespace std;

void findOccurrences(const string& T, const string& P) {
    vector<int> indices; // Vetor para armazenar os índices das ocorrências
    size_t tLen = T.size();
    size_t pLen = P.size();

    for (size_t i = 0; i <= tLen - pLen; i++) {
        // Verificar se P aparece em T começando no índice i
        if (T.substr(i, pLen) == P) {
            indices.push_back(i); // Adicionar índice encontrado
        }
    }

    // Imprimir o resultado
    if (indices.empty()) {
        cout << "{-1}" << endl; // P não foi encontrado
    } else {
        cout << "{";
        for (size_t i = 0; i < indices.size(); i++) {
            cout << indices[i];
            if (i != indices.size() - 1) {
                cout << ", ";
            }
        }
        cout << "}" << endl;
    }
}

int main() {
    string T = "I love CS3233 Competitive Programming. i also love AlGoRiThM";
    string P = "love";

    // Encontrar as ocorrências de P em T
    findOccurrences(T, P);

    return 0;
}

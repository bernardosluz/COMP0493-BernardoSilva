#include <iostream>   // Biblioteca para entrada e saída padrão.
#include <sstream>    // Biblioteca para manipulação de strings como streams.
#include <vector>     // Biblioteca para utilização de vetores (arrays dinâmicos).
#include <algorithm>  // Biblioteca para funções úteis como sort() e transform().
#include <cctype>     // Biblioteca para funções de manipulação de caracteres.

using namespace std;

// Função para dividir uma string em palavras, convertendo para letras minúsculas e removendo conteúdos após pontos finais.
vector<string> tokenize(const string& T) {
    vector<string> tokens;
    string token;

    // Converte a string original para minúsculas.
    string lowerT = T;
    transform(lowerT.begin(), lowerT.end(), lowerT.begin(), ::tolower);

    // Cria um stringstream para processar a string.
    stringstream ss(lowerT);

    // Divide a string com base nos espaços.
    while (getline(ss, token, ' ')) {
        string word; // String para armazenar cada palavra válida.
        for (char c : token) {
            if (c == '.') break;  // Ignora qualquer conteúdo após um ponto final.
            word += c;
        }
        if (!word.empty()) {      // Adiciona a palavra ao vetor, se não estiver vazia.
            tokens.push_back(word);
        }
    }

    return tokens; // Retorna o vetor de tokens.
}

// Função para encontrar a string lexicograficamente menor em um vetor de strings.
string findSmallestToken(vector<string>& tokens) {
    sort(tokens.begin(), tokens.end());
    return tokens.empty() ? "" : tokens.front();
}

int main() {

    string text = "I love CS3233 Competitive Programming. I also love Algorithm.";

    // Divide a string fornecida.
    vector<string> tokens = tokenize(text);

    // Encontra o menor token lexicograficamente.
    string smallestToken = findSmallestToken(tokens);

    cout << "Tokens (sorted): ";
    for (const string& token : tokens) {
        cout << "'"<< token << "'" << " ";
    }
    cout << endl;

    cout << "Lexicographically smallest token: " << smallestToken << endl;

    return 0;
}

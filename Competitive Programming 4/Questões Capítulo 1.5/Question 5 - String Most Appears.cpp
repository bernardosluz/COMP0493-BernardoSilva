#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cctype>

using namespace std;

// Função para dividir a a string em string de uma palavra e converter para minúsculo
vector<string> tokenize(const string& T) {
    vector<string> tokens;
    string token;
    
    // Converte a string T em minúsculo
    string lowerT = T;
    transform(lowerT.begin(), lowerT.end(), lowerT.begin(), ::tolower);
    
    // Usa stringstream para separar as strings contidas em cada linha
    stringstream ss(lowerT);

    // Armazena a string na variável token e o padrão de separação é um espaço em branco
    while (getline(ss, token, ' ')) {
        string word;
        for (char c : token) {
            if (c == '.') break;
            word += c;
        }
        if (!word.empty()) {
            tokens.push_back(word);
        }
    }

    return tokens;
}

// Função para encontrar a string mais frequente
vector<string> findMostFrequentWords(const vector<string>& tokens) {
    unordered_map<string, int> freqMap; // hashmap para pesquisar cada string de forma mais direta

    // Conta a frequência de cada string
    for (const string& word : tokens) {
        freqMap[word]++;
    }

    // Encontra a frequência máxima
    int maxFreq = 0;
    for (const auto& entry : freqMap) {
        maxFreq = max(maxFreq, entry.second);
    }

    // Armazena as strings que tem frequência máxima
    vector<string> mostFrequentWords;
    for (const auto& entry : freqMap) {
        if (entry.second == maxFreq) {
            mostFrequentWords.push_back(entry.first);
        }
    }

    return mostFrequentWords;
}

int main() {
    string T = "I love CS3233 Competitive Programming. I also love Algorithm.";

    // Divide a string T
    vector<string> tokens = tokenize(T);

    // Encontra as strings com maior frequência
    vector<string> mostFrequentWords = findMostFrequentWords(tokens);

    cout << "Most frequent words: ";
    for (const string& word : mostFrequentWords) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
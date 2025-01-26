#include <iostream>
#include <cctype>
#include <string>

using namespace std;

void analyzeString(const string& T) {
    int digits = 0, vowels = 0, consonants = 0;

    // Loop para percorrer a string
    for (char c : T) {
        // Converte o caracter para minúsculo
        c = tolower(c);

        // Verifica se é um dígito
        if (isdigit(c)) {
            digits++;
        }
        // Verifica se é uma vogal
        else if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowels++;
        }
        // Verifica se é uma letra, como já verificou se é uma vogal, logo só pode ser consoante
        else if (isalpha(c)) {
            consonants++;
        }
    }

    // Output the results
    cout << "Digits: " << digits << endl;
    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;
}

int main() {
    string T = "I love CS3233 Competitive Programming!";

    analyzeString(T);

    return 0;
}

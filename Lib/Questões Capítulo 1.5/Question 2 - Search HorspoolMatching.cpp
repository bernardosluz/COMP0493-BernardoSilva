#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

string toLower(const string& text) {
    string result = text;
    for (char& c : result) {
        c = tolower(c);
    }
    return result;
}

// Monta a tabela de busca do padrão
vector<int> shiftTable(const string& pattern, int sizeP, const string& alphabet) {
    vector<int> table(alphabet.size(), sizeP);

    for (int j = 0; j < sizeP - 1; j++) {
        table[alphabet.find(pattern[j])] = sizeP - 1 - j;
    }

    return table;
}

void horspoolMatching(const string& pattern, int sizeP, const string& text, int sizeT, const string& alphabeto) {
    vector<int> table = shiftTable(pattern, sizeP, alphabeto);

    int i = sizeP - 1, flag = 0;
    while (i < sizeT) {
        int k = 0;
        while (k < sizeP && pattern[sizeP - 1 - k] == text[i - k]) {
            k++;
        }
        if (k == sizeP) {
            flag = 1;
            cout << i - sizeP + 1 << endl;
        }
        i += table[alphabeto.find(text[i])];
    }
    if(!flag)
    {
        cout << "-1" << endl;
    }
}

int horspoolMatching2(const string& pattern, int sizeP, const string& text, int sizeT, const string& alphabeto) {
    vector<int> table = shiftTable(pattern, sizeP, alphabeto);

    int i = sizeP - 1;
    while (i < sizeT) {
        int k = 0;
        while (k < sizeP && pattern[sizeP - 1 - k] == text[i - k]) {
            k++;
        }
        if (k == sizeP) {
            return i - sizeP + 1;
        } else {
            i += table[alphabeto.find(text[i])];
        }
    }
    return -1;
}

int main() {
    string pattern = "love";
    string text = "I love CS3233 Competitive Programming. i also love AlGoRiThM";

    string patternLower = toLower(pattern);
    string textLower = toLower(text);

    string alphabetText = "abcdefghijklmnopqrstuvwxyz0123456789. "; // Alfabeto do Texto

    vector<int> table = shiftTable(patternLower, pattern.size(), alphabetText);

    cout << "Shift Table:\n";
    for (size_t i = 0; i < text.size(); i++) {
        cout << text[i] << " - " << table[alphabetText.find(textLower[i])] << endl;
    }

    horspoolMatching(patternLower, pattern.size(), textLower, text.size(), alphabetText);
    //int patternEncontrado = horspoolMatching(patternLower, pattern.size(), textLower, text.size(), alphabetText);
    //cout << "\n" << patternEncontrado << endl;

    return 0;
}

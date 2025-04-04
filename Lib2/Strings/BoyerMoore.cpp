// boyer_moore.cpp

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void buildBadCharHeuristic(string pattern, unordered_map<char, int>& badChar) {
    int m = pattern.length();
    for (int i = 0; i < m; i++) {
        badChar[pattern[i]] = i;
    }
}

void BoyerMooreSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    unordered_map<char, int> badChar;

    buildBadCharHeuristic(pattern, badChar);

    int s = 0;
    while (s <= n - m) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[s + j]) {
            j--;
        }

        if (j < 0) {
            cout << "Padrão encontrado no índice " << s << endl;
            s += (s + m < n) ? m - badChar[text[s + m]] : 1;
        } else {
            s += max(1, j - badChar[text[s + j]]);
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    BoyerMooreSearch(text, pattern);
    return 0;
}

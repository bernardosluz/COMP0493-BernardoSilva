// rabin_karp.cpp

#include <iostream>
#include <string>
using namespace std;

const int d = 256;
const int q = 101;  // Um número primo

void RabinKarpSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    int h = 1;
    int p = 0;
    int t = 0;

    for (int i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    for (int i = 0; i < m; i++) {
        p = (p * d + pattern[i]) % q;
        t = (t * d + text[i]) % q;
    }

    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            int j = 0;
            while (j < m && text[i + j] == pattern[j]) {
                j++;
            }
            if (j == m) {
                cout << "Padrão encontrado no índice " << i << endl;
            }
        }

        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0) t += q;
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    RabinKarpSearch(text, pattern);
    return 0;
}

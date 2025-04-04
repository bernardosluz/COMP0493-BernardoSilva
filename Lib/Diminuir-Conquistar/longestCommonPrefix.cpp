#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Complexidade O(n) ou O(n*m)

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    // Inicializa o prefixo comum como a primeira string
    string prefix = strs[0];

    // Itera pelas outras strings
    for (int i = 1; i < strs.size(); i++) {
        // Encontra o prefixo comum entre 'prefix' e 'strs[i]'
        int j = 0;
        while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]) {
            j++;
        }
        // Atualiza o prefixo comum
        prefix = prefix.substr(0, j);

        // Se o prefixo se tornar vazio, já podemos retornar
        if (prefix == "") return "";
    }

    return prefix;
}

int main() {
    vector<string> strs = {"flower", "flow", "flight"};

    // Chamada da função
    string result = longestCommonPrefix(strs);

    // Resultado
    cout << "Longest Common Prefix: " << result << endl;

    return 0;
}
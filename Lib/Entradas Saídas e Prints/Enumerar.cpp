#include <iostream>
#include <string>

using namespace std;

int main() {
    // Use std::string para manipulação de strings
    string str = "10k";

    for (int i = 0; i < 15; i++) {
        // Concatenar e exibir string com o índice
        //cout << str << (i + 1) << endl;
        cout << str << endl;
    }

    return 0;
}
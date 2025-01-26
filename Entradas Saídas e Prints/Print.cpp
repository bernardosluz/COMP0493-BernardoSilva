#include <iostream>
#include <vector>

// Sobrecarga do operador << para imprimir um Tipo Específico
/*
struct Type{
    int integer;
    double real;
}
ostream& operator << (ostream& os, const Type& parameter) {
    os << "(" << parameter.integer << parameter.real;
    return os;
}
*/

/*
*   O template em C++ é um recurso que permite criar funções ou classes genéricas, ou seja, 
*   que podem operar com diferentes tipos de dados sem precisar reescrever o código para cada tipo.
*   É uma forma de aplicar a reutilização de código, tornando-o mais flexível e escalável.
*/

using namespace std;

template <typename T>
void printVector(const vector<T>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i != vec.size() - 1) {
            cout << ", "; // Adiciona vírgula entre os elementos
        }
    }
    cout << "]" << endl;
}

int main(){
    // Vetor de strings
    vector<string> vetor_strings = {"Arthur", "Bernardo", "Anderson"};
    
    // Vetor de inteiros
    vector<int> vetor_ints = {5, 4, 3, 2, 1};
    
    // Vetor de doubles
    vector<double> vetor_doubles = {3.14, 2.71, 1.41, 1.73};

    printVector(vetor_strings);
    printVector(vetor_ints);
    printVector(vetor_doubles);

    return 0;
}
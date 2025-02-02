#include <iostream>

using namespace std;

// Função que lê 'num' casos e imprime o número do caso e o valor fornecido
void numberCases(int num){

    while(num--){
        int in;
        cin >> in;
        cout << num << " - " << in << endl;
    }
}

// Função que lê números até que seja encontrado o valor 0
void stopInZero(void){
    int num;
    while(cin >> num){
        if(num == 0)
            break;
        cout << num << endl;
    }
}

// Função que lê números até o final do arquivo (EOF)
void whileNoEnd(){
    int num;
    
    while(cin >> num) {
        cout << num << endl; 
    }
}

int main(){
    // Chama a função numberCases com 3 casos
    numberCases(3);

    // Chama a função stopInZero, que interrompe ao encontrar 0
    stopInZero();

    // Chama a função whileNoEnd, que irá ler até EOF
    whileNoEnd();

    return 0;
}

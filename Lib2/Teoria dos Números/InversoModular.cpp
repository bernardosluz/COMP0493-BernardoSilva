// modular_inverse.cpp

#include <iostream>
using namespace std;

int gcd(int a, int b, int& x, int& y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int g = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return g;
}

int modInverse(int a, int m) {
    int x, y;
    int g = gcd(a, m, x, y);
    if (g != 1) {
        cout << "Inverso modular não existe\n";
        return -1;
    }
    return (x % m + m) % m;
}

int main() {
    int a = 3, m = 11;
    int inv = modInverse(a, m);
    if (inv != -1) {
        cout << "O inverso modular de " << a << " módulo " << m << " é: " << inv << endl;
    }
    return 0;
}

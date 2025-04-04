// coef_binomial_analytical.cpp

#include <iostream>
using namespace std;

int binomialCoeff(int n, int k) {
    if (k > n) return 0;
    long long res = 1;
    if (k > n - k) k = n - k;
    for (int i = 0; i < k; i++) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

int main() {
    int n = 5, k = 2;
    cout << "Coeficiente binomial de " << n << " escolhe " << k << " é: " << binomialCoeff(n, k) << endl;
    return 0;
}

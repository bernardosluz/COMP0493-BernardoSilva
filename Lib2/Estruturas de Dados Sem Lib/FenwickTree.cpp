// fenwick_tree.cpp

#include <iostream>
#include <vector>
using namespace std;

class FenwickTree {
    vector<int> BIT;
    int n;

public:
    FenwickTree(int n) {
        this->n = n;
        BIT.resize(n + 1, 0);
    }

    void update(int index, int value) {
        while (index <= n) {
            BIT[index] += value;
            index += index & -index;
        }
    }

    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += BIT[index];
            index -= index & -index;
        }
        return sum;
    }
};

int main() {
    FenwickTree BIT(5);
    BIT.update(1, 3);
    BIT.update(2, 2);
    BIT.update(3, 1);
    cout << "Soma até o índice 3: " << BIT.query(3) << endl;
    return 0;
}

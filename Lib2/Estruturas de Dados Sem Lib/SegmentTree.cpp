// segment_tree.cpp

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class SegmentTree {
    vector<int> tree, arr;
    int n;

    int build(int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return tree[node];
        }

        int mid = (start + end) / 2;
        int left = build(2 * node, start, mid);
        int right = build(2 * node + 1, mid + 1, end);

        tree[node] = left + right; // Soma
        return tree[node];
    }

    int querySum(int node, int start, int end, int L, int R) {
        if (R < start || end < L) return 0; // Não está dentro do intervalo
        if (L <= start && end <= R) return tree[node]; // Totalmente dentro do intervalo

        int mid = (start + end) / 2;
        int left = querySum(2 * node, start, mid, L, R);
        int right = querySum(2 * node + 1, mid + 1, end, L, R);

        return left + right;
    }

    void update(int node, int start, int end, int idx, int value) {
        if (start == end) {
            arr[idx] = value;
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                update(2 * node, start, mid, idx, value);
            } else {
                update(2 * node + 1, mid + 1, end, idx, value);
            }
            tree[node] = tree[2 * node] + tree[2 * node + 1]; // Soma
        }
    }

public:
    SegmentTree(vector<int>& input) {
        arr = input;
        n = input.size();
        tree.resize(4 * n, 0);
        build(1, 0, n - 1);
    }

    int query(int L, int R) {
        return querySum(1, 0, n - 1, L, R);
    }

    void update(int idx, int value) {
        update(1, 0, n - 1, idx, value);
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    SegmentTree segTree(arr);

    cout << "Soma entre índices 1 e 3: " << segTree.query(1, 3) << endl;

    segTree.update(2, 10);
    cout << "Soma entre índices 1 e 3 após atualização: " << segTree.query(1, 3) << endl;

    return 0;
}

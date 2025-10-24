#include <bits/stdc++.h>
using namespace std;

const int k = 25; // maximum power of 2 for sparse table

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i]; // read input array
    }

    // build sparse table for RMQ
    vector<vector<int>> st(k, vector<int>(n));
    st[0] = a; // interval length 1
    for (int i = 1; i < k; i++) {
        for (int j = 0; j + (1 << i) <= n; j++) {
            st[i][j] = min(st[i-1][j], st[i-1][j + (1 << (i - 1))]); // combine intervals
        }
    }

    // precompute logarithms for fast query
    vector<int> lg(n + 1);
    lg[1] = 0;
    for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;

    int q;
    cin >> q;
    while (q--) {
        int i, j;
        cin >> i >> j;
        int len = lg[j - i + 1]; // largest power of 2 inside range
        cout << min(st[len][i], st[len][j - (1 << len) + 1]) << endl; // RMQ answer
    }
}

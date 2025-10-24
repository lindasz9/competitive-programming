#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast exponentiation: computes a^b
ll binpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a;  // Multiply result if current bit is 1
        a = a * a;                 // Square base
        b >>= 1;                    // Shift to next bit
    }
    return res;
}

int main() {
    int n;
    cin >> n; // Number of successive cars of the same make

    // The total number of ways to fill the parking lot:
    // 4^(n-3) * (24 + 9*(n-3))
    // - 4^(n-3): ways to choose makes for remaining positions
    // - 24 + 9*(n-3): combinatorial counting for first positions
    cout << binpow(4, n - 3) * (24 + 9 * (n - 3)) << endl;
}

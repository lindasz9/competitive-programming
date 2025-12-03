#include <bits/stdc++.h>
using namespace std;

const int M = 1e9+7; // modulo

// modular inverse using binary exponentiation
int inv(int b) {
    int res = 1;
    int c = M - 2; // Fermat's little theorem
    while (c) {
        if (c & 1) res = 1LL * res * b % M;
        b = 1LL * b * b % M;
        c >>= 1;
    }
    return res;
}

int main() {
	int n, m;
    cin >> n >> m; // number of children and apples

    vector<int> fact(n + m); // factorials modulo M
    fact[0] = 1;
    for (int i = 1; i < n + m; i++)
        fact[i] = 1LL * i * fact[i - 1] % M;

    // compute C(n+m-1, m) = (n+m-1)! / (m! * (n-1)!)
    int a = fact[n + m - 1];
    int b = 1LL * fact[m] * fact[n - 1] % M;

    cout << 1LL * a * inv(b) % M << '\n'; // number of ways modulo M
}

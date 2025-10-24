#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll m = 1e9 + 7; // Modulo

// Function to compute (F_n, F_{n+1}) using fast doubling
pair<ll, ll> fib(ll n) {
    if (n == 0) return {0, 1}; // Base case: F0=0, F1=1

    pair<ll, ll> p = fib(n >> 1); // Recursive call for floor(n/2)
    ll a = p.first * ((2 * p.second - p.first + m) % m) % m; // F_{2k} formula
    ll b = (p.first * p.first % m + p.second * p.second % m) % m; // F_{2k+1} formula

    if (n % 2) return {b, (a + b) % m}; // If n is odd
    else return {a, b};                 // If n is even
}

int main() {
    ll n;
    cin >> n;            // Input n (0 ≤ n ≤ 10^18)
    pair<ll, ll> p = fib(n); // Compute (F_n, F_{n+1})
    cout << p.first << endl; // Output F_n modulo 10^9+7
}

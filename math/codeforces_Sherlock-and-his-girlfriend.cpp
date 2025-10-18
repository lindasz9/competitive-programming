#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    n++;  // adjust for 1-based indexing to match prices 2..n+1

    vector<int> lp(n + 1); // least prime factor for each number
    vector<int> pr;        // list of primes

    // Sieve of Eratosthenes to compute least prime factors
    for (int i = 2; i <= n; i++) {
        if (lp[i] == 0) {
            pr.push_back(i);
            lp[i] = i;
        }
        for (int j : pr) {
            if (lp[i] < j || j * i > n) break;
            lp[j * i] = j;
        }
    }

    // Minimal number of colors
    if (n < 4) cout << "1\n";  // only one jewelry piece (price 2 or 3)
    else cout << "2\n";         // for n >= 3, two colors suffice

    // Assign colors: primes get color 1, composites get color 2
    for (int i = 2; i <= n; i++){
        if (lp[i] == i) cout << 1 << " ";
        else cout << 2 << " ";
    }
    cout << "\n";
}

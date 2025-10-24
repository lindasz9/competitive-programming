#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin >> t;  // Number of test cases
    while (t--) {
        int a, b;
        cin >> a >> b;  // Read the two largest divisors

        // Compute GCD of a and b using Euclidean algorithm
        int x = a, y = b;
        while (x) {
            y %= x;
            swap(x, y);
        }
        int gcd = y;  // GCD of a and b

        // LCM formula: lcm(a,b) = a * b / gcd(a,b)
        long long res = 1LL * a * b / gcd;

        cout << res << endl;  // Output the reconstructed number
    }
}

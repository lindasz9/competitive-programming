#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;  // Input: a Fibonacci number (0 ≤ n < 10^9)

    // Observation:
    // Any Fibonacci number F_n can trivially be represented as:
    // F_n = F_n + F_0 + F_0
    // because F_0 = 0, so this satisfies the sum condition.
    
    // Therefore, we can always output:
    cout << n << " 0 0\n";
}

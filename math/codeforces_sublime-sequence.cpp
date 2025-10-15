#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); // Fast I/O

    int t;
    cin >> t;  // Number of test cases
    while (t--) {
        int x, n;
        cin >> x >> n;  // Read the integer x and sequence length n

        // Sequence is x, -x, x, -x, ...
        // If n is odd, there is one extra x, so sum = x
        // If n is even, x and -x cancel out in pairs, so sum = 0
        if (n % 2) 
            cout << x << endl;
        else 
            cout << 0 << endl;
    }
}

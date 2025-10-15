#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); // Fast I/O

    int t;
    cin >> t;  // Number of test cases
    while (t--) {
        int x, n;
        cin >> x >> n;  // Input values

        // If n is odd, output x; if even, output 0
        if (n % 2) cout << x << endl;
        else cout << 0 << endl;
    }
}

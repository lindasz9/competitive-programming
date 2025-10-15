#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); // Fast I/O

    int t;
    cin >> t;  // Number of test cases
    while (t--) {
        int a, b;
        cin >> a >> b;  // Input numbers
        int after = 0, aa = a, bb = b;  // Store original values of a and b

        if (!(b % a)) after = b / a;  // If a divides b, compute the quotient

        // Compute GCD of a and b using Euclidean algorithm
        while (a) {
            b %= a;
            swap(a, b);
        }

        int res = b;  // b now holds the GCD
        res = bb / res * aa;  // Compute LCM using formula LCM(a,b) = a*b/GCD(a,b)

        if (!(bb % aa)) res = res / aa * bb;  // Adjust LCM if bb is divisible by aa
        cout << res << endl;  // Output result
    }
}

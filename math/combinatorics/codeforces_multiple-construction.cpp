#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); // Fast input/output

    int t;
    cin >> t; // Number of test cases
    while (t--) {
        int n;
        cin >> n; // Input n

        if (n == 1) {
            // Special case: only one number
            cout << 1 << " " << 1 << endl;
            continue;
        }

        // The idea is to construct the array in a specific interleaving pattern
        // so that the distance between the two occurrences of each number x
        // is divisible by x.

        int k = n % 2 ? 1 : 2; // Adjust starting point depending on parity

        // Print the first occurrence of numbers in a specific descending order
        for (int i = n - k; i > 1; i -= 2) cout << i << " ";
        cout << n << " "; // Append the largest number
        for (int i = 2; i < n; i += 2) cout << i << " ";
        cout << 1 << " "; // Append the smallest number

        // Print the second occurrence of numbers in a specific pattern
        k = n % 2 ? 2 : 1; // Adjust starting point for the second half
        for (int i = n - k; i > 2; i -= 2) cout << i << " ";
        cout << n << " "; // Append the largest number again
        cout << 1 << " "; // Append the smallest number again
        for (int i = 3; i < n; i += 2) cout << i << " ";

        cout << endl; // End of this test case
    }
}

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); // Fast I/O

    int t;
    cin >> t;  // Number of test cases
    while (t--) {
        int n;
        cin >> n;  // Length of the binary string
        string s;
        cin >> s;  // Input binary string

        int cnt1 = 0, cnt0 = 0;  // Counters for '1's and '0's
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') cnt0++;
            else cnt1++;
        }

        int wrong = 0;  // Count of misplaced characters
        for (int i = 0; i < n; i++) {
            // '0's should be in the first cnt0 positions
            // '1's should be in the last cnt1 positions
            if ((s[i] == '0' && i >= cnt0) || (s[i] == '1' && i < n - cnt1)) wrong++;
        }

        // Minimum swaps needed is half of the misplaced positions, rounding up
        cout << (wrong / 2 + wrong % 2) << endl;
    }
}

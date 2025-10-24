#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        int n;
        cin >> n; // Length of the binary string
        string s;
        cin >> s; // The binary string itself

        int cnt1 = 0, cnt0 = 0;
        // Count the number of 0s and 1s in the string
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') cnt0++;
            else cnt1++;
        }

        int wrong = 0;
        // Determine the number of 'misplaced' characters
        // '0's should be in the first cnt0 positions, '1's in the rest
        for (int i = 0; i < n; i++) {
            if ((s[i] == '0' && i >= cnt0) || (s[i] == '1' && i < n - cnt1)) 
                wrong++; // Count each character that is out of its target segment
        }

        // Minimum operations:
        // Each operation can fix up to 2 misplaced characters
        // If 'wrong' is odd, we need an extra operation
        cout << (wrong / 2 + wrong % 2) << endl;
    }
}

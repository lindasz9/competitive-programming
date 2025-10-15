#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); // Fast I/O

    int t;
    cin >> t;  // Number of test cases
    while (t--) {
        int n;
        cin >> n;  // Size of the sequence
        vector<int> val(n + 1), cnt(n + 1), res(n);  
        // val[b] stores the assigned value for number b
        // cnt[b] stores how many more times b can appear
        // res stores the resulting sequence

        int x = 1;  // Counter for assigning unique values
        for (int i = 0; i < n; i++) {
            int b;
            cin >> b;  // Read element
            if (cnt[b] == 0) {  // First time seeing b
                val[b] = x;     // Assign a new unique number to b
                x++;            // Increment unique number counter
                cnt[b] = b;     // Set count of remaining occurrences allowed
            }
            res[i] = val[b];    // Store assigned value in result
            cnt[b]--;           // Decrease remaining occurrences
        }

        bool valid = true;  // Flag to check if sequence is valid
        for (int i : cnt) {
            if (i > 0) {  // If any number has leftover occurrences
                cout << -1 << endl;  // Invalid sequence
                valid = false;
                break;
            }
        }

        if (valid) {  // If valid, print the resulting sequence
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); // Fast input/output

    int t;
    cin >> t; // Number of test cases
    while (t--) {
        int n;
        cin >> n; // Size of the array b
        vector<int> val(n + 1), cnt(n + 1), res(n); 
        // val[b] will store the value assigned to elements with frequency b
        // cnt[b] keeps track of how many more times we need to assign this value
        // res stores the resulting array a

        int x = 1; // The next available number to assign in array a

        for (int i = 0; i < n; i++) {
            int b;
            cin >> b; // Read the desired frequency for position i

            if (cnt[b] == 0) { 
                // If we haven't assigned a number for this frequency yet
                val[b] = x; // Assign the next available number to this frequency
                x++;        // Increment for the next new value
                cnt[b] = b; // Set how many times this value should appear
            }

            res[i] = val[b]; // Assign the corresponding value to array a
            cnt[b]--;        // Decrease the remaining count for this value
        }

        bool valid = true;
        // After assignment, check if all counts are satisfied
        for (int i : cnt) {
            if (i > 0) { 
                cout << -1 << endl; // If some count not satisfied, it's invalid
                valid = false; 
                break; 
            }
        }

        if (valid) {
            // Print the constructed array a
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
}

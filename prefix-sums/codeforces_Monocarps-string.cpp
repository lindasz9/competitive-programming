#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int n;
        cin >> n;      // Length of the string
        string s;
        cin >> s;      // The string consisting of 'a' and 'b'

        vector<int> pref(n + 1);  // Prefix sum array
        pref[0] = 0;

        // Map to store first occurrences of each prefix sum
        unordered_map<int, int> first_occurrence;

        // Compute prefix sums: +1 for 'a', -1 for 'b'
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') pref[i + 1] = pref[i] + 1;
            else pref[i + 1] = pref[i] - 1;
        }

        int total_diff = pref[n]; // Total difference between 'a's and 'b's
        int ans = n;              // Initialize answer with n

        // If string already has equal 'a' and 'b'
        if (total_diff == 0) {
            cout << 0 << endl;
            continue;
        }

        // Iterate through the prefix sums
        for (int i = 0; i <= n; i++) {
            int target = pref[i] - total_diff; // Needed prefix sum to balance
            if (first_occurrence.count(target))
                ans = min(ans, i - first_occurrence[target]); // Update minimal removal
            first_occurrence[pref[i]] = i; // Record first occurrence
        }

        // If no valid subarray found, must remove entire string
        if (ans == n) cout << -1 << endl;
        else cout << ans << endl;
    }
}

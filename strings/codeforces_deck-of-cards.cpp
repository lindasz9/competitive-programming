#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int n, k;
        cin >> n >> k; // Number of cards and number of actions
        string s;
        cin >> s;      // Actions string

        // If all cards are removed, output '-' for all
        if (n == k) {
            while (k--) cout << '-';
            cout << endl;
            continue;
        }

        // Counters for different actions
        int l0 = 0, r1 = 0; // Top-only and bottom-only removals
        int l2 = 0, r2 = 0; // Removals that could be either top or bottom

        // Count occurrences of each action
        for (int i = 0; i < k; i++) {
            if (s[i] == '0') l0++;    // Remove top
            else if (s[i] == '1') r1++; // Remove bottom
            else {
                l2++; r2++;            // Remove either top or bottom
            }
        }

        // Print '-' for cards definitely removed from the top
        for (int i = 0; i < l0; i++) cout << '-';

        if (l0 + r1 + l2 + r2 > n) {
            // Too many removals, remaining uncertain cards are all '?'
            for (int i = 0; i < n - l0 - r1; i++) cout << '?';
        } else {
            // Print '?' for cards that might be removed from the top
            for (int i = 0; i < l2; i++) cout << '?';
            // Print '+' for cards definitely remaining
            for (int i = 0; i < n - l0 - r1 - l2 - r2; i++) cout << '+';
            // Print '?' for cards that might be removed from the bottom
            for (int i = 0; i < r2; i++) cout << '?';
        }

        // Print '-' for cards definitely removed from the bottom
        for (int i = 0; i < r1; i++) cout << '-';
        cout << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
string s;

// Recursive function to check if a valid rabbit arrangement exists
// i = current index in the string
// a, b = states of the previous two pots (used to track potential jumps)
//     0 = no rabbit, 1 = rabbit looking left, 2 = rabbit looking right
bool solve(int i, int a, int b) {
    if (i == n) {
        // End of array: invalid if previous pot had a rabbit looking left and the one before it empty
        if (a == 1 && b == 0) return false;
        return true;
    }

    if (a == 1 && b == 0) {
        // Previous pot had a rabbit looking left and empty pot before that → must assign current as right-looking rabbit
        if (s[i] == '0') return solve(i + 1, 0, 2);
        return false; 
    }

    if (b == 1 || b == 2) {
        // Last pot had a rabbit: decide current based on empty/occupied
        if (s[i] == '0') return solve(i + 1, b, 1) || solve(i + 1, b, 2);
        return solve(i + 1, b, 0);
    }

    // General case: current pot is empty → choose left-looking rabbit
    if (s[i] == '0') return solve(i + 1, 0, 1);
    return solve(i + 1, 0, 0); // Current pot occupied → no rabbit
}

int main() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        cin >> n; 
        cin >> s; // Binary string of pots

        if (n < 3) {
            // For very small arrays, always possible
            cout << "YES" << endl;
            continue;
        }

        bool ans;
        // Initial conditions depend on the first two pots
        if (s[0] == '1') {
            ans = solve(2, 0, 1 - (s[1] - '0')); // Adjust state based on second pot
        } else if (s[0] == '0' && s[1] == '1') {
            ans = solve(2, 1, 0) || solve(2, 2, 0); // First pot empty, second pot occupied
        } else {
            ans = solve(2, 0, 2) || solve(2, 0, 1); // First two pots empty
        }

        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

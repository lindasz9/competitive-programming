#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
    cin >> n;          // length of the string
    string s;
    cin >> s;          // input string

    vector<vector<int>> dp(n, vector<int>(n)); 
    // dp[l][r] = minimum operations to remove substring s[l..r]

    for (int i = 0; i < n; i++) 
        dp[i][i] = 1;  // single character needs one operation

    // consider substrings of increasing length
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int l = j, r = j + i;
            if (r >= n) break;

            // remove s[l] separately
            dp[l][r] = dp[l+1][r] + 1;

            // try to merge removals if same characters appear
            for (int k = l + 1; k <= r; k++) {
                if (s[l] == s[k])
                    dp[l][r] = min(dp[l][r], dp[l+1][k-1] + dp[k][r]);
            }
        }
    }

    cout << dp[0][n-1] << '\n'; // minimum operations for whole string
}

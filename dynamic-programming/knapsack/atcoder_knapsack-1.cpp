#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, W;
    cin >> n >> W;

    // dp[j] will store the maximum total value achievable
    vector<ll> dp(W + 1, 0);

    // Process each item one by one
    for (int i = 1; i <= n; i++) {
        int w, v;
        cin >> w >> v;

        // Iterate backwards to ensure each item is only used once
        for (int j = W; j >= w; j--) {
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }

    // The answer is the maximum value with total weight ≤ W
    cout << dp[W] << "\n";
}

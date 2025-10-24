#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(3, n));
    // dp[i][0] = minimum rest days if day i is a rest day
    // dp[i][1] = minimum rest days if day i is a contest day
    // dp[i][2] = minimum rest days if day i is a gym day

    dp[0][0] = dp[0][1] = dp[0][2] = 0; // Base case: no days yet, 0 rest

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        // If Vasya rests on day i, add 1 to the min of previous day's states
        dp[i][0] = 1 + min({dp[i-1][0], dp[i-1][1], dp[i-1][2]});

        // If Vasya can do a contest today (x=1 or 3), choose min of previous day being rest or gym
        if (x == 1 || x == 3) dp[i][1] = min(dp[i-1][0], dp[i-1][2]);

        // If Vasya can go to gym today (x=2 or 3), choose min of previous day being rest or contest
        if (x == 2 || x == 3) dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
    }

    // Answer is min of last day's states
    cout << min({dp[n][0], dp[n][1], dp[n][2]}) << endl;
}

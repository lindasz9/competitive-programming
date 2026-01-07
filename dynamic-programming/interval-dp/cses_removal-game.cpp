#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 5001;
ll dp[maxn][maxn][2]; 
// dp[l][r][0]: maximum score current player can obtain from interval [l, r]
// dp[l][r][1]: maximum score the other player can obtain from interval [l, r]

int main() {
	int n;
    cin >> n;                 // number of elements
	vector<ll> x(n);
	for (int i = 0; i < n; i++) 
        cin >> x[i];          // values on the table

    // base case: only one element
    for (int i = 0; i < n; i++) {
        dp[i][i][0] = x[i];   // current player takes the only element
        dp[i][i][1] = 0;      // other player gets nothing
    }

    // build DP for increasing interval lengths
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll l = j, r = i + j;
            if (r >= n) break;

            // current player chooses left or right end
            dp[l][r][0] = max(
                x[l] + dp[l+1][r][1],
                x[r] + dp[l][r-1][1]
            );

            // opponent plays optimally to minimize current player's future gain
            dp[l][r][1] = min(
                dp[l+1][r][0],
                dp[l][r-1][0]
            );
        }
    }

    cout << dp[0][n-1][0] << '\n'; // maximum score first player can achieve
}

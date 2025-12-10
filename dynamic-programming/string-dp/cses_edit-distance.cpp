#include <bits/stdc++.h>
using namespace std;

int main() {
	string s, t;
	cin >> s >> t;

	s = ' ' + s; // 1-based indexing
	t = ' ' + t;
	int n = s.size(), m = t.size();

	vector<vector<int>> dp(n, vector<int>(m)); // dp[i][j] = edit distance between s[1..i] and t[1..j]

	// base cases: transforming empty string
	for (int i = 0; i < n; i++) dp[i][0] = i; // remove all characters from s
	for (int j = 0; j < m; j++) dp[0][j] = j; // add all characters to s

	// fill dp table
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (s[i] == t[j])
				dp[i][j] = dp[i-1][j-1]; // no operation needed
			else
				dp[i][j] = min({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]}) + 1;
                // replace, insert, delete
		}
	}

	cout << dp[n-1][m-1] << '\n'; // minimal edit distance
}

#include <bits/stdc++.h>
using namespace std;

int main() {
	string s, t;
	cin >> s >> t;

	s = ' ' + s; // 1-based indexing
	t = ' ' + t;
	int n = s.size(), m = t.size();

	vector<vector<int>> dp(n, vector<int>(m)); // dp[i][j] = LCS length of s[1..i], t[1..j]

	// fill dp table
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (s[i] == t[j])
				dp[i][j] = dp[i-1][j-1] + 1; // extend LCS
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]); // take max from previous
		}
	}

	// reconstruct LCS
	int i = n-1, j = m-1;
	string res = "";
	while (i > 0 && j > 0) {
		if (s[i] == t[j]) {
			res.push_back(s[i]);
			i--; j--;
		} else if (dp[i-1][j] > dp[i][j-1]) i--;
		else j--;
	}

	reverse(res.begin(), res.end()); // correct order
	cout << res << '\n';
}

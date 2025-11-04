#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n, m;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> m;
	vector<int> b(m);
	for (int i = 0; i < m; i++) cin >> b[i];

	vector<int> dp(m), p(m, -1); // dp[j]: LCIS ending at b[j], p[j]: previous index in LCIS

	// process each element of 'a'
	for (int i : a) {
		int curmax = 0, last = -1; // best LCIS length for smaller elements
		for (int j = 0; j < m; j++) {
			if (i == b[j]) { // match found, extend best subsequence
				dp[j] = curmax + 1;
				p[j] = last;
			}
			else if (i > b[j] && dp[j] > curmax) { // track best smaller element
				curmax = dp[j];
				last = j;
			}
		}
	}

	// find maximum LCIS length and position
	int ans = 0, pos = -1;
	for (int i = 0; i < m; i++)
		if (dp[i] > ans) {
			ans = dp[i];
			pos = i;
		}

	cout << ans << endl;

	// reconstruct LCIS
	vector<int> res(ans);
	int id = ans - 1;
	for (int i = pos; i != -1; i = p[i]) {
		res[id--] = b[i];
	}
	for (int i : res) cout << i << " ";
	cout << endl;
}

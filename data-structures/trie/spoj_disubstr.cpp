#include <bits/stdc++.h>
using namespace std;

int t[500000][128]; // trie transitions for all ASCII characters
int cnt = 2;        // current number of nodes (root = 1)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt;
    cin >> tt; // number of test cases

	while (tt--) {
		string s;
        cin >> s;
		int n = s.size();

    // insert all substrings into the trie
		for (int i = 0; i < n; i++) {
			int x = 1; // start from root
			for (int j = i; j < n; j++) {
				int c = s[j];
				if (!t[x][c]) {
					t[x][c] = cnt++; // create new node if needed
				}
				x = t[x][c]; // move to next node
			}
		}

    // number of distinct substrings = number of non-root nodes
		cout << cnt - 2 << '\n';

    // reset trie for next test case
		for (int i = 1; i <= cnt - 1; i++)
			for (int &j : t[i]) j = 0;

		cnt = 2; // reset node counter
	}
}

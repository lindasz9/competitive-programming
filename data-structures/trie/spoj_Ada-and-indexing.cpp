#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 1;
int t[maxn][26]; // trie transitions
int db[maxn];    // number of strings passing through each node
int cnt = 1;     // number of nodes in trie (root = 0)

int main() {
	int n, q;
    cin >> n >> q; // number of strings and queries

    // build the trie
	for (int i = 0; i < n; i++) {
		string s;
    cin >> s;
		int x = 0; // start from root
		for (char c : s) {
			int j = c - 'a';
			if (!t[x][j]) {
				t[x][j] = cnt++; // create new node if missing
			}
			x = t[x][j];
			db[x]++; // increment count for this prefix
		}
	}

    // process queries
	while (q--) {
		string s;
    cin >> s;
		int x = 0, ans = -1;
		for (char c : s) {
			int j = c - 'a';
			if (!t[x][j]) { // prefix does not exist
				ans = 0;
				break;
			}
			x = t[x][j];
			ans = db[x]; // number of strings with this prefix
		}
		cout << ans << '\n';
	}
}

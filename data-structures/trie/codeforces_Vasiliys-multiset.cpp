#include <bits/stdc++.h>
using namespace std;

const int mx = 200001 * 32; 
int t[mx][2]; // trie for binary representation
int db[mx];   // count of numbers passing through each node
int cnt = 1;  // current number of nodes (root = 0)

// insert number x into trie
void add(int x) {
	int j = 0;
	for (int b = 31; b >= 0; b--) {
		int bit = (x & (1 << b)) >> b;
		if (!t[j][bit]) t[j][bit] = cnt++;
		j = t[j][bit];
		db[j]++; // increment count
	}
}

int main() {
	int q;
        cin >> q;

	add(0); // initial multiset contains 0

	while (q--) {
		char c;
        int x;
        cin >> c >> x;

		if (c == '+') 
            add(x);
		else if (c == '-') {
			int j = 0;
			for (int b = 31; b >= 0; b--) {
				int bit = (x & (1 << b)) >> b;
				j = t[j][bit];
				db[j]--; // decrement count
			}
		} else { // query '?'
			int j = 0, res = 0;
			for (int b = 31; b >= 0; b--) {
				int bit = (x & (1 << b)) >> b;
				int bit2 = bit ^ 1; // try opposite bit for maximizing XOR
				if (db[t[j][bit2]]) {
					res |= (1 << b);
					j = t[j][bit2];
				} else {
					j = t[j][bit];
				}
			}
			cout << res << '\n';
		}
	}
}

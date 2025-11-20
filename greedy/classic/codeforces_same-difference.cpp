#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t; // number of test cases
	while (t--) {
		int n;
		cin >> n; // length of string
		string s;
		cin >> s; // input string
		
		char c = s[n-1]; // target character is the last character
		int ans = 0;
		
		// count characters different from the last character
		for (char x : s) 
			if (x != c) ans++;
		
		cout << ans << '\n'; // minimum operations needed
	}
}

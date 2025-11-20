#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t; // number of test cases
	while(t--) {
		long long a, b, n;
		cin >> a >> b >> n; // screen length, max tab length, number of tabs

		// If max tab length is small enough so that all tabs fit individually 
        // or all tabs have the same length as the screen, only 1 move is needed
		if (b <= 1LL * a / n || a == b) 
            cout << "1\n";
		else 
            // Otherwise, at least 2 moves are needed to close all tabs
			cout << "2\n";
	}
}

#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

int main() {
	int t;
	cin >> t; // number of test cases
	while (t--) {
		int n;
		cin >> n; // length of sequence
		
		int low = INF, high = -INF; // track min and max of sequence
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a; 
			low = min(low, a);   // update minimum
			high = max(high, a); // update maximum
		}
		
		int x;
		cin >> x; // target number
		
		// check if x lies within min-max range
		if (x >= low && x <= high) 
			cout << "yes\n";
		else 
			cout << "no\n";
	}
}

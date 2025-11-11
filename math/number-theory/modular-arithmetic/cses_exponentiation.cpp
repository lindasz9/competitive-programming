#include <bits/stdc++.h>
using namespace std;

const int m = 1e9 + 7; // modulus

int main() {
	int n;
	cin >> n; // number of calculations
	while (n--) {
		int a, b;
		cin >> a >> b; // base and exponent
		int res = 1;   // result initialized to 1
		while (b > 0) {
			if (b & 1) res = 1LL * res * a % m; // multiply result by current base if LSB of exponent is 1
			a = 1LL * a * a % m; // square base for next bit
			b >>= 1;             // shift exponent to right (divide by 2)
		}
		cout << res << '\n'; // print result modulo m
	}
}

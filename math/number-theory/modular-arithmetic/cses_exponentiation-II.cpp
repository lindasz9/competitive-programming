#include <bits/stdc++.h>
using namespace std;

const int m = 1e9 + 7; // modulus

// binary exponentiation function: calculates (a^b) % mod
int binexp(int a, int b, int mod) {
	int res = 1; // result initialized to 1
	while (b > 0) {
		if (b & 1) res = 1LL * res * a % mod; // multiply if current bit of exponent is 1
		a = 1LL * a * a % mod; // square the base
		b >>= 1;               // shift exponent right
	}
	return res;
}

int main() {
	int n;
	cin >> n; // number of calculations
	while (n--) {
		int a, b, c;
		cin >> a >> b >> c; // base, exponent, exponent of exponent
		
		int bc = binexp(b, c, m-1); // calculate b^c mod (m-1) using Fermat's theorem
		cout << binexp(a, bc, m) << '\n'; // calculate a^(b^c) mod m
	}
}

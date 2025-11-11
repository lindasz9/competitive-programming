#include <bits/stdc++.h>
using namespace std;

const int m = 1e9 + 7, MAXA = 1e6 + 1; // modulus and maximum value for factorials

// modular inverse using Fermat's little theorem: a^(m-2) % m
int inverse(int a) {
	int res = 1, mm = m-2;
	while (mm > 0) {
		if (mm & 1) res = 1LL * res * a % m; // multiply if current bit is 1
		a = 1LL * a * a % m;                 // square base
		mm >>= 1;                            // shift exponent
	}
	return res;
}

int main() {
	int n;
	cin >> n; // number of calculations
	
	// precompute factorials modulo m
	vector<int> pref(MAXA);
	pref[0] = 1;
	for (int i = 1; i < MAXA; i++) pref[i] = (1LL * pref[i-1] * i) % m;
	
	while (n--) {
		int a, b;
		cin >> a >> b; // a and b for binomial coefficient C(a, b)
		
		// calculate C(a, b) = a! / (b! * (a-b)!) modulo m
		cout << (1LL * pref[a] * inverse(pref[b])) % m * 1LL * inverse(pref[a-b]) % m << '\n';
	}
}

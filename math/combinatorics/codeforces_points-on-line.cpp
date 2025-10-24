#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);

    ll n, d;
    cin >> n >> d; // number of points and maximum allowed distance

    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i]; // read coordinates (strictly increasing)

    ll ans = 0; // total number of valid triplets
    ll l = 0;   // left pointer for sliding window

    // Iterate over right end of triplet window
    for (int r = 2; r < n; r++) {
        // Move left pointer to ensure max distance between x[l] and x[r] <= d
        while (x[r] - x[l] > d) l++;

        ll lr = r - l; // number of points between l and r (excluding r)
        if (lr > 1) 
            ans += (lr * (lr - 1) / 2); // number of ways to choose 2 points between l and r-1
    }

    cout << ans << endl;
}

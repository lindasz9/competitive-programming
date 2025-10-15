#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, k;
    cin >> n >> k;  // Read the length of the array and the threshold K
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];  // Read the array elements

    ll l = 0;       // Left pointer of the sliding window
    ll sum = 0;     // Current sum of the window [l, r]
    ll ans = 0;     // Count of contiguous subsequences satisfying the condition

    for (ll r = 0; r < n; r++) {
        sum += a[r];  // Expand the window by including a[r]

        // Shrink the window from the left while the sum is >= K
        while (sum >= k) {
            ans += (n - r);  // All subarrays starting from 'l' to 'r' and ending at r..n-1 satisfy the condition
            sum -= a[l];     // Remove the leftmost element from sum
            l++;             // Move left pointer rightwards
        }
    }

    cout << ans << endl;  // Output the total count
}

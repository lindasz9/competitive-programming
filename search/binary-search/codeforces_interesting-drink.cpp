#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;                 // Number of shops
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];  // Prices of drinks in each shop
    sort(a.begin(), a.end());  // Sort prices for binary search

    int q;
    cin >> q;                 // Number of days
    for (int i = 0; i < q; i++) {
        int m;
        cin >> m;             // Coins Vasiliy can spend on this day
        int l = 0, r = n - 1, ans = -1;

        // Binary search to find the rightmost shop Vasiliy can afford
        while (l <= r) {
            int mid = (l + r) / 2;
            if (m >= a[mid]) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }

        cout << ans + 1 << endl;  // Number of shops Vasiliy can buy from
    }
}

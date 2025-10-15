#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); // Fast input/output

    int t;
    cin >> t; // Number of test cases
    while (t--) {
        int n;
        cin >> n; // Number of fields
        vector<ll> a(n); // Number of dandelions in each field
        bool odd = false; // Flag to check if there is any field with an odd number

        // Read the fields and check if any field has odd dandelions
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] % 2) odd = true;
        }

        ll ans = 0; // Maximum dandelions FJ can cut
        vector<ll> v; // Store fields with odd dandelions separately

        if (odd) {
            // Separate odd and even fields
            for (ll i : a) {
                if (i % 2) {
                    v.push_back(i); // Odd fields
                } else {
                    ans += i; // Even fields can always be cut, no toggling needed
                }
            }
        } else {
            // All fields are even → mower is initially off, and stays off → nothing cut
            cout << 0 << endl;
            continue;
        }

        // Sort odd fields in ascending order
        sort(v.begin(), v.end());

        // Pick the largest odd field first to maximize cutting
        ans += v.back(); 
        v.pop_back();

        // Remaining odd fields can only be cut in pairs (toggle off/on)
        int half = v.size() / 2;
        if (!(v.size() % 2)) half--; // Adjust if even number of remaining odd fields

        // Add the larger half of the remaining odd fields
        for (int i = v.size() - 1; i > half; i--) ans += v[i];

        cout << ans << endl;
    }
}

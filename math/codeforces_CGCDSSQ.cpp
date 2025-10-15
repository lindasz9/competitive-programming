#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); // Fast input/output

    int n;
    cin >> n; // Length of the sequence
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i]; // Read the array

    // Maps to store counts of GCDs
    unordered_map<int, ll> total; // total[g] = total number of subarrays with GCD = g
    unordered_map<int, ll> cur;   // cur[g] = number of subarrays ending at current index with GCD = g

    for (int i = 0; i < n; i++) {
        unordered_map<int, ll> next; // next will store GCD counts for subarrays ending at a[i]

        // A subarray consisting of only a[i] has GCD = a[i]
        next[a[i]] = 1;

        // Extend previous subarrays by including a[i] and compute new GCDs
        for (auto [g, cnt] : cur) {
            int newg = gcd(g, a[i]); // GCD of previous subarray extended by a[i]
            next[newg] += cnt;       // Add the number of such subarrays
        }

        // Add counts of current subarrays to the total map
        for (auto [g, cnt] : next) total[g] += cnt;

        // Prepare for next iteration
        cur = next;
    }

    int q;
    cin >> q; // Number of queries
    while(q--) {
        int x;
        cin >> x; 
        cout << total[x] << endl; // Output number of subarrays with GCD = x
    }
}

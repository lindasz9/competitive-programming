#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, q;
    cin >> n >> q;                   // Read array size and number of queries
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];  // Read array elements

    while (q--) {
        int d;
        cin >> d;                    // Read the length of the subarray for this query

        deque<int> qmx;              // Will store potential maxima in current window
        int ans = INT_MAX;           // Initialize answer as infinity

        for (int i = 0; i < n; i++) {
            // Remove elements from the back that are smaller than current
            while (!qmx.empty() && qmx.back() < a[i])
                qmx.pop_back();

            qmx.push_back(a[i]);     // Add current element as a potential maximum

            // Remove element that goes out of the window from front
            if (i >= d && qmx.front() == a[i - d]) {
                qmx.pop_front();
            }

            // Once we have a full window, update the minimum of the maxima
            if (i >= d - 1) {
                ans = min(ans, qmx.front());
            }
        }

        // Output the minimum among the maxima of all subarrays of length d
        cout << min(ans, qmx.front()) << endl;
    }
}

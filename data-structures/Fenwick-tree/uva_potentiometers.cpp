#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> fenwick;
vector<int> a;
int n;

// Query prefix sum from 1 to r
ll sum(int r) {
    ll res = 0;
    for (; r > 0; r -= (r & -r)) res += fenwick[r];
    return res;
}

// Update the value at index x to val
void update(int x, int val) {
    int diff = val - a[x]; // difference from previous value
    a[x] = val;            // update actual array
    for (; x <= n; x += (x & -x)) fenwick[x] += diff; // propagate in Fenwick tree
}

int main() {
    int cnt = 1;  // case number
    while (true) {
        cin >> n;
        if (n == 0) break;  // end of input
        if (cnt > 1) cout << "\n";

        fenwick.assign(n + 1, 0);
        a.assign(n + 1, 0);

        // initialize potmeters
        for (int i = 1; i <= n; i++) {
            int b;
            cin >> b;
            update(i, b); // update both array and Fenwick tree
            a[i] = b;
        }

        cout << "Case " << cnt << ":\n";

        // process actions
        while (true) {
            string s;
            cin >> s;
            if (s == "END") break;
            char c = s[0];
            int x, y;
            cin >> x >> y;
            if (c == 'M') {
                // measure resistance: sum of potmeters x..y
                cout << sum(y) - sum(x - 1) << "\n";
            } else {
                // set potmeter x to y Ohms
                update(x, y);
            }
        }
        cnt++;
    } 
}

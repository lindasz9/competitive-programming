#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int cnt = 0;
        vector<int> pref(n, 0);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt += x;
            pref[i] = cnt;
        }
        bool done = false;
        for (int l = 0; l < n - 2; l++) {
            int a = pref[l] % 3;
            for (int r = l + 1; r < n - 1; r++) {
                int b = (pref[r] - pref[l]) % 3;
                int c = (pref[n - 1] - pref[r]) % 3;
                if  ((a == b && b == c) || (a != b && a != c && b != c)) {
                    cout << l + 1 << " " << r + 1 << endl;
                    done = true;
                    break;
                }
            }
            if (done) break;
        }
        if (!done) cout << "0 0" << endl;;
    }
}

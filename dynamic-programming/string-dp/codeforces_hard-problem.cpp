#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = LLONG_MAX;

int main() {
    int n;
    cin >> n;
    vector<ll> c(n); // energy cost to reverse each string
    for (int i = 0; i < n; i++) cin >> c[i];
    vector<string> s(n); // input strings
    for (int i = 0; i < n; i++) cin >> s[i];

    vector<ll> dp0(n, inf), dp1(n, inf);
    dp0[0] = 0;     // cost if first string is not reversed
    dp1[0] = c[0];  // cost if first string is reversed

    for (int i = 1; i < n; i++) {
        string ra(s[i-1].rbegin(), s[i-1].rend()); // reversed previous string
        string rb(s[i].rbegin(), s[i].rend());     // reversed current string

        // current string not reversed
        if (s[i] >= s[i-1] && dp0[i-1] != inf) dp0[i] = dp0[i-1];
        if (s[i] >= ra && dp1[i-1] != inf) dp0[i] = min(dp0[i], dp1[i-1]);

        // current string reversed
        if (rb >= s[i-1] && dp0[i-1] != inf) dp1[i] = dp0[i-1] + c[i];
        if (rb >= ra && dp1[i-1] != inf) dp1[i] = min(dp1[i], dp1[i-1] + c[i]);

        // impossible to maintain order
        if (dp0[i] == inf && dp1[i] == inf) {
            cout << -1 << endl;
            return 0;
        }
    }

    // print minimal energy
    if (dp0[n-1] == inf) cout << dp1[n-1] << endl;
    else if (dp1[n-1] == inf) cout << dp0[n-1] << endl;
    else cout << min(dp0[n-1], dp1[n-1]) << endl;
}

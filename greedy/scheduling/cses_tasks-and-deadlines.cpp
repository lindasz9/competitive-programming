#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> ad(n);
    for (int i = 0; i < n; i++) {
        int a, d;
        cin >> a >> d;           // a = duration, d = deadline
        ad[i] = {a, d};
    }

    sort(ad.begin(), ad.end());  // sort tasks by duration (shortest first)

    ll ans = 0, time = 0;
    for (auto p : ad) {
        time += p.first;         // accumulate finishing time
        ans += (p.second - time); // reward = deadline - finishing time
    }

    cout << ans << endl;         // output maximum total reward
}

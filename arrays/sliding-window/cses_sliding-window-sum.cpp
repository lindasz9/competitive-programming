#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    ll n, k, x, a, b, c;
    cin >> n >> k >> x >> a >> b >> c;  // read parameters and generator values

    ll sum = x;          // current window sum
    ll ans = 0;          // final XOR of all window sums
    deque<ll> q;         // to store elements of the current window
    q.push_back(x);

    if (k == 1) ans = x; // special case: single-element windows

    for (int i = 1; i < n; i++) {
        // generate next number using formula xᵢ = (a * xᵢ₋₁ + b) mod c
        ll res = (a * q.back() + b) % c;
        sum += res;          // add new element to window sum
        q.push_back(res);    // add element to the window

        // when window size reaches k, process it
        if ((ll)q.size() == k) {
            ans ^= sum;      // XOR the current window sum into answer
            sum -= q.front(); // remove oldest element from window
            q.pop_front();
        }
    }

    cout << ans << endl;     // print final XOR of all window sums
}

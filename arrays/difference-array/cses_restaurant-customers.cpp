#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    cin >> n;

    // dif: change in the number of customers at each time point
    map<int,int> dif;

    for (int i = 0; i < n; i++) {
        int a, b; 
        cin >> a >> b;

        dif[a]++;       // increment count at arrival time
        dif[b+1]--;     // decrement count just after leaving time
    }

    int pref = 0;  // current number of customers
    int ans = 0;   // maximum number of customers

    // iterate through all time points in order
    for (auto [time, delta] : dif) {
        pref += delta;        // update current number of customers
        ans = max(ans, pref); // update maximum if needed
    }

    cout << ans << '\n';
}

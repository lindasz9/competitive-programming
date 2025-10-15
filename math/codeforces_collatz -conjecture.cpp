#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t; // Number of test cases
    vector<int> ans(t); // To store possible initial values for each test case

    for (int i = 0; i < t; i++) {
        int k, x;
        cin >> k >> x; 
        // x is the final value after k iterations
        // k is the number of iterations performed

        // One simple possible initial value:
        // If we always reverse the "x / 2" operation (i.e., assume x was always even),
        // then the initial value can be obtained as x * 2^k
        int res = x * pow(2, k);
        ans[i] = res;
    }

    // Output the results
    for (int i : ans) cout << i << endl;

    return 0;
}

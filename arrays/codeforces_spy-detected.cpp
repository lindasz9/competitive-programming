#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin >> t;  // Read number of test cases
    vector<int> ans(t);  // Store answers for each test case

    for (int i = 0; i < t; i++) {
        int n, targ = 0;
        cin >> n;  // Read size of the array for this test case
        vector<int> v(n + 1);  // 1-indexed array

        for (int i = 1; i <= n; i++) cin >> v[i];  // Read array elements

        // Determine a target value (the majority or repeated element)
        if (v[1] == v[2]) 
            targ = v[1];  // First two elements are equal, set as target
        else if (v[1] == v[3]) 
            ans[i] = 2;  // First element matches third, second is different
        else 
            ans[i] = 1;  // Otherwise, first element is different

        if (targ) {  // If a target is set
            for (int j = 1; j <= n; j++) {
                if (v[j] != targ) {
                    ans[i] = j;  // Find the first element that differs from target
                    continue;
                }
            }
        } 
    }

    // Output the results for all test cases
    for (int i = 0; i < t; i++) cout << ans[i] << endl;

    return 0;
}

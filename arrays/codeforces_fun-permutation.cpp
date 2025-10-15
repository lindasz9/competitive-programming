#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); // Fast I/O

    int t;
    cin >> t;  // Number of test cases
    while (t--) {
        int n;
        cin >> n;  // Size of the permutation
        vector<int> res(n);  // Store the resulting permutation

        for (int i = 0; i < n; i++) {
            int p;
            cin >> p;  
            res[i] = n - p + 1;  // Transform each element to its "mirror" position
        }

        for (int i : res) cout << i << " ";  // Output the transformed permutation
        cout << endl;
    }
}

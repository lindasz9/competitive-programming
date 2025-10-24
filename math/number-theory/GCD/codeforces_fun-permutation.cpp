#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        int n;
        cin >> n; // Size of the permutation
        vector<int> res(n); // Will store the resulting permutation q

        for (int i = 0; i < n; i++) {
            int p;
            cin >> p; // Read the permutation p[i]
            res[i] = n - p + 1; 
            // Construct q[i] such that p[i] + q[i] = n + 1
            // This ensures that adjacent sums are >= 3
        }

        // Output the constructed permutation q
        for (int i : res) cout << i << " ";
        cout << endl;
    }
}

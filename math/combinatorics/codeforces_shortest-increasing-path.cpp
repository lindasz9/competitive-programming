#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        int x, y;
        cin >> x >> y; // Target coordinates

        // Analyze minimal steps based on given constraints:
        // 1. Steps alternate between x-axis and y-axis
        // 2. Step lengths strictly increase

        if (y == 1) {
            // Impossible: can't have increasing steps to reach y=1 (first step is along x)
            cout << -1 << endl;
        } else if (y > x) {
            // Case: y larger than x → can reach in 2 steps
            // First step along x, second step along y (larger than previous)
            cout << 2 << endl;
        } else if (x >= y + 2) {
            // Case: x sufficiently larger than y → can reach in 3 steps
            cout << 3 << endl;
        } else {
            // Other cases are impossible
            cout << -1 << endl;
        }
    }
}

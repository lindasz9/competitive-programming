#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        int n, t;
        cin >> n >> t; // n = number of audio requirements, t = total minutes
        bool other = false; // Tracks Farmer John's current side: false = side 0, true = side 1
        int cnt = 0; // Counts "unavoidable" time slots where he can't earn a point

        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b; // a = minute number, b = required side at minute a

            // Check if FJ's current parity of movements allows him to meet requirement
            // a % 2 determines whether he should be on starting side or opposite side naturally
            if (b == 0) {
                // Requirement: be on side 0 at minute a
                if ((a % 2 && !other) || (!(a % 2) && other)) {
                    cnt++; // He has to move differently to satisfy requirement, can't score a point
                    other = !other; // Flip current side to meet requirement
                }
            } else {
                // Requirement: be on side 1 at minute a
                if ((a % 2 && other) || (!(a % 2) && !other)) {
                    cnt++; // Forced adjustment, can't score a point here
                    other = !other; // Flip current side to meet requirement
                }
            }
        }

        // Maximum points = total minutes - number of forced adjustments
        cout << t - cnt << endl;
    }
}

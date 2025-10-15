#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); // Fast I/O

    int t;
    cin >> t;  // Number of test cases
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;  
        // a = number of horizontal lasers
        // b = number of vertical lasers
        // c, d = coordinates of the target point (not used here since only counts matter)

        // Read positions of horizontal lasers (not needed for calculation)
        for (int i = 0; i < a; ++i) {
            int _;
            cin >> _;
        }

        // Read positions of vertical lasers (not needed for calculation)
        for (int i = 0; i < b; ++i) {
            int _;
            cin >> _;
        }

        // Minimum number of laser crossings is the sum of horizontal and vertical lasers
        cout << (a + b) << endl;
    }
}

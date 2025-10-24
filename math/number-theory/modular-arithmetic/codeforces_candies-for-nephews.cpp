#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int n;
        cin >> n; // Number of candies Monocarp initially has

        // To distribute candies equally among 3 nephews,
        // the total number of candies must be divisible by 3.
        if (n % 3 == 0)
            cout << "0\n";           // Already divisible → no extra candies needed
        else
            cout << 3 - (n % 3) << endl; // Buy enough candies to reach the next multiple of 3
    }
}

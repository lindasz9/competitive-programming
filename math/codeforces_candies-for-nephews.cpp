#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int n;
        cin >> n; // Number of candies Monocarp initially has

        // Compute minimum additional candies needed
        // If n is divisible by 3, no additional candies are needed
        if (n % 3 == 0) 
            cout << "0\n";
        else 
            // Otherwise, buy enough to reach the next multiple of 3
            cout << 3 - (n % 3) << endl;
    }
}

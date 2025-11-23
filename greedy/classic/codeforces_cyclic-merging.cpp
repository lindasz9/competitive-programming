#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; 
	cin >> t; // number of test cases
    while (t--) {
        int n; 
        cin >> n; // size of the ring

        vector<pair<int, int>> a(n); // (value, index)
        vector<vector<int>> b(n, vector<int>(3)); // stores {value, left, right}

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x; 
            a[i] = {x, i}; // keep original index

            int y = i - 1, z = i + 1; // neighbors
            if (i == 0) y = n - 1;     // wrap left
            if (i == n - 1) z = 0;     // wrap right

            b[i] = {x, y, z}; // store node value + adjacency
        }

        sort(a.begin(), a.end()); // process nodes in ascending order of value

        long long cost = 0;

        for (int i = 0; i < n - 1; i++) {
            int id = a[i].second; // index of current smallest node

            // add min(neighbor left value, right neighbor value)
            cost += min(b[b[id][1]][0], b[b[id][2]][0]);

            // merge: patch neighbors to bypass this node
            b[b[id][1]][2] = b[id][2]; // left neighbor's right = right neighbor
            b[b[id][2]][1] = b[id][1]; // right neighbor's left = left neighbor
        }

        cout << cost << '\n'; // minimal total merging cost
    }
}

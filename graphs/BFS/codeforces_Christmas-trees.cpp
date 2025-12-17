#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
    cin >> n >> m; // number of trees and people

    unordered_set<int> vis; // occupied positions (trees + assigned people)
    queue<pair<int,int>> q; // BFS queue: (position, distance to nearest tree)

    // initialize BFS with all tree positions
    for (int i = 0; i < n; i++) {
        int a; 
        cin >> a;
        vis.insert(a);        // mark tree position as occupied
        q.push({a, 0});       // distance from tree to itself is 0
    }

    vector<int> y;           // positions chosen for people
    long long d = 0;         // total distance sum

    // multi-source BFS until m people are placed
    while ((int)y.size() < m) {
        auto [v, dd] = q.front(); 
        q.pop();

        // try adjacent integer positions
        for (int a : {v - 1, v + 1}) {
            if (!vis.count(a)) {       // if position is free
                vis.insert(a);         // mark as occupied
                y.push_back(a);        // place a person here
                q.push({a, dd + 1});   // push with increased distance
                d += (dd + 1);         // add distance to total sum
                if ((int)y.size() == m) break;
            }
        }
    }

    cout << d << '\n';       // minimum total distance
    for (int a : y) 
        cout << a << ' ';    // positions of people
    cout << '\n';
}

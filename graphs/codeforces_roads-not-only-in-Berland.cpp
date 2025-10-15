#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); // Fast input/output

    int n;
    cin >> n; // Number of cities
    vector<int> par(n + 1); // Union-find parent array
    vector<pii> toremove;   // List of redundant roads to remove

    // Initialize each city as its own parent
    for (int i = 1; i <= n; i++) par[i] = i;

    // Union-Find "find" function with path compression
    function<int(int)> find_set = [&](int x) {
        if (par[x] == x) return x;
        else return par[x] = find_set(par[x]);
    };

    // Read the existing roads and detect redundant ones
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        int rootA = find_set(a);
        int rootB = find_set(b);

        if (rootA != rootB) {
            // If cities are in different connected components, connect them
            par[rootB] = rootA;
        } else {
            // Otherwise, this road forms a cycle → mark it for removal
            toremove.push_back({a, b});
        }
    }

    // Collect all distinct connected components
    unordered_set<int> s;
    for (int i = 1; i <= n; i++) s.insert(find_set(par[i]));
    vector<int> v(s.begin(), s.end()); // Convert set to vector for indexing

    cout << toremove.size() << endl; // Number of days = number of redundant roads

    // For each redundant road, connect two different components to maintain connectivity
    for (int i = 1; i < s.size(); i++) {
        pii p = toremove[i - 1];
        // Remove road p.first-p.second and add new road v[0]-v[i] connecting components
        cout << p.first << " " << p.second << " " << v[0] << " " << v[i] << endl;
    }
}

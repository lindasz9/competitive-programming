#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; 
    cin >> t; // Number of test cases
    while (t--) {
        int n, m;
        cin >> n >> m; // Number of vertices and edges
        vector<vector<int>> adj(n + 1); // Adjacency list for directed edges
        vector<pair<int, int>> undirected; // List of undirected edges

        // Read edges
        for (int i = 0; i < m; i++) {
            int ti, x, y;
            cin >> ti >> x >> y;
            if (ti) {
                // Directed edge x -> y
                adj[x].push_back(y);
            } else {
                // Undirected edge, store for later
                undirected.push_back({x, y});
            }
        }

        vector<int> visited(n + 1, 0), order; // Visited array for DFS and topological order
        bool cycle = false;

        // DFS to check for cycles and build topological ordering
        function<bool(int)> dfs = [&](int i) -> bool {
            visited[i] = 1; // Visiting
            for (int j : adj[i]) {
                if (visited[j] == 1) return true; // Found a back edge → cycle
                if (!visited[j]) {
                    if (dfs(j)) return true;
                }
            }
            visited[i] = 2; // Visited
            order.push_back(i); // Append to topological order
            return false;
        };

        // Check all components
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                if (dfs(i)) {
                    cycle = true;
                    break;
                }
            }
        }

        if (cycle) {
            // Impossible to form a DAG
            cout << "NO\n";
            continue;
        }

        reverse(order.begin(), order.end()); // Reverse DFS finish order → topological order

        vector<pair<int, int>> res; // Store final directed edges
        for (int i = 1; i <= n; i++) {
            for (int j : adj[i]) res.push_back({i, j}); // Include original directed edges
        }

        // Map node to its position in topological order
        vector<int> pos(n + 1);
        for (int i = 0; i < n; i++) pos[order[i]] = i;

        // Direct undirected edges according to topological order
        for (auto& [x, y] : undirected) {
            if (pos[x] < pos[y]) res.push_back({x, y}); // x comes before y → x->y
            else res.push_back({y, x});                 // y comes before x → y->x
        }

        // Output final DAG
        cout << "YES\n";
        for (auto& [x, y] : res) cout << x << " " << y << endl;
    }
}

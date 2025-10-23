#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; // adjacency list for cities
vector<bool> vis; // visited array

// DFS to explore a connected component
void dfs(int v, int id) {
    vis[v] = true;
    for (int u : adj[v])
        if (!vis[u]) dfs(u, id);
}

int main() {
    int n, m;
    cin >> n >> m;
    adj.assign(n+1, vector<int>());
    // read undirected roads
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vis.assign(n+1, false);
    vector<int> ids; // store representative nodes of components
    // find all connected components
    for (int i = 1; i <= n; i++)
        if (!vis[i]) {
            dfs(i, i);
            ids.push_back(i);
        }

    // print minimum number of roads to connect components
    if (ids.size() == 0) cout << "0\n";
    else cout << ids.size()-1 << endl;

    // connect each component to the first one
    for (int i = 1; i < (int)ids.size(); i++)
        cout << ids[0] << " " << ids[i] << endl;
}

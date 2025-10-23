#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; // adjacency list of cities (roads)
vector<bool> vis; // visited array
vector<int> ord, compid; // DFS order and component id for each node

// DFS to explore connected component
void dfs(int v) {
    vis[v] = true;
    for (int u : adj[v])
        if (!vis[u]) dfs(u);
    ord.push_back(v);
}

// DFS to mark component id
void dfs2(int v, int id) {
    vis[v] = true;
    compid[v] = id;
    for (int u : adj[v])
        if (!vis[u]) dfs2(u, id);
}

int main() {
    int n, m;
    cin >> n >> m;
    adj.assign(n+1, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a); // undirected graph
    }

    vis.assign(n+1, false);
    // find DFS finishing order
    for (int i = 1; i <= n; i++)
        if (!vis[i]) dfs(i);
    reverse(ord.begin(), ord.end());

    vis.assign(n+1, false);
    compid.assign(n+1, -1);
    // assign component ids
    for (int v : ord)
        if (!vis[v]) {
            dfs2(v, v);
        }

    vector<bool> compids(n+1);
    vector<int> ids;
    // collect unique component representatives
    for (int i = 1; i <= n; i++)
        if (!compids[compid[i]]) {
            compids[compid[i]] = true;
            ids.push_back(compid[i]);
        }

    // if graph already connected
    if (ids.size() == 0) cout << "0\n";
    else {
        cout << ids.size()-1 << endl; // minimum roads = components - 1
        for (int i = 1; i < (int)ids.size(); i++)
            cout << ids[0] << " " << ids[i] << endl; // connect components
    }
}

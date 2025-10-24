#include <bits/stdc++.h>
using namespace std;

vector<int> vis;

// DFS to record finishing order or to collect a component
void dfs(int v, vector<vector<int>>& adj, vector<int>& ord) {
    vis[v] = true;
    for (int u : adj[v]) {
        if (!vis[u]) dfs(u, adj, ord);
    }
    ord.push_back(v);  // record vertex when all descendants are processed
}

int main() {
    int n, m;
    cin >> n >> m;
    vis.assign(n + 1, false);
    vector<vector<int>> adj(n + 1);

    // Read directed edges
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    // First DFS pass – compute finishing order
    vector<int> topo;
    for (int i = 1; i <= n; i++) 
        if (!vis[i]) dfs(i, adj, topo);
    reverse(topo.begin(), topo.end());  // reverse to get correct order

    // Build transposed graph (reverse all edges)
    vector<vector<int>> adj2(n + 1);
    for (int i = 1; i <= n; i++) 
        for (int j : adj[i]) adj2[j].push_back(i);
    
    // Second DFS pass on transposed graph to find SCCs
    vector<int> roots(n + 1);
    vis.assign(n + 1, false);
    int cnt = 0;
    for (int j : topo)
        if (!vis[j]) {
            cnt++;                  // found a new strongly connected component
            vector<int> comp;
            dfs(j, adj2, comp);     // collect all vertices in this component
            for (int v : comp) roots[v] = cnt;
        }

    // Output total number of components and their labels
    cout << cnt << endl;
    for (int i = 1; i <= n; i++) cout << roots[i] << " ";
    cout << endl;
}

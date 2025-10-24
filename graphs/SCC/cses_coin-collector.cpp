#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<bool> vis;
vector<vector<int>> adj, radj, comps;
vector<int> order;

// DFS to compute finishing order
void dfs(int v) {
    vis[v] = true;
    for (int u : adj[v])
        if (!vis[u]) dfs(u);
    order.push_back(v);
}

// DFS on the transposed graph to collect SCC
void dfs2(int v, vector<int>& comp) {
    vis[v] = true;
    comp.push_back(v);
    for (int u : radj[v])
        if (!vis[u]) dfs2(u, comp);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> coins(n + 1);
    for (int i = 1; i <= n; i++) cin >> coins[i];  // coins in each room

    adj.assign(n + 1, {});
    radj.assign(n + 1, {});
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;          // tunnel from a to b
        adj[a].push_back(b);
        radj[b].push_back(a);
    }

    // First DFS to get finishing order
    vis.assign(n + 1, false);
    for (int i = 1; i <= n; i++)
        if (!vis[i]) dfs(i);
    reverse(order.begin(), order.end());

    // Second DFS on transposed graph to find SCCs
    vis.assign(n + 1, false);
    vector<int> compid(n + 1);
    for (int v : order)
        if (!vis[v]) {
            vector<int> comp;
            dfs2(v, comp);
            for (int u : comp) compid[u] = comps.size();
            comps.push_back(comp);
        }

    int nc = comps.size();
    vector<ll> allcoins(nc);
    for (int i = 0; i < nc; i++)
        for (int v : comps[i]) allcoins[i] += coins[v];  // total coins per SCC

    // Build DAG of SCCs
    vector<vector<int>> adj2(nc);
    for (int v = 1; v <= n; v++)
        for (int u : adj[v])
            if (compid[v] != compid[u])
                adj2[compid[v]].push_back(compid[u]);

    // Remove duplicate edges (optional)
    for (auto& i : adj2) {
        sort(i.begin(), i.end());
        i.erase(unique(i.begin(), i.end()), i.end());
    }

    // Topological DP to find maximum coins collectable
    vector<ll> dp(nc);
    vector<int> indeg(nc);
    for (int i = 0; i < nc; i++)
        for (int v : adj2[i]) indeg[v]++;

    queue<int> q;
    ll ans = 0;
    for (int i = 0; i < nc; i++)
        if (!indeg[i]) {
            dp[i] = allcoins[i];
            q.push(i);
            ans = max(ans, dp[i]);
        }

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj2[v]) {
            dp[u] = max(dp[u], dp[v] + allcoins[u]);
            ans = max(ans, dp[u]);
            indeg[u]--;
            if (!indeg[u]) q.push(u);
        }
    }

    cout << ans << endl;  // maximum coins collectable
}

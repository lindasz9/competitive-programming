#include <bits/stdc++.h>
using namespace std;
 
vector<bool> vis;
int n, m;
vector<vector<int>> adj, adj2, radj2, adj3;
vector<int> ord, compid;
vector<vector<int>> edges;

// first DFS for order (Kosaraju step 1)
void dfs(int v) {
    vis[v] = true;
    for (int u : adj2[v]) if (!vis[u]) dfs(u);
    ord.push_back(v);
}

// second DFS to assign component IDs (Kosaraju step 2)
void dfs2(int v, int id) {
    vis[v] = true;
    compid[v] = id;
    for (int u : radj2[v]) if (!vis[u]) dfs2(u, id);
}

// check if all nodes can be reached from a single source after reversing edges <= x
bool check(int x) {
    adj2.assign(n+1, vector<int>());
    radj2.assign(n+1, vector<int>());
    
    // build modified graph: edges with weight ≤ x can be reversed
    for (int i = 1; i <= m; i++) {
        auto v = edges[i];
        adj2[v[0]].push_back(v[1]);
        radj2[v[1]].push_back(v[0]);
        if (v[2] <= x) { // reversible edge
            adj2[v[1]].push_back(v[0]);
            radj2[v[0]].push_back(v[1]);
        }
    }

    // Kosaraju's algorithm to find strongly connected components
    ord.clear();
    vis.assign(n+1, false);
    for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i);
    reverse(ord.begin(), ord.end());
    
    vis.assign(n+1, false);
    int id = 0;
    compid.assign(n+1, -1);
    for (int i = 0; i < n; i++) if (!vis[ord[i]]) {
        dfs2(ord[i], id);
        id++;
    }

    // build condensation graph and compute indegrees
    vector<int> indeg(id);
    for (int i = 1; i <= n; i++) 
        for (int u : adj2[i]) 
            if (compid[i] != compid[u]) indeg[compid[u]]++;

    // if only one SCC has indegree 0 → reachable from one node
    int cnt = 0;
    for (int i : indeg) if (i == 0) cnt++;
    return cnt == 1;
}

int main() {
	int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        edges.assign(m+1, vector<int>(3));
        adj.assign(n+1, vector<int>());
        vector<int> w(m+1);

        // read edges
        for (int i = 1; i <= m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].push_back(b);
            w[i] = c;
            edges[i][0] = a; edges[i][1] = b; edges[i][2] = c;
        }

        sort(w.begin(), w.end()); // sort weights for binary search

        int l = 0, r = m;
        int ans = -1;

        // binary search minimal cost
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(w[mid])) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }

        cout << (ans == -1 ? -1 : w[ans]) << endl; // print minimal possible cost
    }
}

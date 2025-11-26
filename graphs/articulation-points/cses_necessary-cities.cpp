#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
vector<int> adj[MAXN]; // adjacency list for cities

int timer = 1, tin[MAXN], l[MAXN]; // tin = discovery time, l = low-link value
vector<int> ans; // stores necessary cities (articulation points)

void dfs(int v, int p) {
    tin[v] = timer;
    l[v] = timer++; // set discovery and low-link time
    bool elvago = false; // flag for articulation point
    int cnt = 0; // count of children in DFS tree

    for (int u : adj[v]) {
        if (u == p) continue; // skip parent
        if (tin[u]) {
            l[v] = min(l[v], tin[u]); // update low-link using back edge
        } else {
            cnt++;
            dfs(u, v); // DFS on child
            l[v] = min(l[v], l[u]); // propagate low-link up
            if (p != -1 && l[u] >= tin[v]) elvago = true; // articulation point check
        }
    }

    if (p == -1 && cnt > 1) elvago = true; // root special case
    if (elvago) ans.push_back(v); // store necessary city
}

int main() {
	int n, m;
    cin >> n >> m; // number of cities and roads
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a); // add bidirectional edge
    }

    dfs(1, -1); // start DFS from city 1
    cout << ans.size() << '\n'; // number of necessary cities
    for (int x : ans) cout << x << ' '; // list of necessary cities
    cout << '\n';
}

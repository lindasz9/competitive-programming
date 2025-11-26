#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+1;
vector<int> adj[MAXN]; // adjacency list for cities

int tin[MAXN], l[MAXN], timer = 1; // discovery time and low-link values
vector<pair<int, int>> hidak; // stores necessary roads (bridges)

void dfs(int v, int par) {
    tin[v] = timer;
    l[v] = timer++; // set discovery and low-link time

    for (int u : adj[v]) {
        if (u == par) continue; // skip parent
        if (tin[u] > 0) 
            l[v] = min(l[v], l[u]); // update low-link via back edge
        else {
            dfs(u, v); // DFS on child
            l[v] = min(l[v], l[u]); // propagate low-link up
        }
    }

    // check if edge (v, par) is a bridge
    if (l[v] == tin[v] && par != -1) 
        hidak.push_back({v, par});
}

int main() {
	int n, m;
    cin >> n >> m; // number of cities and roads
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a); // add bidirectional road
    }

    dfs(1, -1); // start DFS from city 1

    cout << hidak.size() << '\n'; // number of necessary roads
    for (auto p : hidak) 
        cout << p.first << ' ' << p.second << '\n'; // list of necessary roads
}

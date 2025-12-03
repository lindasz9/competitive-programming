#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
vector<int> adj[MAXN]; // adjacency list

int timer = 1;
vector<int> tin(MAXN), l(MAXN); // discovery and low-link times
vector<pair<int, int>> edges;   // store directed edges
bool bridge = false;             // flag if any bridge exists

void dfs(int v, int p) {
	tin[v] = l[v] = timer++; // set discovery and low-link time

	for (int to : adj[v]) {
		if (to == p) continue; // skip parent
		if (tin[to]) {
			l[v] = min(l[v], tin[to]); // back edge
			if (tin[to] < tin[v])
				edges.push_back({v, to}); // orient back edge
		} else {
			dfs(to, v);               // DFS on child
			l[v] = min(l[v], l[to]);  // update low-link
			edges.push_back({v, to}); // orient tree edge
		}
	}

	// detect bridge
	if (tin[v] == l[v] && p != -1) bridge = true;
}

int main() {
	int n, m;
	cin >> n >> m; // nodes and edges

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a); // undirected graph
	}

	dfs(1, -1); // start DFS from node 1

	// if any node unvisited or bridge exists, impossible
	for (int i = 1; i <= n; i++)
		if (tin[i] == 0 || bridge) {
			cout << "IMPOSSIBLE\n"; 
            return 0;
		}

	// output directed edges
	for (auto p : edges) 
        cout << p.first << ' ' << p.second << '\n';
}

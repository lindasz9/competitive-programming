#include <bits/stdc++.h>
using namespace std;
 
vector<bool> vis;
int sid = -1; // id of the component containing the capital
int s; // capital city index
 
// first DFS to get topological order
void dfs(vector<vector<int>>& adj, int v, vector<int>& ord) {
	vis[v] = true;
	for (int u : adj[v]) {
		if (!vis[u]) dfs(adj, u, ord);
	}
	ord.push_back(v); // push after visiting children
}
 
// second DFS on reversed graph to assign components
void dfs2(vector<vector<int>>& adj, int v, vector<int>& comp, int id) {
	vis[v] = true;
	comp[v] = id; // assign component id
	if (v == s) sid = id; // store component id of capital
	for (int u : adj[v]) {
		if (!vis[u]) dfs2(adj, u, comp, id);
	}
}
 
int main() {
	int n, m;
	cin >> n >> m >> s;
	vector<vector<int>> adj(n+1), adj2(n+1); // adjacency lists for original and reversed graphs
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj2[v].push_back(u); // reversed edge
	}
	
	vis.assign(n+1, false);
	vector<int> ord;
	// first pass DFS for finishing order
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) dfs(adj, i, ord);
	}
	reverse(ord.begin(), ord.end()); // reverse to get topological order
	
	// second pass DFS to identify strongly connected components
	vis.assign(n+1, false);
	vector<int> comp(n+1, -1);
	int id = 0;
	for (int u : ord) {
		if (!vis[u]) {
			dfs2(adj2, u, comp, id);
			id++;
		}
	}
	
	// build condensed graph of components
	vector<vector<int>> adj3(id);
	vector<int> indeg(id); // indegree of each SCC
	for (int i = 1; i <= n; i++) {
		for (int u : adj[i]) {
			if (comp[i] != comp[u]) {
				adj3[comp[i]].push_back(comp[u]);
				indeg[comp[u]]++;
			}
		}
	}
	
	// count number of SCCs with indegree 0 excluding the capital's component
	int ans = 0;
	for (int i = 0; i < id; i++)
		if (indeg[i] == 0 && i != sid) ans++;
		
	cout << ans << endl; // minimum new roads required
}

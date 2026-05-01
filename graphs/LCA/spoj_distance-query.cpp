#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

const int maxn = 100001;
const int l = 25; // enough for up to ~100k nodes (2^25 > 1e7)

vector<pii> adj[maxn]; // adjacency list: (neighbor, edge weight)

int up[maxn][l]; // up[v][i] = 2^i-th ancestor of v
int mx[maxn][l]; // maximum edge weight on path to 2^i ancestor
int mn[maxn][l]; // minimum edge weight on path to 2^i ancestor

int d[maxn];     // depth of each node
int vis[maxn];   // visited array

// helper: min handling 0 (0 means "no value yet")
int min2(int a, int b){
    if(a == 0 || b == 0) return a == 0 ? b : a;
    return min(a, b);
}

// helper: max handling 0
int max2(int a, int b){
    if(a == 0 || b == 0) return a == 0 ? b : a;
    return max(a, b);
}

// DFS to compute depth and binary lifting tables
void dfs(int v, int p, int w, int dist){
    d[v] = dist;
    vis[v] = true;

    up[v][0] = p;   // direct parent
    mx[v][0] = w;   // edge weight to parent
    mn[v][0] = w;

    // build binary lifting tables
    for(int i = 1; i < l; i++){
        int mid = up[v][i - 1];

        up[v][i] = up[mid][i - 1];

        mx[v][i] = max2(mx[mid][i - 1], mx[v][i - 1]);
        mn[v][i] = min2(mn[mid][i - 1], mn[v][i - 1]);
    }

    // traverse children
    for(auto [u, w2] : adj[v]){
        if(!vis[u]) dfs(u, v, w2, dist + 1);
    }
}

// LCA query + min/max edge values on path
void lca(int v, int u){
    int minEdge = 0, maxEdge = 0;

    // ensure v is deeper
    if(d[v] < d[u]) swap(v, u);

    int diff = d[v] - d[u];

    // lift v up to depth of u
    for(int i = l - 1; i >= 0; i--){
        if((1 << i) & diff){
            minEdge = min2(minEdge, mn[v][i]);
            maxEdge = max2(maxEdge, mx[v][i]);
            v = up[v][i];
        }
    }

    // already same node
    if(v == u){
        cout << minEdge << ' ' << maxEdge << '\n';
        return;
    }

    // lift both nodes together
    for(int i = l - 1; i >= 0; i--){
        if(up[v][i] != up[u][i]){
            minEdge = min2(minEdge, min2(mn[v][i], mn[u][i]));
            maxEdge = max2(maxEdge, max2(mx[v][i], mx[u][i]));

            v = up[v][i];
            u = up[u][i];
        }
    }

    // final step to LCA
    minEdge = min2(minEdge, min2(mn[v][0], mn[u][0]));
    maxEdge = max2(maxEdge, max2(mx[v][0], mx[u][0]));

    cout << minEdge << ' ' << maxEdge << '\n';
}

int main(){
    int n;
    cin >> n;

    // read tree edges
    for(int i = 1; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    // preprocess from root = 1
    dfs(1, -1, 0, 0);

    int q;
    cin >> q;

    while(q--){
        int a, b;
        cin >> a >> b;
        lca(a, b);
    }
}

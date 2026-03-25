#include <bits/stdc++.h>
using namespace std;

const int maxn = 100001;

// adjacency list of directed flights
vector<int> adj[maxn];

// visited array for topological sort
bool vis[maxn];

// whether the position is losing for the current player
bool islose[maxn];

// DFS for topological sorting
void dfs(int v, vector<int>& ord){
    vis[v] = true;
    for(int u : adj[v])
        if(!vis[u])
            dfs(u, ord);
    ord.push_back(v); // add after visiting all neighbors
}

int main(){
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> s(q);
    for(int i = 0; i < q; i++) cin >> s[i];

    // build the directed graph of flights
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    // topological order of cities
    vector<int> ord;
    for(int i = 1; i <= n; i++)
        if(!vis[i])
            dfs(i, ord);

    // process cities in topological order (reverse for DP)
    for(int x : ord){
        bool lose = true;
        // if there is any neighbor which is losing, current city is winning
        for(int i : adj[x]){
            if(islose[i]) lose = false;
        }
        islose[x] = lose;
    }

    // answer queries
    for(int x : s){
        if(islose[x]) cout << "B\n"; // first player loses => B wins
        else cout << "A\n";          // first player wins => A wins
    }
}

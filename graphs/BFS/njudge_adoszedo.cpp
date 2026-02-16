#include <bits/stdc++.h>
using namespace std;
using pii=pair<int, int>;

int main() {
    int n,m,f;
    cin>>n>>m>>f; // városok, útszakaszok, főváros
    vector<vector<pii>> adj(n+1);
    for(int i=0;i<m;i++) {
        int a,b; cin>>a>>b;
        adj[a].push_back({b,i});
        adj[b].push_back({a,i});
    }

    queue<pii> q;
    q.push({f,0});
    set<pii> ans;
    vector<int> d(n+1,-1), vis(m);
    d[f]=0;

    while(!q.empty()) {
        auto [v,dis]=q.front(); q.pop();
        for(auto [to,i]:adj[v]) {
            if(vis[i]) continue;
            if(d[to]==-1 || d[to]==dis+1){
                d[to]=dis+1;
                q.push({to,dis+1});
                if(v<to) ans.insert({v,to});
                else ans.insert({to,v});
                vis[i]=true;
            }
        }
    }

    cout<<ans.size()<<'\n';
    for(auto [a,b]:ans) cout<<a<<' '<<b<<'\n';
}

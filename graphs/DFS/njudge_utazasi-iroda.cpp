#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int maxn=1e5+1;
vector<int> adj[maxn]; // fa élei
int cnt,p[maxn],last; // cnt: hátralévő sétahajózások, p: szülő, last: utolsó csomópont a DFS-ben
vector<int> ans; // eredmény útvonal

// DFS, ami leáll, ha elérjük a k-adik sétahajózást
void dfs(int v, int par) {
    cnt--; // csökkentjük a hátralévőket
    last=v; // utolsó meglátogatott csomópont
    if(cnt==0) return; // ha elértük a k-adikat, megállunk
    for(int to:adj[v]) {
        if(cnt==0) return; // korai kilépés
        if(to==par) continue; // vissza az előző csomópontra tilos
        p[to]=v; // szülő beállítása
        dfs(to,v);
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    ll n,k; cin>>n>>k; // csillagrendszerek száma, K. sétahajózás
    for(int i=1;i<n;i++) {
        int a,b; cin>>a>>b;
        adj[a].push_back(b); // fa élei
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++) sort(adj[i].begin(),adj[i].end()); // lexikografikus sorrendhez rendezés

    int root=(k-1)/n+1; // kiinduló csomópont a DFS-hez
    cnt=k%n;
    if(!cnt) cnt=n; // ha többszörös, az utolsót kell venni
    dfs(root,-1); // DFS hívás
    while(last){ // visszakövetjük az utat a gyökértől a célig
        ans.push_back(last);
        last=p[last];
    }
    reverse(ans.begin(),ans.end());
    for(int x:ans) cout<<x<<' '; // útvonal kiírása
    cout<<'\n';
}

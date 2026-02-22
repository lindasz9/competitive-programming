#include <bits/stdc++.h>
using namespace std;

const int maxn=20001;
vector<int> adj[maxn]; // szomszédsági lista

int tin[maxn], low[maxn], par[maxn], timer=1;
vector<int> ans;
int dest, sep;

// DFS a belépési idők és low-link értékek kiszámítására
void dfs(int v,int p){
    par[v]=p;                 // szülő eltárolása a DFS-fában
    tin[v]=low[v]=timer++;    // belépési idő és low inicializálása

    for(int to:adj[v]){
        if(to==p) continue;   // a szülő él kihagyása

        if(tin[to]){          // visszaél
            low[v]=min(low[v],tin[to]);
        } else {              // faél
            dfs(to,v);
            low[v]=min(low[v],low[to]);

            // ha a 'to' részfából vissza lehet jutni v fölé,
            // akkor módosítjuk a lehetséges szeparáló csúcsot
            if(to==sep && low[to]<tin[v]) sep=v;
        }
    }
}

// A DFS-fában a sep csúcs részfájának bejárása
void dfs2(int v){
    ans.push_back(v);         // lehetséges tartózkodási város
    for(int to:adj[v]){
        if(par[to]==v){       // csak a DFS-fa élén haladunk tovább
            dfs2(to);
        }
    }
}

int main(){
    int n,m,u; 
    cin>>n>>m>>u>>dest; // városok száma, utak száma, induló U és ismert V

    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);  // kétirányú út
    }

    sep=dest;     // kezdetben V város a vizsgált szeparáló csúcs
    dfs(u,-1);    // DFS U-ból
    dfs2(sep);    // a sep részfájának csúcsai a lehetséges válaszok

    cout<<ans.size()<<'\n';
    for(int x:ans) cout<<x<<' ';
    cout<<'\n';
}

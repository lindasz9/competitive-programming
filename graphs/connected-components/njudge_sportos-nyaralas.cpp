#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

const int maxn=50001;
int n,m,k;

// Mélységi keresés, hogy egy komponens összes csúcsát bejárjuk
void dfs(int v,int c,vector<int>& vis,vector<int>& comp,vector<vector<int>>& adj){
    comp[v]=c;      // hozzárendeljük a komponens azonosítót
    vis[v]=1;       // megjelöljük, hogy már bejártuk
    for(int i:adj[v]) if(!vis[i]) dfs(i,c,vis,comp,adj); // bejárjuk a szomszédokat
}

int main(){
    cin>>n>>m>>k;
    vector<vector<int>> adj1(n+1); // szomszédsági lista bicikliutakhoz
    vector<vector<int>> adj2(n+1); // szomszédsági lista vízi útvonalakhoz

    // bicikliutak beolvasása
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        adj1[a].push_back(b);
        adj1[b].push_back(a);
    }

    // vízi útvonalak beolvasása
    for(int i=0;i<k;i++){
        int a,b; cin>>a>>b;
        adj2[a].push_back(b);
        adj2[b].push_back(a);
    }

    int c=0;
    vector<int> vis1(n+1);     // bejárt jelzés bicikli DFS-hez
    vector<int> comp1(n+1);    // komponens azonosítók bicikliutakhoz
    for(int i=1;i<=n;i++){
        if(!vis1[i]){
            dfs(i,c++,vis1,comp1,adj1); // összes biciklis komponens megtalálása
        }
    }

    c=0;
    vector<int> vis2(n+1);     // bejárt jelzés vízi DFS-hez
    vector<int> comp2(n+1);    // komponens azonosítók vízi útvonalakhoz
    for(int i=1;i<=n;i++){
        if(!vis2[i]){
            dfs(i,c++,vis2,comp2,adj2); // összes vízi komponens megtalálása
        }
    }

    map<pii,vector<int>> hm; // (bicikliKomponens, víziKomponens) -> csúcsok listája
    for(int i=1;i<=n;i++){
        hm[{comp1[i],comp2[i]}].push_back(i);
    }

    vector<int> ans(n+1); // válasz

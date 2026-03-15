#include <bits/stdc++.h>
using namespace std;
#define pb push_back

const int maxn = 20005;

vector<int> adj[maxn], radj[maxn];
int comp[maxn];
bool vis[maxn];

void add(int x,int y){
    // implikációs gráf él: x -> y
    adj[x].pb(y);
    radj[y].pb(x);
}

void dfs1(int v, vector<int>& ord){
    // első DFS: topologikus sorrend gyűjtése
    vis[v] = true;
    for(int u:adj[v])
        if(!vis[u]) dfs1(u,ord);
    ord.pb(v);
}

void dfs2(int v,int id){
    // második DFS: komponensek azonosítása a transzponált gráfban
    vis[v] = true;
    comp[v] = id;
    for(int u:radj[v])
        if(!vis[u]) dfs2(u,id);
}

int main(){
    int t; 
    cin >> t;

    while(t--){
        int n,m;
        cin >> n >> m;

        int nn = 2*n + 2;

        // gráf inicializálása
        for(int i=1;i<nn;i++){
            adj[i].clear();
            radj[i].clear();
            vis[i] = false;
        }

        for(int i=0;i<m;i++){
            int a,b,c;
            bool d=1,e=1,f=1;
            char dd,ee,ff;

            cin >> a >> dd >> b >> ee >> c >> ff;

            // H → 0, T → 1 kódolás
            if(dd=='H') d=0;
            if(ee=='H') e=0;
            if(ff=='H') f=0;

            // (A ∨ B)
            add((2*a+d)^1, 2*b+e);
            add((2*b+e)^1, 2*a+d);

            // (A ∨ C)
            add((2*a+d)^1, 2*c+f);
            add((2*c+f)^1, 2*a+d);

            // (B ∨ C)
            add((2*b+e)^1, 2*c+f);
            add((2*c+f)^1, 2*b+e);
        }

        vector<int> ord;

        // első DFS minden csúcsra
        for(int i=1;i<nn;i++)
            if(!vis[i]) dfs1(i,ord);

        // látogatottság törlése
        for(int i=1;i<nn;i++) vis[i] = false;

        int id = 1;

        // második DFS a fordított sorrendben
        for(int i=nn-2;i>=0;i--){
            if(!vis[ord[i]]) dfs2(ord[i],id++);
        }

        vector<char> ans(n+1);
        bool ok = true;

        for(int i=1;i<=n;i++){
            // ha egy változó és a negáltja ugyanabban az SCC-ben van → lehetetlen
            if(comp[2*i] == comp[2*i+1]){
                cout << "-1\n";
                ok = false;
                break;
            }
            // topologikus sorrend alapján értékadás
            else if(comp[2*i] < comp[2*i+1]) ans[i] = 'T';
            else ans[i] = 'H';
        }

        if(ok){
            for(int i=1;i<=n;i++) cout << ans[i] << ' ';
            cout << '\n';
        }
    }
}

#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
#define pb push_back

const int maxn=20001;
vector<int> radj[maxn]; // fordított élek listája (u -> v helyett v -> u)
int adj[maxn],cnt;      // adj[i]: hova megy közvetlenül az i. város
bool vis[maxn];         // jelzi, hogy egy várost már elszállítottunk-e

// DFS a központi raktárból (1), távolságok kiszámítására
void dfs(int v,int dis,vector<pii>& d){
    d[v]={dis,v};       // eltároljuk a távolságot és a csúcsot
    for(int u:radj[v]) dfs(u,dis+1,d); // bejárjuk a fordított irányú gyerekeket
}

// Egy kiválasztott induló várostól végigmegyünk a raktárig
// és minden érintett várost megjelölünk
void up(int v){
    vis[v]=true;  // város elszállítva
    cnt++;        // számláló növelése
    if(!vis[adj[v]]) up(adj[v]); // továbbmegyünk a következő városba
}

int main(){
    int n,k; cin>>n>>k; // városok száma, kamionok száma
    for(int i=1;i<=n;i++){
        cin>>adj[i];
        radj[adj[i]].pb(i); // fordított él felépítése
    }

    vector<pii> d(n+1),c(n+1);
    dfs(1,0,d);        // távolságok meghatározása a raktártól
    sort(d.begin(),d.end()); // növekvő távolság szerint rendezés

    vis[1]=true;       // a raktár már "feldolgozott"

    // legtávolabbi csúcsoktól indulva választunk
    for(int i=n;i>0;i--){
        if(!vis[d[i].second]){
            cnt=0;
            up(d[i].second);           // út bejárása a raktárig
            c[i]={cnt,d[i].second};    // hány új várost fed le
        }
    }

    sort(c.begin(),c.end()); // lefedett városok száma szerint rendezés

    vector<int> ans;
    int total=0;

    // kiválasztjuk a K legjobb induló várost
    for(int i=n;i>n-k;i--){
        ans.pb(c[i].second);
        total+=c[i].first;
    }

    cout<<total<<'\n';   // maximálisan elszállítható városok száma
    for(int x:ans) cout<<x<<' ';
    cout<<'\n';
}

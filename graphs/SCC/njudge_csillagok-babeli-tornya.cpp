#include <bits/stdc++.h>
using namespace std;
#define pb push_back

const int maxn = 2e6+5;

// adj: irányított gráf szomszédsági listája
// radj: a gráf fordított irányú éleinek listája
vector<int> adj[maxn], radj[maxn];

int n, m;           // szereplők és nyelvek száma
int vis[maxn];      // DFS látogatottság
int comp[maxn];     // komponens azonosító minden csúcsra
int cnt;            // szereplők száma egy komponensben

// első DFS a Kosaraju algoritmushoz
// cél: csúcsok sorrendjének meghatározása
void dfs1(int v, vector<int>& ord) {
    vis[v] = 1;
    for (int u : adj[v]) if (!vis[u]) dfs1(u, ord);
    ord.pb(v); // befejezés után csúcs hozzáadása a sorrendhez
}

// második DFS: komponensek meghatározása
void dfs2(int v, int id) {
    comp[v] = id;          // komponens beállítása
    if (v > m) cnt++;      // ha csúcs szereplő, növeljük a számlálót
    for (int u : radj[v]) if (!comp[u]) dfs2(u, id);
}

int main() {
    cin >> n >> m;

    // szereplők és a beszélt nyelvük összekapcsolása
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        adj[i+m].pb(x);      // szereplő -> beszélt nyelv
        adj[x].pb(i+m);      // beszélt nyelv -> szereplő
        radj[i+m].pb(x);     // fordított él
        radj[x].pb(i+m);
    }

    // szereplők által megértett további nyelvek összekapcsolása
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int x; cin >> x;
            adj[x].pb(i+m);      // nyelv -> szereplő
            radj[i+m].pb(x);     // fordított él
        }
    }

    vector<int> ord;

    // első DFS az összes csúcsra
    for (int i = 1; i <= n+m; i++) if (!vis[i]) dfs1(i, ord);

    int id = 1, maxi = 0, compid;

    // második DFS a fordított gráfra, komponensek megtalálása
    for (int i = n+m-1; i >= 0; i--) if (!comp[ord[i]]) {
        cnt = 0;
        dfs2(ord[i], id++);
        if (cnt > maxi) {
            maxi = cnt;       // legnagyobb kommunikáló részhalmaz
            compid = id-1;    // komponens azonosítója
        }
    }

    // kiírjuk a maximális részhalmaz méretét
    cout << maxi << '\n';

    // kiírjuk a részhalmaz szereplőit
    for (int i = m+1; i <= n+m; i++) if (comp[i] == compid) cout << i-m << ' ';
    cout << '\n';
}

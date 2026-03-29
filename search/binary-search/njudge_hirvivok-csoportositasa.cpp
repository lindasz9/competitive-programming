#include <bits/stdc++.h>
using namespace std;

const int maxh = 1001;

int X[maxh], Y[maxh];   // hírvivők koordinátái
bool vis[maxh];         // bejárt csúcsok jelölése
vector<int> adj[maxh];  // gráf szomszédsági lista

int n, m, h, k;

// DFS: egy komponens bejárása
void dfs(int v){
    vis[v] = true;
    for(int u : adj[v])
        if(!vis[u])
            dfs(u);
}

// eldönti, hogy adott L = mid esetén ≤ k komponens van-e
bool solve(int mid){
    // gráf újraépítése
    for(int i = 0; i < h; i++) adj[i].clear();

    // minden hírvivőpár között él, ha Manhattan-távolság ≤ mid
    for(int i = 0; i < h - 1; i++){
        for(int j = i + 1; j < h; j++){
            if(abs(X[i] - X[j]) + abs(Y[i] - Y[j]) <= mid){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    // komponensek számolása DFS-sel
    for(int i = 0; i < h; i++) vis[i] = false;

    int cnt = 0;
    for(int i = 0; i < h; i++){
        if(!vis[i]){
            dfs(i);
            cnt++; // új komponens
        }
    }

    return cnt <= k; // megfelel-e a feltételnek
}

int main(){
    cin >> n >> m >> h >> k;

    // hírvivők beolvasása
    for(int i = 0; i < h; i++) cin >> X[i] >> Y[i];

    // bináris keresés az L értékre
    int l = 0, r = n * m; // felső korlát nagy, de biztos jó
    while(r > l){
        int mid = (l + r) / 2;
        if(solve(mid)) r = mid;   // ha jó, próbáljuk kisebb L-lel
        else l = mid + 1;         // ha nem jó, növelni kell
    }

    cout << r << '\n'; // minimális L
}

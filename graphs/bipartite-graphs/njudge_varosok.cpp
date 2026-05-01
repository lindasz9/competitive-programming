#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 5e4 + 5;

vector<int> adj[maxn]; // bipartit gráf: x koordináták → y koordináták
int mt[maxn];          // mt[y] = melyik x van hozzárendelve y-hoz
int vis[maxn];

bool kuhn(int v){
    // ha már jártunk itt ebben a keresésben, nem próbáljuk újra
    if(vis[v]) return false;
    vis[v] = 1;

    // megpróbáljuk párosítani v-t egy y csúccsal
    for(int u : adj[v]){
        // ha u nincs párosítva, vagy át tudjuk rendezni a párosítást
        if(mt[u] == -1 || kuhn(mt[u])){
            mt[u] = v;
            return true;
        }
    }
    return false;
}

signed main(){
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> X(n), Y(n);

    unordered_set<int> sx, sy;

    // koordináták beolvasása + egyedi értékek gyűjtése
    for(int i = 0; i < n; i++){
        cin >> X[i] >> Y[i];
        sx.insert(X[i]);
        sy.insert(Y[i]);
    }

    // koordináta-kompresszió (x-ek)
    unordered_map<int,int> mpx;
    int xc = 0;
    for(int x : sx)
        mpx[x] = xc++;

    // koordináta-kompresszió (y-ok)
    unordered_map<int,int> mpy;
    int yc = 0;
    for(int y : sy)
        mpy[y] = yc++;

    // átalakítás indexekre
    for(int i = 0; i < n; i++){
        X[i] = mpx[X[i]];
        Y[i] = mpy[Y[i]];
    }

    // bipartit gráf építése (x → y)
    for(int i = 0; i < n; i++)
        adj[X[i]].push_back(Y[i]);

    // kezdetben minden y nincs párosítva
    for(int i = 0; i < yc; i++)
        mt[i] = -1;

    // Kuhn algoritmus (maximális párosítás)
    for(int i = 0; i < xc; i++){
        for(int j = 0; j < xc; j++)
            vis[j] = 0;

        kuhn(i);
    }

    // hány y van párosítva
    int match = 0;
    for(int i = 0; i < yc; i++)
        if(mt[i] != -1)
            match++;

    // költség:
    // minden külön x és y kell (xc + yc)
    // minden párosítás csökkenti a szükséges kezdővárosok számát
    cout << (xc + yc) * b + (xc + yc - match) * a;
}

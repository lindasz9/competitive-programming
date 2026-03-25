#include <bits/stdc++.h>
using namespace std;

const int maxn = 100001;

// irányított repülőjáratok listája
vector<int> adj[maxn];

// topologikus rendezéshez látogatottság jelzőtömb
bool vis[maxn];

// jelzi, hogy az adott városból indulva a kezdő játékos veszít-e
bool islose[maxn];

// DFS a topologikus sorrendhez
void dfs(int v, vector<int>& ord){
    vis[v] = true;
    for(int u : adj[v])
        if(!vis[u])
            dfs(u, ord);
    ord.push_back(v); // a szomszédok feldolgozása után adjuk a várost
}

int main(){
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> s(q); // lekérdezések kezdővárosai
    for(int i = 0; i < q; i++) cin >> s[i];

    // gráf felépítése: irányított repülőjáratok
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    // topologikus sorrend előállítása
    vector<int> ord;
    for(int i = 1; i <= n; i++)
        if(!vis[i])
            dfs(i, ord);

    // városok feldolgozása topologikus sorrendben (DP)
    for(int x : ord){
        bool lose = true;
        // ha bármelyik szomszéd veszít, a jelenlegi város nyerő
        for(int i : adj[x]){
            if(islose[i]) lose = false;
        }
        islose[x] = lose; // aktuális város vesztes vagy nyerő
    }

    // lekérdezések kiértékelése
    for(int x : s){
        if(islose[x]) cout << "B\n"; // kezdő játékos veszít => B nyer
        else cout << "A\n";          // kezdő játékos nyer => A nyer
    }
}

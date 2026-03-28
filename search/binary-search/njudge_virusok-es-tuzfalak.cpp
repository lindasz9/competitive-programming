#include <bits/stdc++.h>
using namespace std;

const int maxn = 100001;

vector<int> adj[maxn]; // fa: gyerekek listája
int k, cnt;            // k = tűzfalak száma, cnt = szükséges vágások száma

// DFS: kiszámolja az adott részfa méretét,
// és ha meghaladja az m-et, akkor "levágjuk" (tűzfalat teszünk)
int dfs(int v, int m){
    int sum = 1; // aktuális csúcs beleszámít

    // gyerekek feldolgozása
    for(int u : adj[v]){
        sum += dfs(u, m);
    }

    // ha a részfa túl nagy, akkor itt vágunk
    if(sum > m){
        cnt++;      // egy új tűzfal szükséges
        return 0;   // levágjuk, így nem adódik feljebb
    }

    return sum; // különben visszaadjuk a részfa méretét
}

// eldönti, hogy m maximális fertőzött mérettel megoldható-e
bool solve(int m){
    cnt = 0;
    dfs(1, m);        // gyökértől indulunk
    return cnt <= k;  // belefér-e k tűzfalba
}

int main(){
    int n;
    cin >> n >> k;

    // fa beolvasása (szülő → gyerek él)
    for(int i = 2; i <= n; i++){
        int x;
        cin >> x;
        adj[x].push_back(i);
    }

    // bináris keresés az optimális válaszra
    int l = 0, r = n;
    while(r > l){
        int m = (l + r) / 2;
        if(solve(m)) r = m;   // megoldható, próbálunk kisebbet
        else l = m + 1;       // nem megoldható, növelni kell
    }

    cout << r << '\n'; // minimális lehetséges veszélyeztetettség
}

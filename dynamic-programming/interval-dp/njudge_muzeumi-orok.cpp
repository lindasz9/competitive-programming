#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, e, u;
    cin >> n >> e >> u;

    // a[l]: azok az intervallumok, amelyek l napon kezdődnek
    // {jobb vég, ár, azonosító}
    vector<vector<array<int,3>>> a(u+1);

    for(int i = 1; i <= n; i++){
        int x, y, z;
        cin >> x >> y >> z;
        a[x].push_back({y, z, i});
    }

    // dp[r]: minimum költség, hogy lefedjük [e, r]-t
    vector<int> dp(u+1, -1);

    // p[i]: visszakövetéshez, melyik őr után jött az i-edik
    vector<int> p(n+1);

    dp[e-1] = 0; // kezdőállapot: még semmit nem fedtünk le

    // s: aktív állapotok (költség, jobb vég, utolsó őr indexe)
    set<array<int,3>> s;
    s.insert({0, e-1, -1});

    int last; // utolsó kiválasztott őr az optimális megoldásban

    for(int l = e; l <= u; l++){
        int best = -1, bestid = -1;

        // eltávolítjuk azokat az állapotokat, amelyek már nem fedik az l-1 napot és kiválasztjuk a minimális dp értéket l-r napok között
        while(!s.empty()){
            auto [cost, rr, id] = *s.begin();
            if(rr < l-1) s.erase(s.begin());
            else{
                best = cost;
                bestid = id;
                break;
            }
        }

        // ha nincs olyan intervallum, ami lefedi az előző napot, nem folytatható
        if(best == -1) continue;

        // minden intervallum, ami l-nél kezdődik
        for(auto [r, w, id] : a[l]){
            // ha jobb megoldást találunk r-re
            if(dp[r] == -1 || best + w < dp[r]){
                dp[r] = best + w;   // frissítjük a költséget
                p[id] = bestid;     // eltároljuk az előző őrt
                s.insert({dp[r], r, id}); // új állapot beszúrása

                if(r == u) last = id; // ha elértük a végét
            }
        }
    }

    // ha nem lehet lefedni az egész intervallumot
    if(dp[u] == -1) cout << "-1\n";
    else{
        vector<int> ans;

        // visszakövetjük a kiválasztott őröket
        for(int x = last; x > 0; x = p[x]) ans.push_back(x);

        sort(ans.begin(), ans.end()); // növekvő sorrend

        cout << dp[u] << '\n' << ans.size() << ' ';

        for(int x : ans) cout << x << ' ';
        cout << '\n';
    }
}

#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

int main(){
    int n,m,k;
    cin>>n>>m>>k;

    vector<int> nn(n+1), mm(m+1);          // az első és második sor értékei (1-től indexelve)
    vector<vector<pii>> kk(n+1);           // minden első sorbeli kezdőpozícióhoz a játszmák listája (második sor index + játszma sorszám)

    for(int i=1;i<=n;i++) cin>>nn[i];      // első sor feltöltése
    for(int i=1;i<=m;i++) cin>>mm[i];      // második sor feltöltése

    for(int i=0;i<k;i++){
        int a,b; cin>>a>>b;
        kk[a].push_back({b,i});             // játszma indexek az első sor indexe alapján csoportosítva
    }

    vector<int> ans(k);                     // eredmények a K játszmára
    vector<int> d1(m+2), d2(m+2), s(m+2);  // d1,d2: DP sorok; s: prefix összegek

    // előkészítés: d1[i] = maximális pont ha csak mm[i..M] marad
    for(int i=m;i>0;i--) d1[i] = mm[i] - d1[i+1];
    for(int i=m;i>0;i--) s[i] = s[i+1] + mm[i];  // prefix összeg a gyors lekéréshez

    for(int i=n;i>0;i--){                     // visszafelé iterálunk az első sor elemein
        d2[m+1] = nn[i] - d1[m+1];            // DP alapérték: ha csak nn[i] marad
        s[m+1] += nn[i];                       // prefix összeg frissítése
        for(int j=m;j>0;j--){                  // végig a második sor elemein
            d2[j] = max({
                nn[i]-d1[j],                   // csak az első sorból veszünk
                mm[j]-d2[j+1],                 // csak a második sorból veszünk
                nn[i]+mm[j]-d1[j+1]            // mindkettőt vesszük
            });
            s[j] += nn[i];                      // frissítjük prefix összeget
        }
        for(auto [a,b]:kk[i]){                 // lekérdezések feldolgozása az i-edik első sor indexhez
            ans[b] = (s[a]+d2[a])/2;           // optimális pontszám Áronnak
        }
        swap(d1,d2);                            // DP sorok frissítése a következő iterációhoz
    }

    for(int x:ans) cout<<x<<'\n';              // kiírjuk az összes játszma eredményét
}

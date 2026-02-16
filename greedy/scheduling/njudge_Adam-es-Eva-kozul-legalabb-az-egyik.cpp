#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

int main(){
    int p; cin>>p;           // az utolsó lehetséges időpont
    int a; cin>>a;           // Ádám elérhetőségeinek száma
    vector<pii> v;           // minden intervallum tárolása

    // Ádám intervallumainak beolvasása
    for(int i=0;i<a;i++){
        int x,y; cin>>x>>y;
        v.push_back({x,y});
    }

    int e; cin>>e;           // Éva elérhetőségeinek száma
    int n=a+e;               // összes intervallum száma
    for(int i=0;i<e;i++){
        int x,y; cin>>x>>y;
        v.push_back({x,y});
    }

    sort(v.begin(),v.end()); // intervallumok kezdete szerinti rendezés

    int i=0;
    vector<pii> ans;         // összevont elérhetőségi intervallumok

    // intervallumok összefésülése
    while(i<n){
        auto [l,r]=v[i];     // aktuális intervallum kezdete és vége
        i++;
        while(i<n && v[i].first <= r){ // ha van átfedés
            r = max(r, v[i].second);  // bővítjük a végét
            i++;
        }
        ans.push_back({l,r});  // hozzáadjuk az összevont intervallumot
    }

    sort(ans.begin(),ans.end()); // biztosan időrendben
    cout<<ans.size()<<'\n';      // intervallumok száma
    for(auto [x,y]:ans) cout<<x<<' '<<y<<'\n'; // kiírás
}

#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

int main(){
    int n;
    cin>>n; // elemszám
    vector<pii> a(n);
    
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x==-1) x=n+1; // -1 speciális érték átalakítása
        a[i]={x,i};        // (érték, eredeti index)
    }
    
    // Egyedi rendezés: először érték szerint növekvő, ha egyezik, index szerint csökkenő
    sort(a.begin(), a.end(), [&](pii p, pii q){
        if(p.first!=q.first) return p.first<q.first;
        return p.second>q.second;
    });
    
    vector<int> ans(n);
    // hozzárendelés a rangokhoz
    for(int i=1;i<=n;i++){
        ans[a[i-1].second]=i;
    }
    
    for(int x:ans) cout<<x<<' '; // rangok kiírása az eredeti sorrendben
    cout<<'\n';
}

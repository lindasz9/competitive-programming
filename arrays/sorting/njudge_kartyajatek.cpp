#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll n,k;cin>>n>>k; // beolvasás: n a teljes pakli mérete, k a kiválasztott lapok száma
    vector<ll> sor(k); // a kevert pakli sorrendje
    vector<pii> ossz(k); // lap értéke és eredeti indexe
    for(int i=0;i<k;i++){
        ll a;cin>>a; // lap beolvasása
        sor[i]=a; 
        ossz[i]={a,i}; // érték és index tárolása
    }
    sort(ossz.begin(),ossz.end()); // lapok érték szerint növekvő sorrendbe rendezése

    int id=-1,ans=0; // id: legutoljára vizsgált lap az érték szerint rendezett listában, ans: pontszám
    for(int i=0;i<k;i++){
        ll x=sor[i]; // aktuálisan lehelyezett lap
        int cnt=0; // félrerakott lapok száma az adott lépésben
        while(id<k-1&&ossz[id+1].first<x){ // vizsgáljuk, hogy vannak-e kisebb lapok
            id++;
            if(ossz[id].second>i)cnt++; // csak azok számítanak, amik még a kezében vannak (index nagyobb mint i)
        }
        if(cnt)ans++; // ha legalább egy lapot félrerakott, pontot kap
    }
    cout<<ans<<'\n'; // összpontszám kiírása
}

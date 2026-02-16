#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

int main(){
    int n,q; cin>>n>>q; // szenátorok és Caesar gladiátorai száma
    vector<pii> nn(n); // szenátor gladiátorainak ereje és a legyőzéskor kapott növekedés
    for(int i=0;i<n;i++){
        cin>>nn[i].first>>nn[i].second;
    }

    // szenátor gladiátorainak rendezése: erő szerint növekvő, ha azonos, növekedés szerint csökkenő
    sort(nn.begin(),nn.end(),[&](pii a,pii b){
        if(a.first==b.first) return a.second>b.second;
        return a.first<b.first;
    });

    vector<int> pref(n); // prefix összeg: szükséges kezdőerő az adott számú győzelemhez
    int cnt=0;
    for(int i=0;i<n;i++){
        auto [a,b]=nn[i];
        int diff=max(0,a-cnt); // ha szükséges, erőt pótolunk
        if(i==0) pref[0]=diff;
        else pref[i]=pref[i-1]+diff;
        cnt+=diff; // Caesar gladiátor erejének frissítése
        cnt+=b;    // győzelem utáni növekedés
    }

    while(q--){
        int x; cin>>x; // Caesar gladiátor kezdőereje
        cout << upper_bound(pref.begin(),pref.end(),x)-pref.begin() << ' '; // maximum legyőzhető ellenfelek
    }
    cout<<'\n';
}

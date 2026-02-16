#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m; cin>>n>>m; // kikötők száma, hajók száma
    vector<int> diff(n+2); // különbségtömb a hatékony intervallum-növeléshez
    while(m--){
        int l,r; cin>>l>>r; // hajó induló és végállomása
        diff[l]++;       // minden közbülső kikötőt érintő intervallum növelése
        diff[l+1]++;
        diff[r]--;       
        diff[r+1]--;
    }
    int pref=0,ans=0;
    int id=-1;
    for(int i=1;i<=n;i++){
        pref+=diff[i]; // prefix összeg: hajók kikötéseinek száma az adott kikötőben
        if(pref>ans){
            ans=pref; id=i; // új maximum és a hozzá tartozó kikötő
        }
    }
    cout<<id<<' '<<ans<<'\n'; // legtöbb kikötés helye és száma
}

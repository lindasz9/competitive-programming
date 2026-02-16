#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

int main(){
    int n,m;
    cin>>n>>m; // n: sorozat hossza, m: intervallumok száma
    
    vector<int> a(n+2);
    for(int i=1;i<=n;i++) cin>>a[i]; // sorozat elemei
    
    vector<int> diff(n+2); // differenciál tömb az intervallumokhoz
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        diff[x]++;   // intervallum kezdete
        diff[y]--;   // intervallum vége +1
    }
    
    vector<int> pref(n+2); 
    // prefix összegek: pref[i]>0, ha az i. index része legalább egy intervallumnak
    for(int i=1;i<=n;i++) pref[i]=pref[i-1]+diff[i];
    
    int l=1;
    // minden rész, amelyet nem fed intervallum, növekvőre rendezhető
    for(int i=1;i<=n;i++){
        if(pref[i]==0){
            sort(a.begin()+l, a.begin()+i+1);
            l=i+1;
        }
    }
    if(l<=n) sort(a.begin()+l, a.end());
    
    int c=0;
    // megszámoljuk, hány indexnél teljesül, hogy a[i]==i
    for(int i=1;i<=n;i++) if(a[i]==i) c++;
    
    cout<<c<<'\n'; // végső eredmény
}

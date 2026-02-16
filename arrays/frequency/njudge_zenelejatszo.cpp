#include <bits/stdc++.h>
using namespace std;
using pii=pair<int, int>;

int main() {
    int n; cin>>n; // gombnyomások száma
    map<int,int> cnt; // különbségek számlálása
    int prev=0;
    for(int i=0;i<n;i++){
        int t; cin>>t;
        cnt[t-prev]++; // az aktuális és az előző gombnyomás különbsége
        prev=t;
    }
    vector<int> ans;
    int pref=1;
    for(auto p:cnt){
        ans.push_back(pref); // lehetséges válogatás száma
        pref+=cnt[p.first];
    }
    ans.push_back(n+1); // legnagyobb lehetséges válogatás
    cout<<ans.size()<<'\n';
    for(int x:ans) cout<<x<<' '; // összes lehetséges válogatás
    cout<<'\n';
}

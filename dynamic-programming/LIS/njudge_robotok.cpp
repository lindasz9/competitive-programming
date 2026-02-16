#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

const int inf=INT_MAX;

int main(){
    int n,m,k; cin>>n>>m>>k;
    vector<pii> vec(k);
    for(int i=0;i<k;i++) cin>>vec[i].first>>vec[i].second; // tárgy koordináták

    sort(vec.begin(), vec.end()); // sorba rendezés sor szerint

    vector<int> a, d(k, inf);
    d[0] = -inf;

    for(auto [b,c]:vec) a.push_back(-c); // oszlop koordináták negatívban

    int ans=0;
    // LIS-szerű algoritmus: legkevesebb robot = legnagyobb láncok száma
    for(int x:a){
        int id = lower_bound(d.begin(), d.end(), x) - d.begin();
        d[id] = x;
        ans = max(ans, id);
    }

    cout << ans << '\n'; // szükséges robotok száma
}

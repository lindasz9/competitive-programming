#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const ll M=1e9+7;

// moduláris inverz számítása gyors hatványozással
ll inv(ll n){
    ll res=1, mm=M-2;
    while(mm){
        if(mm&1) res=res*n%M;
        n=n*n%M;
        mm>>=1;
    }
    return res;
}

int main(){
    ll b,c; cin>>b>>c; // Béla kezdő és célpont
    vector<ll> fact(2*c-b); // faktoriális előkalkuláció
    fact[0]=1;
    for(ll i=1;i<2*c-b;i++) fact[i]=fact[i-1]*i%M;

    // kombinációk számítása, majd a Catalan-szerű képlet alkalmazása
    ll ans = ((fact[2*c-b-1]*inv(fact[c-1])%M*inv(fact[c-b])%M
              - fact[2*c-b-1]*inv(fact[c])%M*inv(fact[c-b-1])%M) + M) % M;
    cout<<ans<<'\n';
}

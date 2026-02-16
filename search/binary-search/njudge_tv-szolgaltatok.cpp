#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int maxn=1e5+1;
int n,k,l[maxn],r[maxn];

// Számolja, hány peták szükséges, hogy a [kk, kk+K-1] intervallumot lefedjék minden szolgáltatóval
ll cnt(ll kk){
    ll res=0;
    int a=kk, b=kk+k-1;
    for(int i=0;i<n;i++){
        res += max(0, l[i]-a); // balra való kiterjesztés költsége
        res += max(0, b-r[i]); // jobbra való kiterjesztés költsége
    }
    return res;
}

int main(){
    cin>>n>>k; // szolgáltatók száma, K ház
    
    for(int i=0;i<n;i++) cin>>l[i]>>r[i]; // jelenlegi lefedés
    
    ll a=1, b=1e9-k; // bináris keresés intervalluma
    while(a<b){
        ll m=(a+b)/2;
        if(cnt(m) < cnt(m+1)) b=m;
        else a=m+1;
    }
    
    cout<<min(cnt(a), cnt(b))<<'\n'; // minimális összköltség
}

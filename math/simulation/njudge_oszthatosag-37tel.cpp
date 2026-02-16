#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    ios::sync_with_stdio(false);
    ll n; cin>>n;
    
    // oszthatóság vizsgálata
    if(n % 37 == 0) cout<<"IGEN\n";
    else cout<<"NEM\n";

    // közbülső számok kiszámolása a szabály szerint
    while(n > 0){
        n = n/10 - (n%10)*11;
        if(n >= 0) cout<<n<<' ';
    }
    cout<<'\n';
}

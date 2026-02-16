#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k; cin>>n>>k;  // n = ingatlanok száma, k = Mr. S vagyona
    vector<array<int,3>> v(n); // minden ingatlan: {adó, érték, ár}
    for(int i=0;i<n;i++) cin>>v[i][1]>>v[i][2]>>v[i][0]; 
    // v[i][0] = adó, v[i][1] = ár, v[i][2] = érték

    vector<int> dp(k+1);  // dp[i] = maximális érték, amit i bájtdollárból elérhetünk
    int ans=0;

    sort(v.begin(),v.end()); // adó szerint növekvő rendezés

    for(auto [a,b,c]:v){ // a = adó, b = ár, c = érték
        // klasszikus 0/1 hátizsák DP, hátrafelé iterálva
        for(int i=k;i-b>=0;i--){
            dp[i] = max(dp[i], dp[i-b] + c);
        }
        // biztosítjuk, hogy a maximális adót még ki tudjuk fizetni
        ans = max(ans, dp[k-a]);
    }

    cout<<ans<<'\n'; // legnagyobb összérték
}

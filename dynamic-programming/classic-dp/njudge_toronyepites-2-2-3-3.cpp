#include <bits/stdc++.h>
using namespace std;

const int m = 20210108;

int main(){
    int n; cin >> n;
    vector<int> dp(n+1);
    dp[0] = 1; // üres torony

    for(int i=1;i<=n;i++){
        dp[i] = 0;
        if(i>=2) dp[i] = (dp[i] + 2LL*dp[i-2]%m) % m; // piros vagy zöld tégla
        if(i>=3) dp[i] = (dp[i] + 2LL*dp[i-3]%m) % m; // sárga vagy fehér tégla
    }

    cout << dp[n] << '\n';
}

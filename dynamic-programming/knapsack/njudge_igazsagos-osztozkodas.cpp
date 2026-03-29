#include <bits/stdc++.h>
using namespace std;
#define int long long

const int M = 1e9 + 7;

signed main(){
    int n;
    cin >> n;

    vector<int> A(n), B(n); // A[i]: almák száma, B[i]: banánok száma az i-edik csomagban

    int a = 0, b = 0; // összes alma és banán

    // bemenet feldolgozása
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;

        for(char c : s){
            if(c == 'a') A[i]++; // alma
            else B[i]++;         // banán
        }

        a += A[i];
        b += B[i];
    }

    // ha bármelyik összeg páratlan, nem lehet egyenlően elosztani
    if(a & 1 || b & 1){
        cout << "0\n";
        return 0;
    }

    // felezni kell az összes mennyiséget (ennyit kell kapnia az egyik félnek)
    a /= 2;
    b /= 2;

    // dp[i][j]: hányféleképpen választhatunk csomagokat úgy,
    // hogy i almát és j banánt kapjunk
    int dp[a+1][b+1];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1; // 0 alma és 0 banán egyféleképpen (nem választunk semmit)

    // minden csomagra 0-1 knapsack
    for(int id = 0; id < n; id++){
        int aa = A[id], bb = B[id];

        // visszafelé iterálunk, hogy ne használjuk fel többször ugyanazt a csomagot
        for(int i = a; i >= 0; i--){
            for(int j = b; j >= 0; j--){
                if(aa > i || bb > j) break; // nem fér bele

                // hozzáadjuk azokat az eseteket, amikor ezt a csomagot is választjuk
                dp[i][j] = (dp[i][j] + dp[i-aa][j-bb]) % M;
            }
        }
    }

    // eredmény: pontosan a/ b mennyiséget elérő választások száma
    cout << dp[a][b] << '\n';
}

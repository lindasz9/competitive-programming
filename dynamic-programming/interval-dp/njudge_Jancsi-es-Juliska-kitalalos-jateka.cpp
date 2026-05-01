#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> v(n);

    // tömb beolvasása
    for(int i = 0; i < n; i++) cin >> v[i];

    // dp[l][r] = minimális költség az [l, r] intervallumra
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

    // c[l][r] = maximum érték az intervallumban
    vector<vector<int>> c(n, vector<int>(n));

    // alap: egy elemű intervallum
    for(int i = 0; i < n; i++){
        dp[i][i] = 0;
        c[i][i] = v[i];
    }

    // maximumok előszámolása
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            c[i][j] = max(c[i][j - 1], v[j]);
        }
    }

    // két elemű intervallumok
    for(int i = 0; i < n - 1; i++){
        dp[i][i + 1] = min(v[i], v[i + 1]);
    }

    // intervallum DP
    for(int hossz = 2; hossz < n; hossz++){
        for(int l = 0; l + hossz < n; l++){
            int r = l + hossz;

            // minden lehetséges felosztás kipróbálása
            for(int a = l; a <= r; a++){
                for(int b = a; b <= r; b++){

                    int legrosszabb = 0;

                    // bal rész
                    if(a - 1 >= l)
                        legrosszabb = max(legrosszabb, dp[l][a - 1]);

                    // középső rész
                    legrosszabb = max(legrosszabb, dp[a][b]);

                    // jobb rész
                    if(b < r)
                        legrosszabb = max(legrosszabb, dp[b + 1][r]);

                    // költség = középső max + legrosszabb oldal
                    dp[l][r] = min(dp[l][r], c[a][b] + legrosszabb);
                }
            }
        }
    }

    cout << dp[0][n - 1];
}

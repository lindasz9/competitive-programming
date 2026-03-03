#include <bits/stdc++.h>
using namespace std;
#define int long long

// Maximum méret (N,M ≤ 500, +1 a differenciatömb miatt)
const int maxn = 502;

// Mátrix, ebben tároljuk először a differenciát,
// majd ebből számoljuk ki a tényleges vízmennyiséget
int mat[maxn][maxn];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k, e;
    cin >> n >> m >> k >> e;

    // 2D differenciatömb feltöltése
    // Minden esőzés egy téglalapra +1 vizet jelent
    while(e--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        mat[a][b]++;           // bal alsó sarok
        mat[c+1][b]--;         // jobb alsó utáni sor
        mat[a][d+1]--;         // bal felső utáni oszlop
        mat[c+1][d+1]++;       // jobb felső utáni pont
    }

    // Kétszer számolunk prefixösszeget:
    // első kör: differenciatömb → tényleges vízmennyiség cellánként
    // második kör: 2D prefixösszeg a gyors K×K lekérdezéshez
    for(int t = 0; t < 2; t++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                mat[i][j] += mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];

    int best_x = 1, best_y = 1;
    int mx = -1;

    // Végigpróbáljuk az összes K×K négyzetet
    // (i,j) a négyzet jobb felső sarka
    for(int i = k; i <= n; i++){
        for(int j = k; j <= m; j++){

            // K×K részösszeg lekérdezése prefixösszeggel
            int total = mat[i][j]
                      - mat[i-k][j]
                      - mat[i][j-k]
                      + mat[i-k][j-k];

            if(total > mx){
                mx = total;
                best_x = i - k + 1;  // bal alsó sarok x
                best_y = j - k + 1;  // bal alsó sarok y
            }
        }
    }

    cout << mx << '\n';
    cout << best_x << ' ' << best_y << '\n';
}

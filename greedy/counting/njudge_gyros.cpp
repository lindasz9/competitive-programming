#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, C, B;
        cin >> n >> C >> B;

        int v = 0, b = 0, c = 0;

        // megszámoljuk az egyes rendeléstípusokat
        for(int i = 0; i < n; i++){
            char x; 
            cin >> x;

            if(x == 'V') v++;      // vegyes (1 csirke + 1 borjú)
            else if(x == 'B') b++; // borjú (2 borjú)
            else c++;              // csirke (2 csirke)
        }

        // előre kiválasztunk néhány vegyes rendelést
        // (korlátozva a készletek és a vegyes rendelések száma alapján)
        int vv = min(min(C, B) - 2, v);

        int ans = 0;

        // maradék erőforrások és rendelések
        int v1 = v - vv;
        int C1 = C - vv;
        int B1 = B - vv;

        // közös minimum (mindhárom típusból)
        int mn = min({C1, B1, v1});

        // két stratégia:
        // 1) csak külön (csirke + borjú) rendelések
        // 2) először vegyes, majd külön rendelések
        int x1 = max(
            min(C1/2, c) + min(B1/2, b),
            mn + min((C1 - mn)/2, c) + min((B1 - mn)/2, b)
        );

        // hozzáadjuk az előre kiválasztott vegyes rendeléseket
        ans = max(ans, x1) + vv;

        cout << ans << '\n';
    }
}

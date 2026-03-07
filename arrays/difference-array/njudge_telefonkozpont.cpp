#include <bits/stdc++.h>
using namespace std;

const int mx = 400002;

int main(){
    int n;
    cin >> n;

    // dif[i] = változás az i-edik időpontban
    vector<int> dif(mx);

    for(int i=0;i<n;i++){
        int start, end;
        cin >> start >> end;

        dif[start]++;     // hívás indul → +1 forgalom
        dif[end+1]--;     // hívás vége után → -1 forgalom
    }

    int ans = 0;
    int pref = 0; // aktuális egyidejű hívások száma

    for(int i=1; i<=mx; i++){
        pref += dif[i];     // prefix összeadás: aktuális forgalom
        ans = max(ans, pref); // eddigi maximum frissítése
    }

    cout << ans << '\n'; // legnagyobb egyidejű hívásszám
}

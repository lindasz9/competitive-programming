#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;          // ládák száma (páros)
    string s;
    cin >> s;          // ládák tartalma sorban ('A' vagy 'K')

    int a = 0;         // eddig kiválasztott almás ládák száma
    int k = n / 2;     // még elérhető körtés ládák száma (összesen n/2 van)
    int m = n / 2;     // (nem használt változó)
    int ans = 0;       // maximálisan felpakolható ládák száma

    for(int i = 0; i < n; i++){
        if(s[i] == 'A') 
            a++;       // ha alma, növeljük az almák számát
        else 
            k--;       // ha körte, csökkentjük a még hátralévő körték számát

        // csak akkor lehet érvényes, ha az eddigi almák száma
        // nem haladja meg a még elérhető körték számát
        if(a <= k) 
            ans = a * 2;   // ugyanannyi almát és körtét vihetünk
        else 
            break;         // különben nem tudjuk teljesíteni a feltételt
    }

    cout << ans << '\n';   // maximálisan felpakolható ládák száma
}

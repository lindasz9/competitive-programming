#include <bits/stdc++.h>
using namespace std;

const int m = 20200111;

int main(){
    int n;
    cin >> n;

    // dp1[i]: i hosszú 2×i téglalap teljes lefedésének száma
    // dp2[i]: i hosszú 2×i téglalap + kilógó rész állapotainak száma
    vector<int> dp1(n+1), dp2(n+1);

    dp1[0] = 1; // üres járda egyféleképpen fedhető le
    dp1[1] = 1; // alap eset

    dp2[1] = 2; // alap eset

    for(int i = 2; i <= n; i++){
        // teljes lefedés:
        dp1[i] = (dp1[i-2] + dp1[i-1] + dp2[i-2]) % m;

        // kilógó résszel:
        dp2[i] = (dp2[i-1] + 2*dp1[i-1] + dp2[i-2]) % m;
    }

    // eredmény: teljes lefedések száma
    cout << dp1[n] << '\n';
}

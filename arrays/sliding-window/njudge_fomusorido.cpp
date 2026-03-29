#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, t, s;
    cin >> n >> t >> s;

    vector<int> L(n), R(n);

    // reklámszünetek beolvasása
    for(int i = 0; i < n; i++) cin >> L[i] >> R[i];

    int ans = 0; // maximális reklámban töltött idő az S hosszú intervallumban
    int l = 0;   // bal pointer
    int sum = 0; // aktuális ablakban lévő reklámhossz

    // jobb pointerrel bővítjük az intervallumot
    for(int r = 0; r < n; r++){
        sum += R[r] - L[r]; // hozzáadjuk az új reklám hosszát

        // ha az intervallum túl hosszú (nagyobb mint S), balról szűkítünk
        while(R[r] - R[l] >= s){
            sum -= R[l] - L[l];
            l++;
        }

        // ha az aktuális ablak bal széle még túl balra van,
        // akkor levágunk belőle annyit, hogy pontosan S hosszú legyen
        if(L[l] < R[r] - s){
            int x = R[r] - s - L[l]; // levágandó rész
            sum -= x;
            L[l] += x; // módosítjuk a bal reklám kezdetét
        }

        // frissítjük a maximumot
        ans = max(ans, sum);
    }

    // a kihagyott sorozat = teljes idő - reklámban töltött idő
    cout << s - ans << '\n';
}

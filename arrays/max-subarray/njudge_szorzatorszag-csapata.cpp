#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    // t[i] = sportoló képessége, 1-indexelve
    vector<int> t(n+1);

    // neg[i] = az 1..i intervallumban hány negatív szám van
    // cnt2[i] = az 1..i intervallumban hány szám abs értéke 2
    vector<int> neg(n+1), cnt2(n+1);

    vector<int> zeros; // 0-k indexei, külön kezelt szegmensek
    for(int i=1; i<=n; i++){
        cin >> t[i];

        neg[i] = neg[i-1];
        cnt2[i] = cnt2[i-1];

        if(t[i]==0) zeros.push_back(i);   // nullákat gyűjtjük, mert ezek megszakítják a részsorozatot
        if(t[i]<0) neg[i]++;             // negatív számok száma
        if(abs(t[i])==2) cnt2[i]++;      // abs(2) számok száma
    }

    zeros.push_back(n+1); // kényelmi dummy, hogy az utolsó szegmenst is kezeljük

    int l = 1;             // szegmens bal széle
    int max_val = -INT_MAX; // maximális "2-esek száma" eddig
    int s=1, e=1;           // eredmény részsorozat kezdő és vég indexe

    for(int r : zeros){ // minden nulláig terjedő szegmens
        if(l >= r){
            l = r+1; 
            continue; // üres szegmens
        }

        int neg_count = neg[r-1] - neg[l-1]; // szegmens negatív számai

        if(neg_count & 1){ // páratlan negatív → el kell hagyni az egyik végét
            int first=0, last=0;
            for(int i=l; i<r; i++){
                if(t[i]<0){
                    last = i;            // utolsó negatív index
                    if(first==0) first = i; // első negatív index
                }
            }

            // eltávolítjuk az első negatívot (balról)
            if(first < r-1){
                int prod = cnt2[r-1] - cnt2[first]; // abs(2) száma
                if(prod > max_val){
                    max_val = prod;
                    s = first+1; e = r-1;
                }
            }

            // eltávolítjuk az utolsó negatívot (jobbról)
            if(l-1 < last-1){
                int prod = cnt2[last-1] - cnt2[l-1];
                if(prod > max_val){
                    max_val = prod;
                    s = l; e = last-1;
                }
            }
        }else{ // páros negatív → az egész szegmenst felhasználhatjuk
            int prod = cnt2[r-1] - cnt2[l-1];
            if(prod > max_val){
                max_val = prod;
                s = l; e = r-1;
            }
        }

        l = r+1; // következő szegmens kezdete
    }

    // speciális esetek
    if(max_val < 0 && (int)zeros.size() > 1) s = e = zeros[0]; // csak nullák vannak
    else if(n==1) s = e = 1;

    cout << s << ' ' << e << '\n';
}

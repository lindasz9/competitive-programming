#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n; // cél szoba száma (0..N-1)
    
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i]; // kezdeti kulcstípusok
    
    int cnt=0, id=0;           // cnt: újraindítások száma, id: aktuális szoba
    vector<bool> have(n);      // mely kulcsokat szereztük meg
    vector<int> cur;           
    
    while(id<n){
        int b=(a[id]+cnt)%n;   // aktuális szoba kulcsa a jelenlegi újraindításokkal
        if(!have[b]){
            have[b]=true;      // megszerezzük a kulcsot
            cur.push_back(b);  // ideiglenesen tároljuk a frissen szerzett kulcsokat
        }
        
        if(have[id]) id++;     // ha van kulcsunk a következő szobához, lépünk
        else{
            // újraindítás: frissítjük a kulcsokat a moduláris eltolással
            vector<int> cur2;
            for(int x:cur){
                int y=(x+1)%n;
                if(!have[y]){
                    cur2.push_back(y);
                    have[y]=true;
                }
            }
            swap(cur,cur2);
            cnt++; // újraindítás számláló
        }
    }
    
    cout<<cnt<<'\n'; // minimális újraindítások száma a cél eléréséhez
}

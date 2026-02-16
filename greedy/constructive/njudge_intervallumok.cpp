#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

int main(){
    int n;
    cin>>n; // elemek száma
    
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i]; // bemeneti tömb
    
    vector<pii> ans;              // (db, mx) párok tárolása
    vector<vector<int>> starts;   // az egyes megoldások kezdőértékei
    
    // db: hány részre bontjuk a tömböt (csak osztók jöhetnek szóba)
    for(int db=1;db<n;db++){
        if(n%db)continue; // csak akkor vizsgáljuk, ha db osztója n-nek
        
        int len=n/db; // egy blokk hossza
        
        int mx=0;
        // Meghatározzuk a blokkokon belüli (utolsó - első) maximumát
        for(int i=0;i<n;i+=len){
            mx=max(mx,a[i+len-1]-a[i]);
        }
        
        vector<int> cur; 
        // első blokk kezdőértéke
        cur.push_back(a[len-1]-mx);
        
        int prev=a[len-1]; // előző blokk vége
        bool ok=true;      // jelzi, hogy érvényes-e a konstrukció
        
        // további blokkok feldolgozása
        for(int i=len;i<n;i+=len){
            int jo=a[i+len-1]-mx; // minimális lehetséges kezdő
            int rossz=prev+1;    // biztosítjuk a szigorú növekedést
            
            int start=max(jo,rossz); // blokk tényleges kezdete
            
            // mennyit kell "tolni", ha a növekedés miatt módosítunk
            int r=jo>=rossz ? 0 : rossz-jo;
            
            int end=a[i+len-1]+r; // blokk vége eltolás után
            
            // ellenőrizzük, hogy nem ütközik a következő blokk első elemével
            if(i+len<n && end>=a[i+len])
                ok=false;
            
            prev=end;          // frissítjük az előző blokk végét
            cur.push_back(start);
        }
        
        if(ok){
            ans.push_back({db,mx}); // eltároljuk az érvényes (db, mx) párost
            starts.push_back(cur);  // és a kezdőértékeket
        }
    }
    
    cout<<ans.size()<<'\n'; // megoldások száma
    
    for(int i=0;i<(int)ans.size();i++){
        cout<<ans[i].first<<' '<<ans[i].second<<'\n';
        for(int x:starts[i])
            cout<<x<<' '; // adott felosztáshoz tartozó kezdőértékek
        cout<<'\n';
    }
}

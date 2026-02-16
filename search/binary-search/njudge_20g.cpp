#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

int main(){
    int n,q;
    cin>>n>>q; // n: lakóházak száma, q: lekérdezések száma
    
    vector<int> pref(n); 
    cin>>pref[0]; // az első ház magassága
    
    for(int i=1;i<n;i++){
        int x;
        cin>>x; 
        // pref[i] az első i+1 ház maximum magassága
        // így pref monoton nemcsökkenő lesz
        pref[i]=max(pref[i-1],x);
    }
    
    while(q--){
        int x;
        cin>>x; // antenna magassága (M)
        
        // Megkeressük az első olyan indexet, ahol a prefix maximum > x
        // Az előtte lévő házak mind megfelelnek (előttük nincs M-nél magasabb ház)
        cout<<upper_bound(pref.begin(),pref.end(),x)-pref.begin()+1<<'\n';
    }
}

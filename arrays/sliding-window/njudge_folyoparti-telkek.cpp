#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

int main(){
    int n,p;
    cin>>n>>p; // n: telkek száma, p: Lilla pénze
    
    vector<int> ar(n);
    for(int i=0;i<n;i++)
        cin>>ar[i]; // telkek árai
    
    int l=0,cur=0,ans=0;
    // l: bal pointer, cur: aktuális szakasz összege, ans: maximális hossz
    
    for(int r=0;r<n;r++){
        cur+=ar[r]; // jobb pointer bővítése
        
        // Ha túlléptük a keretet, balról szűkítjük az intervallumot
        while(cur>p){
            cur-=ar[l];
            l++;
        }
        
        // Frissítjük a maximális hosszúságot
        ans=max(ans,r-l+1);
    }
    
    cout<<ans<<'\n'; // kiírjuk a maximális megvehető egymás melletti telkek számát
}

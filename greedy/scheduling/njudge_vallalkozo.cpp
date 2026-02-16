#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m; // munkanapok száma, megrendelések száma
    
    vector<int> a(n+1); // naponta elvégezhető munkák
    for(int i=1;i<=n;i++) cin>>a[i];
    
    vector<int> b(m);   // megrendelések határideje
    for(int i=0;i<m;i++) cin>>b[i];
    
    sort(b.begin(),b.end()); // határidők növekvő sorrendbe
    
    int id=0, ans=0;
    for(int i=1;i<=n && id<m;i++){
        // átugorjuk a lejárt határidejű megrendeléseket
        while(id<m && b[id]<i) id++;
        
        int take = min(a[i], m-id); // hány munkát tudunk elvégezni az adott napon
        id += take;
        ans += take;                // összesített elvégzett munkák
    }
    
    cout<<ans<<'\n'; // maximálisan teljesíthető megrendelések száma
}

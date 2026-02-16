#include <bits/stdc++.h>
using namespace std;

const int maxn=30005;
vector<int> adj[maxn];

// DFS: kiszámítja a távolságokat egy kezdőcsúcsból
void dfs(int v,int pa,int dis,vector<int>& d){
    d[v]=dis;
    for(int to:adj[v]){
        if(to!=pa) dfs(to,v,dis+1,d);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t; // tesztesetek száma
    while(t--){
        int n,ts,js,k;
        cin>>n>>ts>>js>>k; // szobák, Tom kezdő, Jerry kezdő, teleport lépések száma
        
        vector<int> dt(n+1), dj(n+1), da(n+1);
        for(int i=1;i<=n;i++) adj[i].clear();
        
        // fa beolvasása
        for(int i=1;i<n;i++){
            int a,b; cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        dfs(ts,-1,0,dt); // Tomtól távolságok
        dfs(js,-1,0,dj); // Jerrytől távolságok
        
        bool yes=false;
        // Ha van olyan csúcs, ahol Jerry k lépés alatt elérhető,
        // de Tomnak több mint k lépés kell, akkor Jerry elmenekülhet
        for(int i=1;i<=n;i++){
            if(dj[i]<k && dt[i]>k) yes=true;
        }
        
        if(!yes){
            cout<<"IGEN\n"; // Tom mindig eléri Jerryt
            continue;
        }
        
        // fa átmérőjének meghatározása
        int a=1;
        for(int i=1;i<=n;i++){
            if(dt[i]>dt[a]) a=i;
        }
        dfs(a,-1,0,da);
        int mx=0;
        for(int i=1;i<=n;i++) mx=max(mx,da[i]);
        
        if(mx>k*2) cout<<"NEM\n"; // ha átmérő > 2*k, Jerry elmenekülhet
        else cout<<"IGEN\n";
    }
}

#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n,m;
vector<pii> xy={{0,-1},{-1,0},{0,1},{1,0}}; // bal, fel, jobb, le irányok

// mélység-alapú DFS: innen indulva felfedezzük a hozzáférhető barlangrészeket
void dfs(vector<vector<int>>& nm,int x,int y){
    int cur=nm[x][y]; // aktuális cella mélysége
    nm[x][y]=0;        // jelöljük, hogy már látogatott
    for(auto [a,b]:xy){
        int i=x+a,j=y+b;
        // határellenőrzés és nem-barlang átugrása
        if(i>n||i<1||j>m||j<1||!nm[i][j]) continue;
        // csak az egyenlő vagy mélyebb barlangrészek felé léphetünk
        if(nm[i][j]>=cur) dfs(nm,i,j);
    }
}

int main(){
    cin>>n>>m;
    vector<vector<int>> nm(n+1,vector<int>(m+1));
    vector<array<int,3>> q; // (mélység, sor, oszlop)
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            cin>>nm[i][j];
            if(nm[i][j]) q.push_back({nm[i][j],i,j}); // csak barlangrészek
        }
    
    sort(q.begin(),q.end()); // növekvő mélység szerint
    
    vector<pii> ans; // kezdőpontok
    
    for(auto [a,x,y]:q){
        if(nm[x][y]){  // ha még nem fedeztük fel
            dfs(nm,x,y); 
            ans.push_back({x,y}); // új kezdőpont
        }
    }
    
    cout<<ans.size()<<'\n'; // minimálisan szükséges kezdőpontok száma
    for(auto [a,b]:ans)
        cout<<a<<' '<<b<<'\n'; // sor- és oszlopindex
}

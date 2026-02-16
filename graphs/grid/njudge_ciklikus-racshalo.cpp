#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

const int maxn=201;
vector<int> adj[maxn];  // szomszédok listája
int d[maxn][maxn];      // távolságok

int main(){
    int n,m,k;
    cin>>n>>m>>k; // sorok, oszlopok, új élek száma
    
    // Alap rács élei: sorfolytonosan és toroidisan
    for(int i=1;i<=n;i++){
        for(int j=(i-1)*m+1;j<i*m;j++){
            adj[j].push_back(j+1);
            adj[j+1].push_back(j);
        }
        adj[i*m].push_back((i-1)*m+1);
        adj[(i-1)*m+1].push_back(i*m);
    }
    for(int i=1;i<=m;i++){
        for(int j=i;j<(n-1)*m+i;j+=m){
            adj[j].push_back(j+m);
            adj[j+m].push_back(j);
        }
        adj[(n-1)*m+i].push_back(i);
        adj[i].push_back((n-1)*m+i);
    }
    
    while(k--){
        int a,b; cin>>a>>b; // új él
        adj[a].push_back(b);
        adj[b].push_back(a);
        
        int mx=0;
        // BFS minden csúcsból a távolságok meghatározására
        for(int i=1;i<=n*m;i++){
            for(int j=1;j<=n*m;j++) d[i][j]=0;
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int v=q.front(); q.pop();
                for(int x:adj[v]){
                    if(!d[i][x] && x!=i){
                        q.push(x);
                        d[i][x]=d[i][v]+1;
                    }
                }
            }
            // maximális távolság a gráfban
            for(int j=1;j<=n*m;j++) mx=max(mx,d[i][j]);
        }
        
        cout<<mx<<'\n'; // minimális lépésszám minden új él után
    }
}

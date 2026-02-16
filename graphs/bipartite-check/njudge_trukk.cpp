#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

const int M=1e9+7;

// DFS segítségével ellenőrizzük, hogy a gráf két színnel színezhető-e
bool dfs(vector<vector<int>>& adj, vector<int>& c, int v){
	for(int u:adj[v]){
		if(c[u]==0){
			if(c[v]==1) c[u]=2;
			else c[u]=1;
			if (!dfs(adj,c,u)) return false; // ha nem színezhető, false
		}else if(c[u]==c[v]) return false; // ha szomszédok azonos színűek, nem bipartit
	}
	return true;
}

int main() {
	int t; cin>>t; // bemutatók száma
	while(t--){
		int n,k; cin>>n>>k; // dobozok száma, feltételek száma
		vector<vector<int>> adj(n+1); // gráf reprezentáció: intervallumokból élek
		for(int i=0;i<k;i++){
			int a,b; cin>>a>>b;
			adj[a-1].push_back(b); 
			adj[b].push_back(a-1);
		}
		vector<int> c(n+1); // színek tárolása: 0=nincs, 1-2=sínek
		bool ok=true;
		int cnt=0; // összefüggő komponensek száma
		for(int i=0;i<=n;i++)
			if(c[i]==0){
				cnt++;
				if(!dfs(adj,c,i)) ok=false; // ha bármely komponens nem színezhető, nincs megoldás
			}
		if(!ok){
			cout<<"0\n";
			continue;
		}
		int ans=1;
		for(int i=1;i<cnt;i++) ans=1LL*ans*2%M; // minden további komponens szabad választás a színezéshez
		cout<<ans<<'\n';
	}
}

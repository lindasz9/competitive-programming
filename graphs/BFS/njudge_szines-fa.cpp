#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

int main(){
    int n; cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i=2;i<=n;i++){
        int a; cin>>a;
        adj[a].push_back(i); // fa él
    }

    queue<pii> q;
    q.push({1,1}); // kezdés a gyökérrel, szín 1
    vector<int> c(n+1);
    int ans=0;

    while(!q.empty()){
        auto [v,col] = q.front(); q.pop();
        if(ans){
            c[v] = ans; // minden további csúcsra az utolsó szín
        } else {
            c[v] = col;
            if(adj[v].size()==0) ans = col; // levél: maximális szín
        }
        for(int u:adj[v]) q.push({u, col+1});
    }

    cout << ans << '\n'; // maximális szín
    for(int i=1;i<=n;i++) cout << c[i] << ' '; 
    cout << '\n';
}

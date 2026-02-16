#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;

const int maxn=100001;
unordered_map<int,vector<pii>> x,y; // x és y koordináták szerint csoportosított állomások
vector<pii> adj[maxn]; // gráf: szomszéd + távolság
int n;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b; cin>>a>>b;
        x[a].push_back({b,i}); // azonos x koordinátájú állomások
        y[b].push_back({a,i}); // azonos y koordinátájú állomások
    }

    // élek létrehozása: azonos x vagy y koordinátán egymás melletti állomások
    for(auto xy:{x,y})
        for(auto& [i,v]:xy){
            sort(v.begin(),v.end());
            auto [pa,pj]=v[0];
            for(auto [a,j]:v){
                if(j==pj) continue;
                adj[j].push_back({pj,a-pa});
                adj[pj].push_back({j,a-pa});
                pa=a; pj=j;
            }
        }

    set<pii> q; q.insert({0,0}); // Prim algoritmushoz prioritási sor: {súly, csúcs}
    vector<bool> used(n);
    vector<int> minw(n,INT_MAX);
    int mxw=0, mxcnt=0;

    // Prim-algoritmus a minimum teljesítményhez (max edge MST)
    for(int i=0;i<n;i++){
        auto [w,v]=*q.begin();
        q.erase(q.begin());
        if(w>mxw){ mxw=w; mxcnt=1; } // legnagyobb él súly nyomon követése
        else if(w==mxw) mxcnt++;
        used[v]=true;
        for(auto [u,uw]:adj[v]){
            if(!used[u] && uw<minw[u]){
                q.erase({minw[u],u});
                minw[u]=uw;
                q.insert({uw,u});
            }
        }
    }

    cout<<mxw<<'\n'<<mxcnt<<'\n'; // legkisebb szükséges teljesítmény és ehhez tartozó élpárok száma
}

#include <bits/stdc++.h>
using namespace std;
#define pb push_back

const int maxn=20001,maxm=100001;
vector<array<int,3>> adj[maxn]; // szomszédsági lista: {szomszéd, él index, irány}
int dir[maxm], cnt[maxn];       // dir tárolja az él irányát, cnt a bejárt élek számát csúcsonként

// Euler út bejárás az élek irányának meghatározására
void euler(int start){
    stack<int> st;
    st.push(start);
    while(!st.empty()){
        int v=st.top();
        bool found=false;
        while(cnt[v]<(int)adj[v].size()){
            auto [to,i,d]=adj[v][cnt[v]++]; // szomszéd, él index, irány
            if(dir[i]!=0) continue;         // ha már beállítottuk az irányt, kihagyjuk
            dir[i]=d;                        // irány hozzárendelése
            found=true;
            st.push(to);
            break;
        }
        if(!found) st.pop();
    }
}

int main(){
    int n,m; cin>>n>>m;  // városok és felújítandó útszakaszok száma
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        adj[a].pb({b,i,1}); // 1 = a->b irány
        adj[b].pb({a,i,2}); // 2 = b->a irány
    }

    vector<int> odds;
    for(int i=1;i<=n;i++)
        if(adj[i].size() & 1) odds.pb(i); // páratlan fokszámú csúcsok gyűjtése

    // páratlan fokszámú csúcsok összekötése, hogy minden csúcs páros fokú legyen
    for(int i=0;i<(int)odds.size()-1;i+=2){
        adj[odds[i]].pb({odds[i+1],m+i+1,1});
        adj[odds[i+1]].pb({odds[i],m+i+1,2});
    }

    // Euler út bejárása minden olyan csúcsból, ahol maradt bejárt él
    for(int v=1;v<=n;v++){
        if(cnt[v]<adj[v].size()) euler(v);
    }

    cout<<odds.size()<<'\n'; // összes minimális terhelés
    for(int i=0;i<m;i++){
        if(dir[i]==1) cout<<"<- "; // a->b irány
        else cout<<"-> ";          // b->a irány
    }
    cout<<'\n';
}

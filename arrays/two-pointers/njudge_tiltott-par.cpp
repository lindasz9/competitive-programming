#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; 
    cin>>n;
    vector<int> a(n);
    unordered_map<int,vector<int>> m;   // tárolja minden érték előfordulásainak indexeit
    map<pii,int> memo;                  // lekérdezések memoizálása, hogy ne számoljuk újra ugyanazt

    for(int i=0;i<n;i++){
        cin>>a[i];
        m[a[i]].push_back(i);          // az a[i] érték előfordulásának indexét eltesszük
    }

    int q; cin>>q;
    while(q--){
        int x,y; cin>>x>>y;

        // ha már számoltuk ezt a kérdést, azonnal visszaadjuk
        if(memo.count({x,y})){
            cout<<memo[{x,y}]<<'\n';
            continue;
        }

        vector<int> &vx = m[x], &vy = m[y]; // x és y indexlistái
        int ans = 0, l = 0, r = vy.size() - 1;

        // kétpointeres módszer: hány Ap=X és Aq=Y páros van p<q
        while(l < vx.size() && r >= 0 && vx[l] < vy[r]){
            ans++; l++; r--;
        }

        // memoizáljuk az eredményt és kiírjuk
        cout << (memo[{x,y}] = ans) << '\n';
    }
}

#include <bits/stdc++.h>
using namespace std;
#define int long long

// Fenwick Tree (BIT) add operation: adds x at position l
void add(vector<int>& ft, int mx, int l, int x){
    for(int i = l; i < mx; i += i & (-i))
        ft[i] += x;
}

// Fenwick Tree prefix sum query: sum [1..x]
int get(vector<int>& ft, int x){
    int res = 0;
    for(int i = x; i > 0; i -= i & (-i))
        res += ft[i];
    return res;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // queries: (value, type, time, original_index)
    vector<array<int,4>> q(n);

    for(int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        q[i] = {c, a, b, i}; // reorder for grouping by value
    }

    // sort by value
    sort(q.begin(), q.end(), [](array<int,4> a, array<int,4> b){
        if(a[0] == b[0]) return a[3] < b[3];
        return a[0] < b[0];
    });

    vector<int> ans(n, -1);
    int id = 0;

    // process queries grouped by value
    while(id < n){
        int x = q[id][0];

        vector<array<int,3>> v; // (type, time, index)

        // collect same-value queries
        while(id < n && q[id][0] == x){
            v.push_back({q[id][1], q[id][2], q[id][3]});
            id++;
        }

        // coordinate compression for time values
        set<int> s;
        for(auto &it : v) s.insert(it[1]);

        unordered_map<int,int> mp;
        int idx = 1;
        for(int t : s)
            mp[t] = idx++;

        vector<int> ft(idx + 5, 0); // Fenwick tree

        // process operations for this value
        for(auto &it : v){
            int type = it[0];
            int time = it[1];
            int index = it[2];

            if(type == 1){
                // add occurrence
                add(ft, idx, mp[time], 1);
            }
            else if(type == 2){
                // remove occurrence
                add(ft, idx, mp[time], -1);
            }
            else{
                // query count at time
                ans[index] = get(ft, mp[time]);
            }
        }
    }

    // output answers
    for(int x : ans)
        if(x != -1)
            cout << x << '\n';
}

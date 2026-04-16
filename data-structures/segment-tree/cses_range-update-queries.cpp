#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 2e5 * 5;

// t[v] stores lazy value: how much is added to the whole segment
// a[] stores initial array
int t[maxn], a[maxn];

// build segment tree (only base values matter at leaves)
void build(int v, int l, int r){
    if(l == r){
        t[v] = a[l]; // leaf stores original value
    }
    else{
        int m = (l + r) / 2;
        build(v * 2, l, m);
        build(v * 2 + 1, m + 1, r);
        t[v] = 0; // internal nodes store only lazy increments
    }
}

// range add: add x to all elements in [ql, qr]
void update(int v, int l, int r, int ql, int qr, int x){
    // no overlap
    if(r < ql || l > qr) return;

    // fully covered segment -> store lazy update
    if(ql <= l && r <= qr){
        t[v] += x;
        return;
    }

    // partial overlap -> propagate to children
    int m = (l + r) / 2;
    update(v * 2, l, m, ql, qr, x);
    update(v * 2 + 1, m + 1, r, ql, qr, x);
}

// point query: get value at position k
int atk(int v, int l, int r, int k){
    if(l == r){
        return t[v]; // base value + all accumulated updates
    }
    else{
        int m = (l + r) / 2;

        // accumulate all lazy values along the path
        if(k <= m)
            return t[v] + atk(v * 2, l, m, k);
        else
            return t[v] + atk(v * 2 + 1, m + 1, r, k);
    }
}

signed main(){
    int n, q;
    cin >> n >> q;

    // read initial array
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    // build structure
    build(1, 1, n);

    // process queries
    while(q--){
        int type;
        cin >> type;

        if(type == 1){
            int a, b, u;
            cin >> a >> b >> u;

            // add u to range [a, b]
            update(1, 1, n, a, b, u);
        }
        else{
            int k;
            cin >> k;

            // query value at position k
            cout << atk(1, 1, n, k) << '\n';
        }
    }
}

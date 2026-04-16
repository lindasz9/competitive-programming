#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 2e5 * 5;

// t: segment tree array
// a: original array
int t[maxn], a[maxn];

// build segment tree on interval [l, r]
void build(int v, int l, int r){
    if(l == r){
        t[v] = a[l]; // leaf node stores array value
    }
    else{
        int m = (l + r) / 2;

        // build left and right children
        build(v * 2, l, m);
        build(v * 2 + 1, m + 1, r);

        // current node stores minimum of children
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
}

// point update: set a[i] = x
void update(int v, int l, int r, int x, int i){
    if(l == r){
        t[v] = x; // update leaf
    }
    else{
        int m = (l + r) / 2;

        // go to the correct child
        if(i <= m) update(v * 2, l, m, x, i);
        else update(v * 2 + 1, m + 1, r, x, i);

        // update current node after child update
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
}

// range minimum query on [ql, qr]
int minq(int v, int l, int r, int ql, int qr){
    // no overlap
    if(r < ql || l > qr) return LLONG_MAX;

    // full overlap
    if(ql <= l && r <= qr) return t[v];

    // partial overlap
    int m = (l + r) / 2;
    return min(
        minq(v * 2, l, m, ql, qr),
        minq(v * 2 + 1, m + 1, r, ql, qr)
    );
}

signed main(){
    int n, q;
    cin >> n >> q;

    // read array (1-indexed)
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    // build segment tree
    build(1, 1, n);

    // process queries
    while(q--){
        int type, b, c;
        cin >> type >> b >> c;

        if(type == 1){
            // update position b to value c
            update(1, 1, n, c, b);
        } else {
            // query minimum on range [b, c]
            cout << minq(1, 1, n, b, c) << '\n';
        }
    }
}

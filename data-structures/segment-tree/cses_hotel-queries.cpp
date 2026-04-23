#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 2e5 + 1;
const int maxn4 = maxn * 4;

int t[maxn4], a[maxn];

// build segment tree: t[v] stores maximum free rooms in interval
void build(int v, int l, int r){
    if(l == r){
        t[v] = a[l]; // leaf = hotel capacity
    }
    else{
        int m = (l + r) / 2;

        build(v * 2, l, m);
        build(v * 2 + 1, m + 1, r);

        // internal node stores maximum free rooms
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
}

// update hotel i to new value x (after assigning rooms)
void update(int v, int l, int r, int i, int x){
    if(l == r){
        t[v] = x; // update leaf
    }
    else{
        int m = (l + r) / 2;

        if(i <= m) update(v * 2, l, m, i, x);
        else update(v * 2 + 1, m + 1, r, i, x);

        // update max value upward
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
}

// find first hotel index with at least x free rooms
int firstx(int v, int l, int r, int x){
    // if no hotel in this segment can satisfy request
    if(t[v] < x) return -1;

    // leaf = found hotel
    if(l == r) return l;

    int m = (l + r) / 2;

    // try left side first (first fit requirement)
    if(t[v * 2] >= x)
        return firstx(v * 2, l, m, x);
    else
        return firstx(v * 2 + 1, m + 1, r, x);
}

signed main(){
    int n, m;
    cin >> n >> m;

    // read hotel capacities
    for(int i = 1; i <= n; i++) cin >> a[i];

    // build segment tree
    build(1, 1, n);

    // process groups
    while(m--){
        int x; // required rooms
        cin >> x;

        // find first hotel with enough rooms
        int i = firstx(1, 1, n, x);

        if(i == -1){
            // no hotel found
            cout << "0 ";
        }
        else{
            // assign group to hotel i
            a[i] -= x;

            // update segment tree
            update(1, 1, n, i, a[i]);

            cout << i << ' ';
        }
    }
}

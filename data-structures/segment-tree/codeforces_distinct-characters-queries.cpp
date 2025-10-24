#include <bits/stdc++.h>
using namespace std;

const int MAXLEN = 100002;
vector<vector<bool>> st(MAXLEN*4, vector<bool>(26)); // segment tree storing character presence for each segment
string s;

// combine two segment vectors to merge character presence info
vector<bool> combine(vector<bool> v1, vector<bool> v2) {
    vector<bool> v3(26);
    for (int i = 0; i < 26; i++)
        if (v1[i] || v2[i])
            v3[i] = true;
    return v3;
}

// build segment tree
void build(int v, int l, int r) {
    if (l == r) { // leaf node represents a single character
        int x = (int)s[l] - (int)'a';
        st[v][x] = true;
    } else {
        int m = (l + r) / 2;
        build(v*2, l, m);
        build(v*2+1, m+1, r);
        st[v] = combine(st[v*2], st[v*2+1]); // merge children's info
    }
}

// query distinct characters in range [tl, tr]
vector<bool> get(int v, int l, int r, int tl, int tr) {
    if (tl > r || tr < l) return vector<bool>(26); // no overlap
    if (l >= tl && r <= tr) return st[v]; // full overlap
    int m = (l + r) / 2;
    return combine(get(v*2, l, m, tl, tr),
                   get(v*2+1, m+1, r, tl, tr));
}

// update character at position 'pos' to new value 'val'
void update(int v, int l, int r, int pos, int val) {
    if (l == r) { // update leaf node
        st[v] = vector<bool>(26);
        st[v][val] = true;
    } else {
        int m = (l + r) / 2;
        if (pos <= m) update(v*2, l, m, pos, val);
        else update(v*2+1, m+1, r, pos, val);
        st[v] = combine(st[v*2], st[v*2+1]); // update parent node
    }
}

int main() {
    cin >> s;
    build(1, 0, s.size()-1); // build initial tree
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        b--;
        if (a == 1) { // update query
            char c;
            cin >> c;
            int x = (int)c - (int)'a';
            update(1, 0, s.size()-1, b, x);
        } else { // query distinct characters in substring
            int c;
            cin >> c;
            c--;
            auto v = get(1, 0, s.size()-1, b, c);
            int ans = 0;
            for (bool i : v) ans += i; // count distinct characters
            cout << ans << "\n";
        }
    }
}

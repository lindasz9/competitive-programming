#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 2e6 + 10;
const int maxn4 = maxn * 4;

int t[maxn4]; // segment tree: stores counts of active horizontal segments

// point update: add x at position k (activate/deactivate horizontal line)
void update(int v, int l, int r, int k, int x){
    if(l == r){
        t[v] += x; // update leaf
        return;
    }

    int m = (l + r) / 2;

    if(k <= m) update(v * 2, l, m, k, x);
    else update(v * 2 + 1, m + 1, r, k, x);

    // maintain sum in segment
    t[v] = t[v * 2] + t[v * 2 + 1];
}

// range sum query: count active horizontals in [ql, qr]
int sum(int v, int l, int r, int ql, int qr){
    // no overlap
    if(r < ql || l > qr) return 0;

    // full overlap
    if(ql <= l && r <= qr) return t[v];

    int m = (l + r) / 2;

    // partial overlap
    return sum(v * 2, l, m, ql, qr) +
           sum(v * 2 + 1, m + 1, r, ql, qr);
}

// event for sweep line
struct Event{
    int x;     // x-coordinate of event
    int type;  // 0 = vertical query, 1 = add horizontal, 2 = remove horizontal
    int y1, y2; // y or interval
};

signed main(){
    int n;
    cin >> n;

    vector<Event> e;

    for(int i = 0; i < n; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int z = 1e6 + 1; // shift to avoid negative coordinates
        a += z; b += z; c += z; d += z;

        if(a == c){
            // vertical segment
            if(b > d) swap(b, d);

            // query: count horizontals crossing [b, d] at x = a
            e.push_back({a, 0, b, d});
        }
        else{
            // horizontal segment
            if(a > c) swap(a, c);

            // add at left endpoint
            e.push_back({a, 1, b, 0});

            // remove at right endpoint
            e.push_back({c, 2, b, 0});
        }
    }

    // sort events by x, then by type (add before query before remove)
    sort(e.begin(), e.end(), [](Event a, Event b){
        if(a.x != b.x) return a.x < b.x;
        return a.type < b.type;
    });

    int ans = 0;

    // sweep line
    for(Event ev : e){
        int et = ev.type;

        if(et == 1){
            // activate horizontal line at y = y1
            update(1, 1, maxn, ev.y1, 1);
        }
        else if(et == 2){
            // deactivate horizontal line
            update(1, 1, maxn, ev.y1, -1);
        }
        else{
            // vertical segment: count intersections
            ans += sum(1, 1, maxn, ev.y1, ev.y2);
        }
    }

    cout << ans << '\n';
}

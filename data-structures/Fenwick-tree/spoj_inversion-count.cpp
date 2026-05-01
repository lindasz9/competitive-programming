#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxa = 1e7 + 1;
int ft[maxa]; // Fenwick Tree (Binary Indexed Tree)

// increases frequency at position l
void add(int l){
    for(int i = l; i < maxa; i += i & (-i))
        ft[i]++;
}

// returns sum of frequencies from 1 to x
int get(int x){
    int res = 0;
    for(int i = x; i > 0; i -= i & (-i))
        res += ft[i];
    return res;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        // reset Fenwick tree
        for(int i = 0; i < maxa; i++)
            ft[i] = 0;

        vector<int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        // reverse array to count inversions using BIT
        reverse(a.begin(), a.end());

        int ans = 0;

        for(int i = 0; i < n; i++){
            int x = a[i];

            // count how many elements smaller/equals have been seen
            ans += get(x);

            // insert current element into BIT
            add(x + 1);
        }

        cout << ans << '\n';
    }
}

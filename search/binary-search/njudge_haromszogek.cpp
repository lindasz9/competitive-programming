#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,q; cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end()); // előkészítés bináris kereséshez

    while(q--){
        int c,b; cin>>c>>b;
        // háromszögfeltétel: |b-c| < a[i] < b+c
        int l = upper_bound(a.begin(), a.end(), abs(c-b)) - a.begin(); // alsó határ
        int r = lower_bound(a.begin(), a.end(), c+b) - a.begin();      // felső határ
        cout << r-l << '\n'; // érvényes szakaszok száma
    }
}

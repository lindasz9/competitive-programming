#include <bits/stdc++.h>
using namespace std;

int n;
string s;

// adott karakterhez legnagyobb mutáns részszekvencia hossza
int solve(char c){
    int ans=0, cnt=0;
    vector<int> first(2*n+2,-1); // prefix különbségek első előfordulása
    for(int i=0;i<n;i++){
        if(s[i]==c) cnt++; else cnt--; // +1 ha c, -1 ha nem
        if(first[cnt+n]==-1){
            first[cnt+n]=i; // első előfordulás
        } else {
            ans=max(ans,i-first[cnt+n]); // hossz frissítése
        }
    }
    if(cnt>=0) return n; // egész string mutáns
    return ans;
}

int main(){
    cin>>s;
    n=s.size();
    int ans=max({solve('A'),solve('C'),solve('G'),solve('T')});
    cout<<ans<<'\n';
}

#include <bits/stdc++.h>
using namespace std;

set<pair<int,int>> memo;          // már látott állapotok (x, y)
queue<array<int,3>> q;            // BFS queue: {x, y, lépések száma}

// új állapot hozzáadása, ha még nem volt
void add(int a,int b,int cur){
    if(!memo.count({a,b})){
        memo.insert({a,b});
        q.push({a,b,cur});
    }
}

int main(){
    int a,b,c,l;
    cin>>a>>b>>c>>l;           // kannák méretei és kimérendő mennyiség
    
    q.push({a,0,0});           // kezdeti állapot: első kanna tele, másik kettő üres
    memo.insert({a,0});
    
    while(!q.empty()){
        auto [x,y,cur]=q.front(); q.pop();
        int z=a-x-y;            // harmadik kanna mennyisége
        if(x==l || y==l || z==l){
            cout<<cur<<'\n'; return 0; // megtaláltuk a célt
        }
        cur++;
        // minden lehetséges átöntés
        int d;
        d=min(x,b-y); add(x-d, y+d, cur);
        d=min(y,a-x); add(x+d, y-d, cur);
        d=min(x,c-z); add(x-d, y, cur);
        d=min(z,a-x); add(x+d, y, cur);
        d=min(y,c-z); add(x, y-d, cur);
        d=min(z,b-y); add(x, y+d, cur);
    }
    
    cout<<"-1\n"; // ha nem lehet kimérni
}

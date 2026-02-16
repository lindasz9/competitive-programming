#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int maxn=80;
ll dp[maxn][10][2][2]; // dp[pos][dig][tight][up]: pos pozícióban, dig az előző számjegy, tight: korlátozott-e a szám, up: növekedés szakaszban vagyunk-e
string s;
int n;

// rekurzív függvény a szivárványszámok számolására
ll cnt(int pos,int dig,bool tight,bool up){
    if(pos==n) return 1; // elértük a szám végét, érvényes szám
    if(dp[pos][dig][tight][up]!=-1) return dp[pos][dig][tight][up]; // memoizáció

    ll res=0;
    int lim=tight?s[pos]-'0':9; // ha tight, nem léphetünk túl az eredeti számjegyen
    for(int i=0;i<=lim;i++){
        if(i==dig) res+=cnt(pos+1,i,tight&&i==lim,up); // számjegy nem változik
        if(i>dig && up) res+=cnt(pos+1,i,tight&&i==lim,true); // növekvő szakaszban nagyobb számjegy
        if(i>dig && !up) continue; // csökkenő szakaszban nem lehet nagyobb
        if(i<dig) res+=cnt(pos+1,i,tight&&i==lim,false); // kisebb számjegy, csökkenő szakasz
    }
    return dp[pos][dig][tight][up]=res; // tárolás
}

int main(){
    cin>>s; // N beolvasása
    n=s.size();
    memset(dp,-1,sizeof(dp));
    bool yes=true,up=true; 
    int prev=s[0]-'0';
    for(int i=1;i<n;i++){ // ellenőrizzük, hogy maga a N szivárvány-e
        int x=s[i]-'0';
        if(x>prev && !up) yes=false; // ha a csökkenő szakasz után nő, már nem szivárvány
        if(x<prev) up=false; // csökkenő szakasz kezdete
        prev=x;
    }
    cout<<cnt(0,0,true,true)-yes<<'\n'; // kiírás, levonva N magát ha szivárvány
}

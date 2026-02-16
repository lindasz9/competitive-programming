#include <bits/stdc++.h>
using namespace std;

// kiírja a következő számot a balról/jobbról választás szerint
void next(bool& rr,int& l,int& r){
    if(rr){
        cout<<r<<' '; // jobb szélső
        r--;
    }else{
        cout<<l<<' '; // bal szélső
        l++;
    }
    rr^=1; // váltás a következőre
}

int main(){
    int n,k; cin>>n>>k; // N szám, K különböző medián
    int l=1,r=n; // aktuális bal és jobb szélső
    bool rr=true;
    for(int i=0;i<k-1;i++) next(rr,l,r); // előállítjuk a K-1 különböző mediánt
    cout<<(n+1)/2<<' '; // középső szám (új medián)
    for(int i=0;i<n-k;i++) next(rr,l,r); // a maradék számok kiírása
}

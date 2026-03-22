#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n; // járda hossza

    vector<int> a(n+1), b(n+1);
    a[0]=1; a[1]=2; // a[i]: összes lehetséges kikövezés i hosszra
    b[0]=0; b[1]=1; // b[i]: összes lehetséges kikövezés i hosszra + kilógó rész

    for(int i=2;i<=n;i++){
        b[i] = (a[i-1] + b[i-1] + a[i-2]) % 2023;  // kilógó rész frissítése
        a[i] = (b[i] + a[i-1] + a[i-2]*2 + b[i-1]*3) % 2023; // i hossz frissítése
    }

    cout<<a[n]<<'\n'; // kikövezések száma mod 2023
}

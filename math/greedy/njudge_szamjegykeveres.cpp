#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s; // kiinduló szám
    
    int n=s.size();
    int cnt=0;
    
    // megszámoljuk a 0-kat
    for(char c:s) 
        if(c=='0') cnt++;
    
    int plus=0;
    // speciális eset: az összes számjegy 0, kivéve az első, és első != 1
    if(cnt==n-1 && s[0]!='1')
        plus=(n-1)*9 + (s[0]-'0');
    
    int ans=0;
    // minden helyértékhez hozzáadjuk a maximális lépésigényű számjegyeket
    for(int i=1;i<n;i++) ans+=9*i;
    
    if(!plus)
        for(int i=0;i<n;i++) ans+=s[i]-'0'; // normál eset: összeadjuk a számjegyeket
    
    cout<<ans+plus<<'\n'; // minimális műveletszám
}

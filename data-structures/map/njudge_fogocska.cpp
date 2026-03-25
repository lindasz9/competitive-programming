#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<bool> fogo(n); // jelzi, hogy ki a fogó
    fogo[0] = true;       // az első játékos kezdetben fogó

    unordered_map<int,string> i2a; // index alapján név
    unordered_map<string,int> a2i; // név alapján index

    // játékosok beolvasása
    for(int i = 0; i < n; i++){
        string s; 
        cin >> s;
        a2i[s] = i;
        i2a[i] = s;
    }

    set<string> ans; // trollkodó diákok nevei

    // érintések feldolgozása
    while(m--){
        string s, t;
        cin >> s >> t;
        int si = a2i[s], ti = a2i[t];

        // ha s nem fogóként érintett, akkor trollkodott
        if(fogo[si] == false) ans.insert(s);

        // frissítjük a fogó státuszt
        fogo[ti] = true;  // a megérintett lesz fogó
        fogo[si] = false; // az érintő nem fogó többé
    }

    // eredmény kiírása
    cout << ans.size() << '\n';
    for(string s : ans) cout << s << ' ';
    cout << '\n';
}

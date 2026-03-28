#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    // ha csak 1 oszlop van, minden cella üres lesz
    if(m == 1){
        for(int i = 0; i < n; i++) cout << ".\n";
        return 0;
    }

    int nr = n % 3;
    int x = 0;
    if(nr == 0) x = 2; // sorok eltolása a mintázathoz

    if(m & 1){ // ha páratlan az oszlopszám
        for(int i = 0; i < n; i++){
            int r = (i + x) % 6; // ismétlődő 6 soros minta
            if(r == 0) // teljesen üres sor
                for(int j = 0; j < m; j++) cout << ".";
            else if(r == 3){ // fal az utolsó cellán
                for(int j = 1; j < m; j++) cout << ".";
                cout << "#";
            }
            else if(r == 1 || r == 5){ // váltakozó sor: .# .# ... .
                for(int j = 0; j < m/2; j++) cout << ".#";
                cout << ".";
            } else { // váltakozó sor: #. #. ... .
                for(int j = 0; j < m/2; j++) cout << "#.";
                cout << ".";
            }
            cout << '\n';
        }
    } else { // ha páros az oszlopszám
        for(int i = 0; i < n; i++){
            int r = (i + x) % 6; // ismétlődő 6 soros minta
            if(r == 0) // teljesen üres sor
                for(int j = 0; j < m; j++) cout << ".";
            else if(r == 3){ // fal az utolsó cellán
                for(int j = 1; j < m; j++) cout << ".";
                cout << "#";
            }
            else if(r == 2 || r == 4){ // váltakozó sor: .# .# ... ..
                for(int j = 1; j < m/2; j++) cout << ".#";
                cout << "..";
            } else // váltakozó sor: #. #. ... .
                for(int j = 0; j < m/2; j++) cout << "#.";
            cout << '\n';
        }
    }
}

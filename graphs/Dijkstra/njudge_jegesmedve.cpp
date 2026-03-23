#include <bits/stdc++.h>
using namespace std;

const int maxn = 101;

// 4 irány (fel, le, balra, jobbra)
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

// olv: olvadási hőmérséklet
// hal: halak száma
// d: adott mezőre eljutásnál a maximális minimális túlélési hőmérséklet
int olv[maxn][maxn], hal[maxn][maxn], d[maxn][maxn];

int main(){
    int n, m;
    cin >> n >> m;

    int jx, jy; // jegesmedve kezdőpozíciója

    // olvadási hőmérsékletek beolvasása
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            cin >> olv[i][j];
            if(olv[i][j] == -1){
                jx = i, jy = j; // kezdőpont
            }
        }

    // halak száma
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> hal[i][j];

    // s: prioritási sor (max-heap szimulálva negatív értékekkel)
    // {túlélési érték, x, y}
    set<array<int,3>> s;

    // kezdőpont: végtelen túlélési hőmérséklet
    s.insert({-INT_MAX, jx, jy});

    // Dijkstra-szerű feldolgozás:
    // minden mezőhöz megkeressük a legjobb (legkésőbb elolvadó) útvonalat
    while(!s.empty()){
        auto [dis, x, y] = *s.begin();
        dis *= -1; // visszaalakítás pozitívra
        s.erase(s.begin());

        for(auto [dx,dy] : dir){
            int xx = x + dx, yy = y + dy;

            // rácson kívül
            if(xx >= n || xx < 0 || yy >= m || yy < 0) continue;

            // ha még nem jártunk ott és nem azonnal olvad el
            if(d[xx][yy] == 0 && olv[xx][yy] > 0){
                // az út "értéke": a minimum az eddigi út és az új mező olvadása közül
                int mini = min(olv[xx][yy], dis);

                d[xx][yy] = mini; // eltároljuk
                s.insert({-mini, xx, yy});
            }
        }
    }

    // s2: mezők rendezve aszerint, meddig érhetők el
    // {elérhetőség napja, halak száma, id}
    set<array<int,3>> s2;

    int id = 0;

    // minden elérhető mező hozzáadása
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(d[i][j] > 0 && hal[i][j] > 0)
                s2.insert({d[i][j], hal[i][j], id++});
        }

    int ans = 0;
    int day = 1;

    // greedy: mindig a legkorábban eltűnő halakat esszük meg
    while(!s2.empty()){
        auto& [a, b, i] = *s2.begin();
        s2.erase(s2.begin());

        if(a < day) continue; // már nem érhető el ezen a napon

        else if(a > day && b > 1)
            s2.insert({a, b-1, i}); // marad még hal ezen a mezőn

        ans++;
        day++;
    }

    // végül hozzáadjuk a kezdőmező halait (ez mindig elérhető)
    cout << day + hal[jx][jy] << '\n';
}

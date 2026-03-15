#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

// a négy élszomszéd iránya (fel, le, balra, jobbra)
pii xy[4] = {{-1,0},{1,0},{0,-1},{0,1}};

const int maxn = 2001;

// mat: igaz, ha az adott mező járható ('.')
// a: Ádámtól elérhető mezők
// b: Beától elérhető mezők
bool mat[maxn][maxn], a[maxn][maxn], b[maxn][maxn];

// d: BFS távolság Ádám komponensétől
int d[maxn][maxn];

int n, m;

// BFS sor: (x, y, távolság)
queue<array<int,3>> q;

// DFS Ádám kezdőpontjától: meghatározza az összes mezőt,
// amely Ádámtól elérhető falak figyelembevételével
void dfsa(int x, int y) {
    a[x][y] = true;            // jelöljük, hogy Ádám eléri ezt a mezőt
    q.push({x, y, 0});         // BFS kezdőpontként betesszük a sorba
    d[x][y] = 0;               // távolság 0

    // bejárjuk a négy szomszédot
    for (auto [xx, yy] : xy) {
        int x2 = x + xx, y2 = y + yy;

        // ha kilépnénk a rácsból, kihagyjuk
        if (x2 >= n || x2 < 0 || y2 >= m || y2 < 0) continue;

        // ha járható és még nem jártunk ott DFS-ben
        if (mat[x2][y2] && a[x2][y2] == false) dfsa(x2, y2);
    }
}

// DFS Bea kezdőpontjától: meghatározza az összes mezőt,
// amely Beától elérhető
void dfsb(int x, int y) {
    b[x][y] = true;            // jelöljük, hogy Bea eléri ezt a mezőt

    // bejárjuk a négy szomszédot
    for (auto [xx, yy] : xy) {
        int x2 = x + xx, y2 = y + yy;

        // rácson kívülre nem léphetünk
        if (x2 >= n || x2 < 0 || y2 >= m || y2 < 0) continue;

        // ha járható és még nem látogattuk
        if (mat[x2][y2] && b[x2][y2] == false) dfsb(x2, y2);
    }
}

int main() {
    cin >> n >> m;

    pii sa, sb; // Ádám és Bea kezdőpozíciója

    // rács beolvasása
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char c; cin >> c;

            if (c == 'A') sa = {i, j};        // Ádám kezdőpontja
            else if (c == 'B') sb = {i, j};   // Bea kezdőpontja
            else if (c == '.') mat[i][j] = true; // üres mező
        }

    // távolságok inicializálása
    memset(d, -1, sizeof(d));

    // Ádám komponensének meghatározása
    dfsa(sa.first, sa.second);

    // Bea komponensének meghatározása
    dfsb(sb.first, sb.second);

    int ans = INT_MAX; // minimális Manhattan-távolság

    // BFS minden mezőre Ádám komponenséből kiindulva
    while (!q.empty()) {
        auto [x, y, dis] = q.front(); q.pop();

        // ha Bea is el tud jutni erre a mezőre,
        // akkor ez egy lehetséges találkozási pont
        if (b[x][y]) ans = min(ans, dis);

        // BFS terjesztése a négy irányba
        for (auto [xx, yy] : xy) {
            int x2 = x + xx, y2 = y + yy;

            // rácson kívülre nem mehetünk
            if (x2 >= n || x2 < 0 || y2 >= m || y2 < 0) continue;

            // ha még nem jártunk ott BFS-ben
            if (d[x2][y2] == -1) {
                d[x2][y2] = dis + 1;          // távolság növelése
                q.push({x2, y2, dis + 1});    // új mező hozzáadása a sorhoz
            }
        }
    }

    // kiírjuk a minimális elérhető Manhattan-távolságot
    cout << ans << '\n';
}

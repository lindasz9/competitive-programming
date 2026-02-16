#include <bits/stdc++.h>
using namespace std;

const int maxn=31;
int dp[maxn][maxn][maxn][maxn];       // memoization table
bool vis[maxn][maxn][maxn][maxn];     // visited states
int table[maxn][maxn];                 // pontértékek a rácsban

// Rekurzív megoldás: maximális előny az (a..b, c..d) téglalapból
int solve(int a,int b,int c,int d){
    if(a>b || c>d) return 0;           // üres téglalap
    if(vis[a][b][c][d]) return dp[a][b][c][d];
    vis[a][b][c][d]=true;
    
    int sum=0, best=INT_MIN;
    
    // felső sor választása
    for(int i=c;i<=d;i++) sum+=table[a][i];
    best=max(best, sum - solve(a+1,b,c,d));
    
    // alsó sor választása
    sum=0;
    for(int i=c;i<=d;i++) sum+=table[b][i];
    best=max(best, sum - solve(a,b-1,c,d));
    
    // baloszlop választása
    sum=0;
    for(int i=a;i<=b;i++) sum+=table[i][c];
    best=max(best, sum - solve(a,b,c+1,d));
    
    // jobboszlop választása
    sum=0;
    for(int i=a;i<=b;i++) sum+=table[i][d];
    best=max(best, sum - solve(a,b,c,d-1));
    
    return dp[a][b][c][d] = best;
}

int main(){
    int n,m;
    cin>>n>>m;
    
    int total=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin>>table[i][j];
            total+=table[i][j];
        }
    
    int advantage = solve(0,n-1,0,m-1); // maximális előny
    cout<<(total + advantage)/2<<'\n';    // játékos által elérhető maximális pont
}

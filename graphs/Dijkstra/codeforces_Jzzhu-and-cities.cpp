#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int INF = INT_MAX;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pii>> adj(n+1);

    // read roads between cities
    for (int i = 0; i < m; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        adj[u].push_back({v, x});
        adj[v].push_back({u, x});
    }

    // read train routes and keep the shortest one for each city
    vector<int> train(n+1, INF);
    for (int i = 0; i < k; i++) {
        int s, y;
        cin >> s >> y;
        train[s] = min(train[s], y);
    }

    // add train routes as edges from the capital
    for (int i = 2; i <= n; i++)
        if (train[i] != INF) adj[1].push_back({i, train[i]});

    vector<ll> d(n+1, INF); // shortest distances
    d[1] = 0;
    set<pii> q;
    q.insert({0, 1});
    vector<int> ways(n+1); // count of shortest paths to each city

    // Dijkstra's algorithm
    while (!q.empty()) {
        ll dv = q.begin()->first;
        int v = q.begin()->second;
        q.erase(q.begin());
        for (pii p : adj[v]) {
            int to = p.first;
            ll len = p.second;
            if (dv + len < d[to]) {
                q.erase({d[to], to});
                d[to] = dv + len;
                q.insert({d[to], to});
                ways[to] = 1; // new shortest path found
            } else if (dv + len == d[to]) ways[to]++; // another shortest path
        }
    }

    // count maximum train routes that can be closed
    int ans = k;
    for (int i = 2; i <= n; i++) {
        if (d[i] == train[i] && ways[i] == 1) ans--; // cannot close unique shortest train
    }

    cout << ans << endl;
}

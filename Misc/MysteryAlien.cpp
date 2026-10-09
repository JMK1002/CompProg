//
// Created by JMKov on 6/6/2024.
//
#include <iostream>
#include <set>

using namespace std;

const int INF = INT32_MAX;

int n, m;
set<pair<int, int>> adj[200004];
set<pair<int, int>> rev[200004];
int dist[200004];
int par[200004];
set<int> mn;

void djikstra(int v) {
    for (int i = 0; i < n; i++) dist[i] = INF;
    dist[v] = 0;
    par[v] = 0;
    mn.insert();
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].emplace(v, w);
        rev[v].emplace(u, w);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
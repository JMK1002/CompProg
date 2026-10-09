//
// Created by JMKov on 8/8/2024.
//
#include <iostream>
#include <set>

using namespace std;

int n;
set<int> adj[2003];
int par[2004];
pair<int, int> mx = {0,0};
pair<int, int> diam;

void dfs(int v, int p, int d) {
    par[v] = p;
    mx = max(mx, {d, v});
    for (int e : adj[v]) {
        if (e == p) continue;
        dfs(e, v, d + 1);
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    dfs(0, 0, 0);
    diam.first = mx.second;
    mx = {0, 0};
    dfs(diam.first, diam.first, 0);
    diam.second = mx.second;

    int p = diam.second;
    for (int i = 0; i < mx.first / 2; i++) {
        p = par[p];
    }

    if (mx.first % 2 == 0) {
        cout << mx.first / 2 + 1 << endl;
        for (int i = 0; i <= mx.first / 2; i++) cout << p + 1 << " " << i << endl;
    }
    else {
        int cnt = 0;
        for (int i = 1; i <= (mx.first + 1) / 2; i += 2) cnt += 2;
        cout << cnt << endl;
        for (int i = 1; i <= (mx.first + 1) / 2; i += 2) cout << p + 1 << " " << i << endl << par[p] + 1 << " " << i << endl;
    }

    for (int i = 0; i <= n; i++) {
        adj[i].clear();
        par[i] = 0;
    }
    mx = {0,0};
    diam = {0,0};
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
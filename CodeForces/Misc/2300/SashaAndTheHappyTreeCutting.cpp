//
// Created by JMKov on 8/13/2024.
//
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n, k;
int tin[100005];
int tout[100005];
pair<int, int> par[100005];
vector<pair<int, int>> adj[100005];
int asdf[100005];
set<int> s;
int dp[2000000];
int cnt = 0;

bool isAncestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

void dfs(int v, int p) {
    tin[v] = ++cnt;
    for (pair<int, int> e : adj[v]) {
        if (e.first == p) continue;
        cnt++;
        par[e.first] = {v, e.second};
        dfs(e.first, v);
    }
    tout[v] = ++cnt;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    dfs(0, 0);
    cin >> k;
    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        int lca = u;
        while (!isAncestor(lca, u) || !isAncestor(lca, v)) lca = par[lca].first;
        while (u != lca) {
            asdf[par[u].second] |= (1 << i);
            u = par[u].first;
        }
        while (v != lca) {
            asdf[par[v].second] |= (1 << i);
            v = par[v].first;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        s.insert(asdf[i]);
    }
    for (int i = 0; i < (1 << k); i++) dp[i] = 10000000;
    dp[0] = 0;
    for (int i = 0; i < (1 << k); i++) {
        for (int j : s) {
            dp[i | j] = min(dp[i | j], dp[i] + 1);
        }
    }
    cout << dp[(1 << k) - 1] << endl;

    for (int i = 0; i <= n; i++) {
        tin[i] = 0;
        tout[i] = 0;
        par[i] = {0, 0};
        adj[i].clear();
        asdf[i] = 0;
        dp[i] = 0;
    }
    s.clear();
    cnt = 0;
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
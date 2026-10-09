//
// Created by JMKov on 9/16/2024.
//
#include <iostream>
#include <set>
#include <vector>

using namespace std;

long long n, m, c;
set<long long> adj[305];
vector<long long> sizes;
vector<set<long long>> splitVals;
vector<set<pair<long long, long long>>> edges;
bool explored[305];
bool dp[305][305][2];
set<long long> explored2;
long long sz = 0;

void dfs2(long long v) {
    explored2.insert(v);
    for (long long e : adj[v]) {
        if (explored2.find(e) != explored2.end()) continue;
        dfs2(e);
    }
}

void dfs1(long long v) {
    sz++;
    explored[v] = true;
    for (long long e : adj[v]) {
        edges[sizes.size()].insert({min(e, v), max(e, v)});
        if (explored[e]) continue;
        dfs1(e);
    }
}

void solve() {
    cin >> n >> m >> c;
    for (long long i = 0; i < m; i++) {
        long long u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    for (long long i = 0; i < n; i++) {
        if (explored[i]) continue;
        edges.push_back({});
        dfs1(i);

        splitVals.push_back({});
        for (pair<long long, long long> p : edges[sizes.size()]) {
            long long e = p.first; long long v = p.second;
            adj[e].erase(v);
            adj[v].erase(e);
            dfs2(v);
            adj[e].insert(v);
            adj[v].insert(e);
            if (explored2.size() != sz) {
                splitVals[sizes.size()].insert(explored2.size());
                splitVals[sizes.size()].insert(sz - explored2.size());
            }
            explored2.clear();
        }

        sizes.push_back(sz);
        sz = 0;
    }
    dp[0][0][0] = true;
    for (long long i = 0; i < sizes.size(); i++) {
        for (long long j = 0; j <= n; j++) {
            dp[i + 1][j][0] |= dp[i][j][0];
            dp[i + 1][j][1] |= dp[i][j][1];
        }
        for (long long j = 0; j <= n - sizes[i]; j++) {
            dp[i + 1][j + sizes[i]][0] |= dp[i][j][0];
            dp[i + 1][j + sizes[i]][1] |= dp[i][j][1];
        }
        for (long long k : splitVals[i]) {
            for (long long j = 0; j <= n - k; j++) {
                dp[i + 1][j + k][1] |= dp[i][j][0];
            }
        }
    }
    long long mx = 0;
    for (long long i = 0; i <= n / 2; i++) {
        if (dp[sizes.size()][i][0] || dp[sizes.size()][i][1]) mx = i;
    }
    if (mx == 0) cout << -1 << endl;
    else cout << mx * mx + (n - mx) * (n - mx) + c * (sizes.size() - 1) << endl;

    for (long long i = 0; i <= sizes.size(); i++) {
        for (long long j = 0; j <= n; j++) {
            dp[i][j][0] = false;
            dp[i][j][1] = false;
        }
    }
    for (long long i = 0; i <= n; i++) {
        adj[i].clear();
        explored[i] = false;
    }
    sizes.clear();
    splitVals.clear();
    edges.clear();
    explored2.clear();
    sz = 0;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

// 2
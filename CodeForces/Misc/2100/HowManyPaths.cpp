//
// Created by JMKov on 7/29/2024.
//
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

long long n, m;
bool explored[400005];
long long ans[400005];
long long scc[400005];
set<long long> adj[400005];
set<long long> radj[400005];
set<long long> sccAdj[400005];
set<long long> rsccAdj[400005];
vector<long long> ord;
long long cnt = 0;

void dfs1(long long v) {
    explored[v] = true;
    for (long long e : adj[v]) {
        if (explored[e]) continue;
        dfs1(e);
    }
    ord.push_back(v);
}

void dfs2(long long v, long long id) {
    explored[v] = true;
    scc[v] = id;
    for (long long e : radj[v]) {
        if (explored[e]) continue;
        dfs2(e, id);
    }
}

void kosaraju() {
    for (long long i = 0; i < n; i++) explored[i] = false;
    for (long long i = 0; i < n; i++) if (!explored[i]) dfs1(i);
    for (long long i = 0; i < n; i++) explored[i] = false;
    reverse(ord.begin(), ord.end());
    for (long long i : ord) {
        if (!explored[i]) dfs2(i, cnt);
        cnt++;
    }
    for (long long i = 0; i < n; i++) {
        for (long long j : adj[i]) {
            sccAdj[scc[i]].insert(scc[j]);
            rsccAdj[scc[j]].insert(scc[i]);
        }
    }
}

void dfs3(long long v) {
    explored[v] = true;
    for (long long e : sccAdj[v]) {
        if (explored[e]) continue;
        dfs3(e);
    }
    ord.push_back(v);
}

void solve() {
    cin >> n >> m;
    for (long long i = 0; i < m; i++) {
        long long u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].insert(v);
        radj[v].insert(u);
    }
    kosaraju();
    ord.clear();
    for (long long i = 0; i < n; i++) explored[i] = false;
    for (long long i = 0; i < cnt; i++) if (!explored[i]) dfs3(i);
    reverse(ord.begin(), ord.end());
    ans[scc[0]] = 1;
    for (long long v : ord) {
        for (long long e : rsccAdj[v]) {
            if (min(ans[e], ans[v]) >= 0) {
                ans[v] += ans[e];
                ans[v] = min(ans[v], 2ll);
            }
            else ans[v] = -1;
        }
        if (ans[v] > 0 && sccAdj[v].find(v) != sccAdj[v].end()) ans[v] = -1;
    }
    for (long long i = 0; i < n; i++) {
        min(ans[scc[i]], 2ll);
        cout << min(ans[scc[i]], 2ll) << " ";
    }
    cout << endl;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
        for (long long i = 0; i <= n; i++) {
            explored[i] = false;
            ans[i] = 0;
            scc[i] = 0;
            adj[i].clear();
            radj[i].clear();
            sccAdj[i].clear();
            rsccAdj[i].clear();
        }
        ord.clear();
        cnt = 0;
    }
    return 0;
}
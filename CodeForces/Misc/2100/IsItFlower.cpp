//
// Created by JMKov on 7/11/2024.
//
#include <iostream>
#include <set>

using namespace std;

int n, m, pedals;
set<int> adj[200005];
bool middle[200005];
bool explored[200005];
set<int> cyc;

void clean() {
    cyc.clear();
    pedals = 0;
    for (int i = 0; i < n; i++) {
        middle[i] = false;
        explored[i] = false;
        adj[i].clear();
    }
}

void dfs(int v) {
    explored[v] = true;
    for (int e : adj[v]) {
        if (explored[e]) continue;
        dfs(e);
    }
}

void dfs(int v, bool b) {
    explored[v] = true;
    for (int e : adj[v]) {
        if (explored[e] || middle[e] != b) continue;
        dfs(e, b);
    }
}

bool validCycle(bool b) {
    for (int i : cyc) {
        int cnt = 0;
        for (int e : adj[i]) {
            cnt += cyc.find(e) != cyc.end();
        }
        if (cnt != 2) {
            return false;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) explored[i] = false;
    for (int i = 0; i < n; i++) {
        if (cyc.find(i) != cyc.end() && !explored[i]) {
            dfs(i, b);
            cnt++;
        }
    }
    if (cnt != 1) {
        return false;
    }
    if (cyc.size() != pedals) {
        return false;
    }
    return true;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    bool work = false;
    for (int i = 0; i * i <= n; i++) {
        if (i * i == n) {
            pedals = i;
            work = true;
        }
    }
    if (pedals * (pedals + 1) != m) work = false;
    if (!work) {
        cout << "NO" << endl;
        clean();
        return;
    }
    dfs(0);
    for (int i = 0; i < n; i++) {
        if (!explored[i]) {
            cout << "NO" << endl;
            clean();
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        if (adj[i].size() == 4) {
            middle[i] = true;
            cyc.insert(i);
        }
        else if (adj[i].size() != 2) {
            cout << "NO" << endl;
            clean();
            return;
        }
    }
    bool ans = validCycle(1);
    if (!ans) {
        cout << "NO" << endl;
        clean();
        return;
    }
    for (int i = 0; i < n; i++) {
        if (middle[i]) {
            middle[i] = false;
            for (int j = 0; j < n; j++) explored[j] = false;
            dfs(i, false);
            cyc.clear();
            for (int j = 0; j < n; j++) if (explored[j]) {
                cyc.insert(j);
            }
            ans = ans && validCycle(false);
            middle[i] = true;
        }
    }
    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;
    clean();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
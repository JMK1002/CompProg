//
// Created by JMKov on 5/7/2024.
//
#include <iostream>
#include <set>
#include <queue>

using namespace std;

set<int> adj[200004];
int p[200004];
int dst[200004];
bool ex[200004];
int rp[200004];

void dfs(int v, int cnt) {
    dst[v] = cnt;
    for (int e : adj[v]) {
        if (p[v] == e) continue;
        p[e] = v;
        dfs(e, cnt + 1);
    }
}

void checkL(int v) {
    
}

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        p[i] = -1;
        adj[i].clear();
        dst[i] = 0;
        ex[i] = false;
        rp[i] = -1;
    }

    int rt = 0;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    for (int i = 0; i < n; i++) if (adj[i].size() == 1) rt = i;

    dfs(rt, 1);

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
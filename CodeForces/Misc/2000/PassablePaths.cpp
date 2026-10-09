//
// Created by JMKov on 6/20/2024.
//
#include <iostream>
#include <set>

using namespace std;

int n;
set<int> adj[200005];

multiset<int> dfs(int v, int p) {
    multiset<int> suff
    for (int e : adj[v]) {
        if (e == p) continue;
        dfs(e, v);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    return 0;
}
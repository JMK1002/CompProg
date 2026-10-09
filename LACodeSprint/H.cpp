//
// Created by JMKov on 5/18/2024.
//
#include <iostream>
#include <set>

using namespace std;

set<int> adj[100004];
set<set<int>> cyc;

void fnd(int v) {
    set<int> explored;
    explored.insert(v);
    pair<int, int> nds;
    for (int i : adj[])
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }


    return 0;
}
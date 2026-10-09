//
// Created by JMKov on 5/18/2024.
//
#include <iostream>
#include <set>

using namespace std;

int col[200004];
int cnt[200004];
set<int> adj[200004];
int ans = 0;

void dfs(int v, int par) {
    ans += cnt[col[v]];
    int temp = cnt[col[v]];
    for (int edge : adj[v]) {
        if (edge == par) continue;
        cnt[col[v]] = 1;
        dfs(edge, v);
    }
    cnt[col[v]] = temp + 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> col[i];
            cnt[i] = 0;
            adj[i].clear();
        }

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].insert(v);
            adj[v].insert(u);
        }
        dfs(0, -1);
        cout << ans << endl;
    }
    return 0;
}
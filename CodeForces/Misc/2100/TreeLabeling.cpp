//
// Created by JMKov on 7/27/2024.
//
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> adj[200005];
int cnt[30];
bool act[200005];
int bipartite[2];
int ans[200005];
bool explored[200005];

void dfs(int v, int p) {
    act[v] = !act[p];
    bipartite[act[v]]++;
    for (int e : adj[v]) {
        if (e == p) continue;
        dfs(e, v);
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
//        if (i % 2 == 0) {
//            u = 0; v = i + 1;
//        }
//        else {
//            u = i; v = i + 1;
//        }
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        int x = i;
        int a = 0;
        while (x) {
            a++;
            x >>= 1;
        }
        cnt[a - 1]++;
    }
    dfs(0, 0);
    bool b = (bipartite[0] > bipartite[1]);
    int ptr = 1;
    for (int i = 0; i < n; i++) {
        int x = ptr;
        int a = 0;
        while (x) {
            a++;
            x >>= 1;
        }
        while (ptr <= n && !((1ll << (a - 1)) & bipartite[b])) {
            ptr++;
            x = ptr;
            a = 0;
            while (x) {
                a++;
                x >>= 1;
            }
        }
        if (ptr > n) break;

        if (act[i] == b) {
            ans[i] = ptr;
            explored[ptr] = true;
            ptr++;
        }
    }
    ptr = 1;
    for (int i = 0; i < n; i++) {
        while (explored[ptr]) ptr++;
        while (i <= n && ans[i]) i++;
        if (i > n) break;
        ans[i] = ptr;
        ptr++;
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
        for (int i = 0; i <= n; i++) {
            adj[i].clear();
            act[i] = false;
            ans[i] = 0;
            explored[i] = false;
        }
        for (int i = 0; i < 30; i++) cnt[i] = 0;
        bipartite[0] = 0;
        bipartite[1] = 0;
    }
    return 0;
}
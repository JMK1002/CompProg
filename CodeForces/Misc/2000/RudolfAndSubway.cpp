//
// Created by JMKov on 3/14/2024.
//
#include <iostream>
#include <set>
#include <queue>

using namespace std;

const int offset = 200001;
set<int> adj[400004];
bool explored[400004];
int inv[200005];

void solve() {
    int n, m, b, e;
    cin >> n >> m;
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--; v--;
//u = i; v = i + 1; c = i + 1;
        adj[offset + c].insert(u);
        adj[offset + c].insert(v);
        adj[u].insert(offset + c);
        adj[v].insert(offset + c);
        inv[cnt] = c;
        cnt++;
    }
    cin >> b >> e;
    b--; e--;
    queue<int> q;
    q.push(b);
    explored[b] = true;
    int dist = 0;
    int ans = -1;
    while (!q.empty() && ans == -1) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            int v = q.front();
            q.pop();
            if (v == e) ans = dist;
            for (int edge : adj[v]) {
                if (explored[edge]) continue;
                q.push(edge);
                explored[edge] = true;
            }
        }
        dist++;
    }
    cout << ans / 2 << endl;
    for (int i = 0; i < n; i++) {
        explored[i] = false;
        adj[i].clear();
    }
    for (int i = 0; i < m; i++) {
        explored[inv[i] + + offset] = false;
        adj[inv[i] + offset].clear();
    }
}

int main() {
    cin.tie();
    istream::sync_with_stdio(0);
    cout.tie();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
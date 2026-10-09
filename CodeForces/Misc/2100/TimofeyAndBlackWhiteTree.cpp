#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200200;
const int INF = 1e9;

int n, ANS = INF;
int crr[MAXN], dist[MAXN], res[MAXN];
bool clr[MAXN];
vector<int> gr[MAXN];

void init() {
    ANS = INF;
    for (int v = 0; v < n; ++v)
        gr[v].clear();
    fill(dist, dist + n, INF);
    memset(clr, 0, n);
}

void dfs(int v, int p) {
    if (dist[v] >= ANS) return;
    if (clr[v]) ANS = min(ANS, dist[v]);
    for (int u: gr[v]) {
        if (u == p) continue;
        if (dist[v] + 1 < dist[u]) {
            dist[u] = dist[v] + 1;
            dfs(u, v);
        } else ANS = min(ANS, dist[v] + 1 + dist[u]);
    }
}

void solve() {
    dist[*crr] = 0;
    dfs(*crr, -1);
    clr[*crr] = true;
    for (int i = 1; i < n; ++i) {
        dist[crr[i]] = 0;
        dfs(crr[i], -1);
        clr[crr[i]] = true;
        res[i] = ANS;
    }
}

int main() {
    int gorilla; cin >> gorilla;
    while (gorilla--) {
        cin >> n >> *crr, --(*crr);
        init();
        for (int i = 1; i < n; ++i)
            cin >> crr[i], --crr[i];
        for (int i = 1; i < n; ++i) {
            int v, u; cin >> v >> u, --v, --u;
            gr[v].push_back(u);
            gr[u].push_back(v);
        }
        solve();
        for (int i = 1; i < n; ++i)
            cout << res[i] << ' ';
        cout << '\n';
    }
}
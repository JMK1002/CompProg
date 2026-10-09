//
// Created by JMKov on 7/17/2024.
//
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int n;
string s;
vector<int> adj[2004];
int nxt[2005][2005];
vector<pair<int, pair<int, int>>> dist;
int dp[2005][2005];

void dfs(int v, int p, int og, int d) {
    dist.push_back({d, {og, v}});
    for (int e : adj[v]) {
        if (e == p) continue;
        dfs(e, v, og, d + 1);
        nxt[og][e] = v;
    }
}

void solve() {
    cin >> n >> s;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++) dfs(i, -1, i, 0);
    sort(dist.begin(), dist.end());
    for (pair<int, pair<int, int>> p : dist) {
        if (p.first == 0) dp[p.second.first][p.second.second] = 1;
        else if (p.first == 1 && s[p.second.first] == s[p.second.second]) dp[p.second.first][p.second.second] = 2;
        else {
            dp[p.second.first][p.second.second] = (s[p.second.first] == s[p.second.second]) *
                    (2 + dp[nxt[p.second.first][p.second.second]][nxt[p.second.second][p.second.first]]);
            dp[p.second.first][p.second.second] = max(dp[p.second.first][p.second.second],
                                                      max(dp[p.second.first][nxt[p.second.first][p.second.second]],
                                                      dp[nxt[p.second.second][p.second.first]][p.second.second]));
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) ans = max(ans, dp[i][j]);
    cout << ans << endl;

    for (int i = 0; i <= n; i++) {
        adj[i].clear();
        for (int j = 0; j <= n; j++) {
            nxt[i][j] = 0;
            dp[i][j] = 0;
        }
    }
    dist.clear();
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
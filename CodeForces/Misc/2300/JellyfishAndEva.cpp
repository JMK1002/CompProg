#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
long double dp[5005];
set<int> adj[5004];
bool explored[5004];
vector<long double> bollocks[2502];

void dfs(int v) {
    explored[v] = true;
    for (int e : adj[v]) {
        if (explored[e]) continue;
        dfs(e);
    }
    vector<double> asdf;
    for (int e : adj[v]) {
        asdf.push_back(dp[e]);
    }
    sort(asdf.begin(), asdf.end());
    reverse(asdf.begin(), asdf.end());
    if (asdf.size() % 2 == 1) {
        for (int i = 0; i < asdf.size(); i++) {
            dp[v] += asdf[i] * (1.0 / asdf.size());
        }
    }
    else {
        for (int i = 0; i < asdf.size(); i++) {
            dp[v] += asdf[i] * bollocks[asdf.size() / 2][i];
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].insert(v);
    }
    dp[n - 1] = 1;
    dfs(0);
    cout << dp[0] << endl;

    for (int i = 0; i <= n; i++) {
        dp[i] = 0;
        adj[i].clear();
        explored[i] = false;
    }
}

int main() {
    cout.precision(20);
    int t;
    cin >> t;

    bollocks[1] = {0.5, 0};
    for (int i = 2; i <= 2500; i++) {
        bollocks[i].push_back(1.0 / (i * 2));
        for (int j = 1; j < i * 2; j++) {
            bollocks[i].push_back(1.0 / (i * 2) * (bollocks[i - 1][j - 2] * (j - 1) + bollocks[i - 1][j - 1] * (i * 2 - 1 - j)));
        }
    }

    while (t--) {
        solve();
    }
    return 0;
}
// 1
// 1/2 0
// 1/3 1/3 1/3
// 1/4 1/4 1/8 0
// 1/5 1/5 1/5 1/5 1/5
// 1/6 1/6 1/6 1/8 1/16 0
// -1  0   1   2   3
// -1  4   3   2   1

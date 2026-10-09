//
// Created by JMKov on 3/2/2024.
//
#include <iostream>
#include <set>
using namespace std;

const long long mod = 998244353;

set<long long> adj[300004];
long long dp[300004];
bool explored[300004];

void dfs(long long v) {
    dp[v] = 1;
    explored[v] = true;
    for (long long e : adj[v]) {
        if (!explored[e]) {
            dfs(e);
            dp[v] *= dp[e] + 1;
            dp[v] %= mod;
        }
    }
}

void solve() {
    long long n;
    cin >> n;
    for (long long i = 0; i < n - 1; i++) {
        long long u,v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    dfs(0);
    long long s = 1;
    for (long long i = 0; i < n; i++) {
        s += dp[i];
        s %= mod;
    }
    cout << s << endl;
    for (long long i = 0; i < n; i++) {
        adj[i].clear();
        dp[i] = 0;
        explored[i] = false;
    }
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
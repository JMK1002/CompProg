#include <iostream>
#include <set>
#include <vector>
using namespace std;

const long long mod = 998244353;

long long n;
set<long long> adj[200005];
long long par[200005];
long long depth[200005];
long long mn[200005];
long long ans[200005];

void clean() {
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
        par[i] = 0;
        depth[i] = 0;
        mn[i] = 0;
        ans[i] = 0;
    }
}

long long inv(long long a) {
  return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

long long dfs(long long v, long long p) {
    par[v] = p;
    depth[v] = depth[p] + 1;
    for (long long e : adj[v]) {
        if (e == p) continue;
        mn[v] = min(mn[v], dfs(e, v));
    }
    if (adj[v].size() == 1) mn[v] = depth[v];
    return mn[v];
}

void dfs2(long long v, long long lst) {
    if (v != 0) {
        if (mn[par[v]] != mn[v]) lst = par[v];
        ans[v] = ans[par[v]] - inv(mn[v] - depth[lst]) * ans[lst] % mod;
        ans[v] += mod;
        ans[v] %= mod;
    }
    for (long long e : adj[v]) {
        if (e == par[v]) continue;
        dfs2(e, lst);
    }
}

void solve() {
    cin >> n;
    for (long long i = 0; i < n - 1; i++) {
        long long u, v;
        // u = i + 1; v = i + 2;
        cin >> u >> v;
        u--; v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    for (long long i = 0; i < n; i++) {
        mn[i] = __INT64_MAX__;
        ans[i] = -1;
    }
    ans[0] = 1;

    dfs(0, 0);
    dfs2(0, 0);
    for (long long i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
    clean();
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie(nullptr);
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
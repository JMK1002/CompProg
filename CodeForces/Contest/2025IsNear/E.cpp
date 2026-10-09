#include <iostream>
#include <set>
#include <vector>
using namespace std;

long long n;
set<long long> adj[200005];
long long dists[200005];
long long cnt[200005]; // * Counts the amount of "2" nodes in subtree
long long par[200005];
bool explored[200005];
vector<long long> leafs;
long long ans = 0;
long long tot = 0;

void dfs(long long v, long long p) {
    par[v] = p;
    for (long long e : adj[v]) {
        if (e == p) continue;
        dfs(e, v);
        cnt[v] += cnt[e];
    }
    cnt[v] += dists[v] == 2;
}

void dfs2(long long v) {
    if (dists[v] == 0 || explored[v]) return;
    explored[v] = true;
    for (long long e : adj[v]) {
        if (e == par[v]) {
            long long amnt = tot - cnt[v];
            if (dists[e] == 1) {
                ans += amnt;
            }
        }
        else {
            dfs2(e);
            if (dists[e] == 1) {
                ans += cnt[e];
            }
        }
    }
}

void solve() {
    cin >> n;
    for (long long i = 0; i < n - 1; i++) {
        long long u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    for (long long i = 0; i < n; i++) dists[i] = 2;
    for (long long i = 0; i < n; i++) {
        if (adj[i].size() == 1) {
            leafs.push_back(i);
            dists[i] = 0;
        }
    }
    for (long long l : leafs) {
        for (long long e : adj[l]) {
            dists[e] = min(dists[e], 1ll); 
        }
    }
    ans += leafs.size() * (n - leafs.size());
    dfs(0, 0);
    for (long long i = 0; i < n; i++) tot += dists[i] == 2;
    for (long long i = 0; i < n; i++) dfs2(i);

    cout << ans << endl;
    for (long long i = 0; i <= n; i++) {
        adj[i].clear();
        dists[i] = 0;
        cnt[i] = 0;
        par[i] = 0;
        explored[i] = false;
    }
    leafs.clear();
    ans = 0;
    tot = 0;
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
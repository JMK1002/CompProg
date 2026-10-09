//
// Created by JMKov on 5/28/2024.
//
#include <iostream>
#include <set>

using namespace std;

const long long mod = 998244353;

long long a[100004];
long long b[100004];
multiset<long long> adj[100004];
bool explored[100004];
long long ans = 1;
bool hasCycle = false;

void dfs(long long v, long long p) {
    explored[v] = true;
    long long pcnt = 0;
    for (long long e : adj[v]) {
        if (e == p) {
            pcnt++;
            continue;
        }
        if (explored[e]) {
            hasCycle = true;
            continue;
        }
        dfs(e, v);
    }
    if (pcnt > 1) hasCycle = true;
}

void solve() {
    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++) cin >> a[i];
    for (long long i = 0; i < n; i++) cin >> b[i];
    for (long long i = 0; i < n; i++) {
        adj[a[i]].insert(b[i]);
        adj[b[i]].insert(a[i]);
    }

    for (long long i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            explored[a[i]] = true;
            dfs(a[i], -1);
            ans *= n;
            ans %= mod;
        }
    }

    for (long long i = 1; i <= n; i++) {
        if (!explored[i]) {
            hasCycle = false;
            dfs(i, -1);
            if (!hasCycle) {
                ans = 0;
            }
            else {
                ans *= 2;
                ans %= mod;
            }
        }
    }
    cout << ans << endl;
    for (long long i = 0; i <= n; i++) {
        adj[i].clear();
        explored[i] = false;
    }
    ans = 1;
    hasCycle = false;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

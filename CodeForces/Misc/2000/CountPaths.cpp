//
// Created by JMKov on 5/18/2024.
//
#include <iostream>
#include <set>

using namespace std;

long long col[200004];
long long cnt[200004];
set<long long> adj[200004];
long long ans = 0;

void dfs(long long v, long long par) {
    ans += cnt[col[v]];
    long long temp = cnt[col[v]];
    for (long long edge : adj[v]) {
        if (edge == par) continue;
        cnt[col[v]] = 1;
        dfs(edge, v);
    }
    cnt[col[v]] = temp + 1;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        ans = 0;
        for (long long i = 0; i < n; i++) {
            cin >> col[i];
            cnt[i + 1] = 0;
            adj[i].clear();
        }

        for (long long i = 0; i < n - 1; i++) {
            long long u, v;
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
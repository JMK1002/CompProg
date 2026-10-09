//
// Created by JMKov on 12/8/2023.
//
#include <iostream>
#include <set>
#include <vector>
#include <cmath>

using namespace std;

long long group[100005];
set<long long> adj[100005];
long long last[100005];
long long mn[100005][2];
set<long long> check;

void dfs(long long v, long long groupInd) {
    group[v] = groupInd;
    for (long long node : adj[v]) {
        if (group[node] == 0) {
            dfs(node, groupInd);
        }
    }
}

void solve() {
    long long n, m;
    cin >> n >> m;
    check.clear();
    for (long long i = 0; i < n; i++) {
        group[i] = 0;
        adj[i].clear();
    }
    for (long long i = 0; i < m; i++) {
        long long u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    long long groupNum = 1;
    long long ind = 0;
    while (ind < n) {
        dfs(ind, groupNum);
        groupNum++;
        while (group[ind] != 0) ind++;
    }
    groupNum--; // its one indexed
    if (group[n - 1] == 1) {
        cout << 0 << endl;
        return;
    }

    for (long long i = 0; i < groupNum; i++) {
        last[i] = 0;
        mn[i][0] = INT32_MAX;
        mn[i][1] = INT32_MAX;
    }

    for (long long i = 0; i < n; i++) {
        if (group[i] == 1) {
            for (long long j : check) {
                mn[j][0] = min(mn[j][0], abs(i - last[j]));
            }
            check.clear();
        }
        else if (group[i] == group[n - 1]) {
            for (long long j : check) {
                mn[j][1] = min(mn[j][1], abs(i - last[j]));
            }
            check.clear();
        }
        check.insert(group[i] - 1);
        last[group[i] - 1] = i;
    }

    for (long long i = n - 1; i >= 0; i--) {
        if (group[i] == 1) {
            for (long long j : check) {
                mn[j][0] = min(mn[j][0], abs(i - last[j]));
            }
            check.clear();
        }
        else if (group[i] == group[n - 1]) {
            for (long long j : check) {
                mn[j][1] = min(mn[j][1], abs(i - last[j]));
            }
            check.clear();
        }
        check.insert(group[i] - 1);
        last[group[i] - 1] = i;
    }

    long long ans = INT64_MAX;
    for (long long i = 0; i < groupNum; i++) {
        ans = min(ans, mn[i][0] * mn[i][0] + mn[i][1] * mn[i][1]);
    }
    ans = min(ans, mn[0][1] * mn[0][1]);
    cout << ans << endl;
}

int main() {
    long long t;
    cin >> t;
    while (t--) solve();
    return 0;
}
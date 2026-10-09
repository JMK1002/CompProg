//
// Created by JMKov on 7/3/2024.
//
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

long long n, m;
long long arr[200004];
set<long long> adj[200004];
set<long long> radj[200004];
set<long long> compAdj[200004];
set<long long> rcompAdj[200004];
pair<long long, long long> compArr[200004];
bool explored[200004];
long long components[200004];
pair<long long, long long> dp[200004];
vector<long long> top;
long long cnt = 0;

void dfs1(long long v) {
    explored[v] = true;
    for (long long e : adj[v]) {
        if (explored[e]) continue;
        dfs1(e);
    }
    top.push_back(v);
}

void dfs2(long long v) {
    components[v] = cnt;
    for (long long e : radj[v]) {
        if (components[e] != -1) continue;
        dfs2(e);
    }
}

void kosaraju() {
    for (long long i = 0; i < n; i++) {
        if (explored[i]) continue;
        dfs1(i);
    }
    reverse(top.begin(), top.end());
    for (long long i = 0; i < n; i++) components[i] = -1;
    for (long long i : top) {
        if (components[i] != -1) continue;
        dfs2(i);
        cnt++;
    }
}

void clean() {
    for (long long i = 0; i <= n; i++) {
        arr[i] = 0;
        adj[i].clear();
        radj[i].clear();
        compAdj[i].clear();
        rcompAdj[i].clear();
        compArr[i] = {0, 0};
        explored[i] = false;
        components[i] = 0;
        dp[i] = {0, 0};
    }
    top.clear();
    cnt = 0;
}

void dfs3(long long v) {
    explored[v] = true;
    for (long long e : compAdj[v]) {
        if (explored[v]) continue;
        dfs3(e);
    }
    top.push_back(v);
}

void solve() {
    cin >> n >> m;
    for (long long i = 0; i < n; i++) cin >> arr[i];
    for (long long i = 0; i < m; i++) {
        long long u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].insert(v);
        radj[v].insert(u);
    }
    kosaraju();
    for (long long i = 0; i < n; i++) {
        compArr[components[i]].second += arr[i];
        compArr[components[i]].first++;
        for (long long e : adj[i]) {
            if (components[i] == components[e]) continue;
            compAdj[components[i]].insert(components[e]);
        }
        for (long long e : radj[i]) {
            if (components[i] == components[e]) continue;
            rcompAdj[components[i]].insert(components[e]);
        }
    }
    for (long long i = 0; i < n; i++) explored[i] = false;
    top.clear();
    for (long long i = 0; i < cnt; i++) {
        if (explored[i]) continue;
        dfs3(i);
    }
    for (long long i : top) {
        for (long long j : rcompAdj[i]) {
            if (dp[j].first > dp[i].first || (dp[j].first == dp[i].first && dp[j].second < dp[i].second)) {
                dp[i].first = dp[j].first;
                dp[i].second = dp[j].second;
            }
        }
        dp[i].first += compArr[i].first;
        dp[i].second += compArr[i].second;
    }
    pair<long long, long long> ans = {0, 0};
    for (long long i = 0; i < cnt; i++) {
        if (dp[i].first > ans.first || (dp[i].first == ans.first && dp[i].second < ans.second)) {
            ans.first = dp[i].first;
            ans.second = dp[i].second;
        }
    }
    cout << ans.first << " " << ans.second << endl;

    clean();
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
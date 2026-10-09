//
// Created by JMKov on 6/30/2024.
//
#include <iostream>
#include <set>
#include <queue>

using namespace std;

long long n;
set<long long> adj[5004];
long long arr[5004];
long long diff[5004];
long long par[5004];
long long ans = 0;

void findPars(long long v, long long p) {
    par[v] = p;
    for (long long e : adj[v]) {
        if (e == p) continue;
        findPars(e, v);
    }
    adj[v].erase(p);
}

void minOps(long long v, long long amnt) {
    queue<long long> q;
    long long cnt = 0;
    for (long long e : adj[v]) q.push(e);
    cnt += amnt;
    while (!q.empty() && amnt > 0) {
        long long sz = q.size();
        while (sz-- && amnt > 0) {
            long long u = q.front();
            if (diff[u] < 0) {
                int p = amnt;
                amnt += diff[u];
                amnt = max((long long) 0, amnt);
                diff[u] = min((long long) 0, diff[u] + p);
            }
            q.pop();
            for (long long e : adj[u]) {
                q.push(e);
            }
        }
        cnt += amnt;
    }
    ans += cnt;
    diff[v] = 0;
}

void dfs(long long v) {
    for (long long e : adj[v]) {
        dfs(e);
    }
    if (diff[v] > 0) minOps(v, diff[v]);
//    cout << v << " " << ans << endl;
}

void solve() {
    cin >> n;
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (long long i = 1; i < n; i++) {
        long long x;
        cin >> x;
        x--;
        adj[i].insert(x);
        adj[x].insert(i);
    }
    findPars(0, 0);
    for (long long i = 0; i < n; i++) {
        diff[i] = arr[i];
        for (long long e : adj[i]) {
            diff[i] -= arr[e];
        }
        if (adj[i].empty()) {
            diff[i] = INT64_MIN + 1000000; // TODO watch out for underflow
        }
    }
//    for (long long i = 0; i < n; i++) cout << diff[i] << " ";
//    cout << endl;
    dfs(0);
    cout << ans << endl;

    for (int i = 0; i <= n + 2; i++) {
        adj[i].clear();
        arr[i] = 0;
        diff[i] = 0;
        par[i] = 0;
    }
    ans = 0;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
//8
//1 -1 -3 0 0 0 0 0
//1 2 3 3 1 6 7
//
//7
//2 0 -2 0 0 0 0
//1 2 3 3 1 6
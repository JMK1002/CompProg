//
// Created by JMKov on 4/18/2024.
//
#include <iostream>
#include <set>

using namespace std;

const long long INF = INT64_MAX / 2;

long long n, m;
set<pair<long long, long long>> adj[1000004];
long long dist[1000004];
bool explored[1000004];

void dijk(long long v) {
    for (long long i = 0; i < n * n; i++) {
        dist[i] = INF;
        explored[i] = false;
    }
    dist[v * n] = 0;
    set<pair<long long, long long>> q;
    q.insert({dist[v], v});
    while (!q.empty()) {
        long long nv = (*q.begin()).second;
        q.erase(q.begin());
        explored[nv] = true;
        for (pair<long long, long long> ne : adj[nv]) {
            if (explored[ne.first]) continue;
            if (dist[ne.first] > dist[nv] + ne.second) {
                q.erase({dist[ne.first], ne.first});
                dist[ne.first] = dist[nv] + ne.second;
                q.insert({dist[ne.first], ne.first});
            }
        }
    }
}


void solve() {
    cin >> n >> m;
    set<pair<pair<long long, long long>, long long>> eg;
    for (long long i = 0; i < m; i++) {
        long long u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        eg.insert({{u, v}, w});
    }
    long long bk[n];
    for (long long i = 0; i < n; i++) cin >> bk[i];
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < n; j++) {
            if (j == i) continue;
            adj[i * n + j].insert({i * (n + 1), 0});
        }
    }
    for (pair<pair<long long, long long>, long long> p : eg) {
        for (long long j = 0; j < n; j++) {
            adj[p.first.first * n + j].insert({p.first.second * n + j, bk[j] * p.second});
            adj[p.first.second * n + j].insert({p.first.first * n + j, bk[j] * p.second});
        }
    }
    dijk(0);
    cout << dist[n * n - 1] << endl;

    for (long long i = 0; i < n * n; i++) adj[i].clear();
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
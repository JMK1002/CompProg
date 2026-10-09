//
// Created by JMKov on 7/26/2023.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <numeric>
#include <vector>
#include <queue>

using namespace std;

#define INF INT32_MAX

int dsu[2002];
set<pair<int, int>> connections[2002];

void dijkstra(int s, int n, int * d) {
    for (int i = 0; i < n; i++) d[i] = INF;
    d[s] = 0;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : connections[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                q.push({d[to], to});
            }
        }
    }
}

int find_root(int v) {
    if (dsu[v] == v) return v;
    dsu[v] = find_root(dsu[v]);
    return dsu[v];
}

void union_sets(int a, int b) {
    int ar = find_root(a);
    int br = find_root(b);
    if (ar == br) return;
    dsu[ar] = br;
}

bool solve() {
    int n;
    cin >> n;
    int arr[n][n];
    iota(dsu, dsu + 2002, 0);
    vector<pair<int, pair<int, int>>> dists;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (i == j) continue;
            dists.emplace_back(arr[i][j], *new pair<int, int>{i, j});
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i][j] != arr[j][i] || arr[i][j] <= 0) {
                return false;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i][i] != 0) {
            return false;
        }
    }
    sort(dists.begin(), dists.end());
    bool explored[n];
    for (bool & i : explored) i = false;
    int pos = 0;
    while (pos < dists.size()) {
        connections[dists[pos].second.first].emplace(dists[pos].second.second, dists[pos].first);
        connections[dists[pos].second.second].emplace(dists[pos].second.first, dists[pos].first);
        union_sets(dists[pos].second.second, dists[pos].second.first);
//        cout << dists[pos].second.second << " " << dists[pos].second.first << " " << dists[pos].first << endl;
        while (pos < dists.size() && find_root(dists[pos].second.first) == find_root(dists[pos].second.second)) pos++;
    }
    for (int i = 0; i < n; i++) {
        int dist[n];
        dijkstra(i, n, dist);
        for (int j = 0; j < n; j++) {
            if (arr[i][j] != dist[j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    cout << ((solve()) ? "YES" : "NO") << endl;
}
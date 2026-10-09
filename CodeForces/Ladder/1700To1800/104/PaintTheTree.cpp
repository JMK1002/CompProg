//
// Created by JMKov on 7/16/2023.
//
#include <iostream>
#include <set>
using namespace std;

long long calcCost(long long start, const long long * pat, long long n, const long long * path, long long ** costs) {
    long long ret = 0;
    long long index = 0;
    long long v = start;
//    for (long long i = 0; i < 3; i++) cout << pat[i] << " ";
//    cout << ": ";
    while (v != -1) {
        ret += costs[v][pat[index]];
//        cout << costs[v][pat[index]] << " ";
        index++;
        index %= 3;
        v = path[v];
    }
//    cout << endl;
    return ret;
}

int main() {
    long long n;
    cin >> n;
    set<long long> connections[n];
    long long ** costs;
    costs = new long long * [n];
    for (long long i = 0; i < n; i++) costs[i] = new long long[3];
    long long edges[n];
    for (long long & edge : edges) edge = 0;
    for (long long j = 0; j < 3; j++) for (long long i = 0; i < n; i++) cin >> costs[i][j];
    for (long long i = 0; i < n - 1; i++) {
        long long u, v;
        cin >> u >> v;
        u--; v--;
        connections[u].insert(v);
        connections[v].insert(u);
        edges[u]++; edges[v]++;
        if (edges[u] >= 3 || edges[v] >= 3) {
            cout << -1 << endl;
            return 0;
        }
    }
    long long start = -1;
    for (long long i = 0; i < n; i++) if (edges[i] == 1) {
        start = i;
        break;
    }
    long long path[n];
    for (long long i = 0; i < n; i++) path[i] = -1;
    path[start] = *(connections[start].begin());
    long long v = start;
    while (path[v] != -1) {
        for (long long edge : connections[path[v]]) {
            if (edge == v) continue;
            path[path[v]] = edge;
            break;
        }
        v = path[v];
    }
//    for (long long i : path) cout << i << " ";
//    cout << endl;
    long long ans = INT64_MAX;
    long long bestPat[3];
    for (long long i = 0; i < 3; i++) {
        for (long long j = 0; j < 3; j++) {
            if (i == j) continue;
            long long pat[3]{i, j, 3 - i - j};
            long long cost = calcCost(start, pat, n, path, costs);
            if (cost < ans) {
                ans = cost;
                for (long long k = 0; k < 3; k++) bestPat[k] = pat[k];
            }
        }
    }
    cout << ans << endl;
    long long ansArr[n];
    long long index = 0;
    v = start;
    while (v != -1) {
        ansArr[v] = bestPat[index];
        index++;
        index %= 3;
        v = path[v];
    }
//    for (long long i : bestPat) cout << i << " ";
//    cout << endl;
    for (long long i : ansArr) cout << i + 1 << " ";
    cout << endl;
//    cout << endl;
    return 0;
}
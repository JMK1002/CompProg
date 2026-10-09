//
// Created by JMKov on 7/19/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

long long parent[200010];
long long sz[200010];
long long ans[200010];
long long currAns = 0;

void build_set(long long v) {
    parent[v] = v;
    sz[v] = 1;
}

long long find_set(long long v) {
    if (parent[v] == v) {
        return v;
    }
    parent[v] = find_set(parent[v]);
    return parent[v];
}

void union_set(long long a, long long b) {
    long long ap = find_set(a);
    long long bp = find_set(b);
    if (ap == bp) return;
    if (sz[ap] < sz[bp]) {
        parent[ap] = bp;
        currAns -= sz[ap] * (sz[ap] - 1) / 2;
        currAns -= sz[bp] * (sz[bp] - 1) / 2;
        sz[bp] += sz[ap];
        currAns += sz[bp] * (sz[bp] - 1) / 2;
        sz[ap] = 0;
    }
    else {
        parent[bp] = ap;
        currAns -= sz[ap] * (sz[ap] - 1) / 2;
        currAns -= sz[bp] * (sz[bp] - 1) / 2;
        sz[ap] += sz[bp];
        currAns += sz[ap] * (sz[ap] - 1) / 2;
        sz[bp] = 0;
    }
}

int main() {
    long long n, m;
    cin >> n >> m;
    vector<pair<long long, pair<long long, long long>>> edges;
    for (long long i = 0; i < n - 1; i++) {
        long long u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        edges.emplace_back(w, *new pair<long long, long long>(u, v));
    }
    sort(edges.begin(), edges.end());
    long long arr[m];
    for (long long i = 0; i < m; i++) cin >> arr[i];
    for (long long i = 0; i < n; i++) {
        build_set(i);
    }
    long long pos = 0;
    ans[0] = n;
    for (long long i = 1; i < 200001; i++) {
//        for (long long j = 0; j < n; j++) cout << sz[j] << " ";
//        cout << endl;
//        cout << currAns << endl;
        while (pos < edges.size() && edges[pos].first == i) {
            union_set(edges[pos].second.first, edges[pos].second.second);
            pos++;
        }
        ans[i] = currAns;
    }
    for (long long i : arr) cout << ans[i] << " ";
    cout << endl;
    return 0;
}
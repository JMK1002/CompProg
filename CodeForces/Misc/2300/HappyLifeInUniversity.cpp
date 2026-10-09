//
// Created by JMKov on 9/1/2024.
//
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

long long n;
long long par[300005];
long long arr[300005];
set<long long> adj[300005];
vector<long long> topo;
long long topoInd[300005];
long long sz[300005];
long long temp[300005];
long long last[300005];
set<long long> subtracts[300005];
long long t[3000000]; // ! max segtree
long long lazy[3000000];

void push(long long v) {
    t[v] += lazy[v];
    lazy[v * 2] += lazy[v];
    lazy[v * 2 + 1] += lazy[v];
    lazy[v] = 0;
}

void reset(long long v, long long l, long long r) {
    if (l > r) return;
    else if (l == r) {
        t[v] = 0;
        lazy[v] = 0;
    }
    else {
        long long m = (l + r) / 2;
        reset(v * 2, l, m);
        reset(v * 2 + 1, m + 1, r);
        t[v] = 0;
        lazy[v] = 0;
    }
}

long long query(long long v, long long l, long long r, long long tl, long long tr) {
    push(v);
    if (l > r || tl > tr || tl < l || tr > r) return 0;
    else if (tl == l && tr == r) {
        return t[v];
    }
    else {
        long long m = (l + r) / 2;
        long long a = query(v * 2, l, m, tl, min(tr, m));
        long long b = query(v * 2 + 1, m + 1, r, max(tl, m + 1), tr);
        return max(a, b);
    }
}

void add(long long v, long long l, long long r, long long tl, long long tr, long long amnt) {
    push(v);
    if (l > r || tl > tr || tl < l || tr > r) return;
    else if (tl == l && tr == r) {
        lazy[v] += amnt;
        push(v);
    }
    else {
        long long m = (l + r) / 2;
        add(v * 2, l, m, tl, min(tr, m), amnt);
        add(v * 2 + 1, m + 1, r, max(tl, m + 1), tr, amnt);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
}

void addToSubtree(long long v, long long amnt) {
    add(1, 1, n, topoInd[v] + 1, topoInd[v] + sz[v], amnt);
}

long long getSubtreeMax(long long v) {
    return query(1, 1, n, topoInd[v] + 1, topoInd[v] + sz[v]);
}

void dfs1(long long v) {
    sz[v] = 1;
    long long prev = temp[arr[v]];
    temp[arr[v]] = v;

    for (long long e : adj[v]) {
        dfs1(e);
        sz[v] += sz[e];
    }

    temp[arr[v]] = prev;
    last[v] = prev;
    topo.push_back(v);
}

long long dfs2(long long v) {
    long long best = 0;
    for (long long e : adj[v]) best = max(best, dfs2(e));
    addToSubtree(v, 1);
    for (long long e : subtracts[v]) addToSubtree(e, -1);
    // cout << v << " ";
    // for (long long e : adj[v]) cout << getSubtreeMax(e) << " ";
    // cout << endl;
    vector<long long> vals;
    vals.push_back(1);
    vals.push_back(1);
    for (long long e : adj[v]) vals.push_back(getSubtreeMax(e));
    sort(vals.begin(), vals.end());
    reverse(vals.begin(), vals.end());
    return max(best, vals[0] * vals[1]);
}

void solve() {
    cin >> n;
    reset(1, 1, n);
    for (long long i = 0; i <= n; i++) {
        arr[i] = 0;
        par[i] = 0;
        adj[i].clear();
        topoInd[i] = 0;
        sz[i] = 0;
        temp[i] = 0;
        last[i] = 0;
        subtracts[i].clear();
    }
    topo.clear();
    for (long long i = 1; i < n; i++) {
        cin >> par[i];
        par[i]--;
    }
    for (long long i = 1; i < n; i++) adj[par[i]].insert(i);
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i]--;
    }
    for (long long i = 0; i < n; i++) temp[i] = -1;
    dfs1(0);
    reverse(topo.begin(), topo.end());
    for (long long i = 0; i < n; i++) topoInd[topo[i]] = i;
    for (long long i = 0; i < n; i++) {
        if (last[i] == -1) continue;
        subtracts[last[i]].insert(i);
    }
    cout << dfs2(0) << endl;
    // add(1, 1, n, 1, 3, 2);
    // add(1, 1, n, 3, 4, 1);
    // cout << query(1, 1, n, 3, 5) << endl;
    // for (long long i : topo) cout << i << " ";
    // cout << endl;
    // for (long long i = 0; i < n; i++) cout << topoInd[i] << " ";
    // cout << endl;
    // for (long long i = 0; i < n; i++) cout << sz[i] << " ";
    // cout << endl;

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
//
// Created by JMKov on 5/20/2024.
//
#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<pair<long long, pair<long long, long long>>> queries;
vector<set<long long>> adj;
vector<long long> arr;
long long arrInd[500001];
long long rangeEnd[500001];
long long t[2000001];
long long lazy[2000001];

void bump(long long v) {
    lazy[v * 2] += lazy[v];
    lazy[v * 2 + 1] += lazy[v];
    lazy[v] = 0;
}

void build(long long l, long long r, long long v) {
    if (l > r) return;
    else if (l == r) {
        t[v] = arr[l];
    }
    else {
        long long m = (l + r) / 2;
        build(l, m, v * 2);
        build(m + 1, r, v * 2 + 1);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

void add(long long l, long long r, long long tl, long long tr, long long v, long long x) {
    if (tl > tr || l > r) return;
    if (l == tl && r == tr) {
        lazy[v] += x;
    }
    else {
        bump(v);
        long long m = (tl + tr) / 2;
        add(l, min(m, r), tl, m, v * 2, x);
        add(max(m + 1, l), r, m + 1, tr, v * 2 + 1, x);
    }
}

long long get(long long tl, long long tr, long long ind, long long v) {
    if (tl > ind || tr < ind || tl > tr) return 0;
    else if (tl == tr) {
        return arr[ind] + lazy[v];
    }
    else {
        bump(v);
        long long m = (tl + tr) / 2;
        return get(tl, m, ind, v * 2)
            + get(m + 1, tr, ind, v * 2 + 1);
    }
}

void get(long long l, long long r, long long v) {
    if (l > r) return;
    else if (l == r) {
        arr[l] += lazy[v];
        lazy[v] = 0;
    }
    else {
        bump(v);
        long long m = (l + r) / 2;
        get(l, m, v * 2);
        get(m + 1, r, v * 2 + 1);
    }
}

void dfs(long long v) {
    long long x = arr.size();
    for (long long edge : adj[v]) {
        dfs(edge);
    }
    arr.push_back(0);
    arrInd[v] = arr.size() - 1;
    rangeEnd[v] = x;
}

void solve() {
    long long q;
    cin >> q;
    adj.push_back({});
    for (long long i = 0; i < q; i++) {
        long long x;
        cin >> x;
        if (x == 1) {
            long long a;
            cin >> a;
            a--;
            queries.push_back({x, {a, -1}});
            adj.push_back({});
            adj[a].insert(adj.size() - 1);
        }
        else {
            long long a, b;
            cin >> a >> b;
            a--;
            queries.push_back({x, {a, b}});
        }
    }

    dfs(0);
//    for (long long i : arr) cout << i << " ";
//    cout << endl;

    long long n = arr.size();
    long long cnt = 1;
    build(0, n - 1, 1);
    for (long long i = 0; i < q; i++) {
        if (queries[i].first == 1) {
            if (queries[i].second.first != cnt) {
                add(rangeEnd[cnt], arrInd[cnt], 0, n - 1, 1, -1 * get(0, n - 1, arrInd[queries[i].second.first], 1));
            }
            cnt++;
        }
        else {
            add(rangeEnd[queries[i].second.first], arrInd[queries[i].second.first], 0, n - 1, 1, queries[i].second.second);
        }
    }

    get(0, n - 1, 1);
    for (long long i = 0; i < arr.size(); i++) {
        cout << arr[arrInd[i]] << " ";
    }
    cout << endl;

    for (long long i = 0; i < arr.size(); i++) {
        arrInd[i] = 0;
        rangeEnd[i] = 0;
    }
    for (long long i = 0; i < arr.size() * 4; i++) {
        t[i] = 0;
        lazy[i] = 0;
    }
    queries.clear();
    adj.clear();
    arr.clear();
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
//1
//5
//1 1
//2 1 3
//1 1
//2 3 1
//1 3
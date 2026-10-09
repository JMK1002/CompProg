//
// Created by JMKov on 6/25/2024.
//
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

long long n, m, q;
long long arr[300004];
set<pair<long long, long long>> curr;
long long t[2400032];
pair<long long, long long> lazy[2400032];

void propogate(long long v, int a, int b) {
    pair<long long, long long> amnt = lazy[v];
    t[v] += a * (a - 1) / 2 * amnt.second + amnt.first * a;
    lazy[v * 2] = {lazy[v * 2].first + amnt.first + amnt.second * b, lazy[v * 2].second + amnt.second};
    lazy[v * 2 + 1] = {lazy[v * 2 + 1].first + amnt.first, lazy[v * 2 + 1].second + amnt.second};
    lazy[v] = {0, 0};
}

void build(long long tl, long long tr, long long v) {
    if (tl > tr) return;
    else if (tl == tr) {
        t[v] = arr[tl];
    }
    else {
        long long tm = (tl + tr) / 2;
        build(tl, tm, v * 2);
        build(tm + 1, tr, v * 2 + 1);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

void add(long long tl, long long tr, long long v, long long l, long long r, pair<long long, long long> amnt) {
    if (tl > tr || r < tl || l > tr) return;
    else if (tl == l && tr == r) {
        lazy[v].first += amnt.first;
        lazy[v].second += amnt.second;
    }
    else {
        long long tm = (tl + tr) / 2;
        add(tl, tm, v * 2, l, min(tm, r), {amnt.first + amnt.second * max((long long) 0, (r - max(tm + 1, l) + 1)), amnt.second});
        add(tm + 1, tr, v * 2 + 1, max(tm + 1, l), r, amnt);
    }
}

long long get(long long tl, long long tr, long long v, long long l, long long r) {
    if (tl > r || tr < l || tl > tr) return 0;
    else if (tl == l && tr == r) {
        long long tm = (tl + tr) / 2;
        propogate(v, r - l + 1, max((long long) 0, r - max(tm + 1, l) + 1));
        return t[v];
    }
    else {
        if (tr - tl <= 2) {
            cout << "SDF" << endl;
        }
        long long tm = (tl + tr) / 2;
        propogate(v, r - l + 1, max((long long) 0, r - max(tm + 1, l) + 1));
        return get(tl, tm, v * 2, l, min(tm, r)) +
                get(tm + 1, tr, v * 2 + 1, max(tm + 1, l), r);
    }
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    cin >> n >> m >> q;
    pair<long long, long long> input[n];
    for (long long i = 0; i < m; i++) {
        cin >> input[i].first;
    }
    for (long long i = 0; i < m; i++) {
        cin >> input[i].second;
        curr.insert(input[i]);
    }
    auto ptr1 = curr.begin();
    auto ptr2 = curr.begin();
    ptr2++;
    while (ptr2 != curr.end()) {
        pair<long long, long long> p1 = *ptr1;
        pair<long long, long long> p2 = *ptr2;
        for (long long i = p1.first + 1; i <= p2.first; i++) {
            arr[i] = (p2.first - i) * p1.second;
        }
        ptr1++;
        ptr2++;
    }
    build(1, n, 1);
    while (q--) {
        long long x, u, v;
        cin >> x >> u >> v;
        if (x == 1) {
            pair<long long, long long> prev = *(--curr.lower_bound({u, v}));
            pair<long long, long long> nxt = *curr.lower_bound({u, v});
            add(0, n, 1, u + 1, nxt.first, {0, v - prev.second});
            add(0, n, 1, prev.first + 1, u, {0 - (nxt.first - u) * prev.second, 0});
            cout << get(1, n, 1, u - 1, u + 1) << endl;
            curr.insert({u, v});
        }
        else {
            cout << get(1, n, 1, u, v) << endl;
//            for (long long i = 0; i < n; i++) get(1, n, 1, i, i);
        }
    }
    return 0;
}
//300000 2 2
//1 300000
//1366679 1600056
//1 136516 7785717
//2 41265 165241

//446858932593
//446858932593
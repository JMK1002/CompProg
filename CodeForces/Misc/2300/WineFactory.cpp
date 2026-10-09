//
// Created by JMKov on 8/31/2024.
//
#include <iostream>
using namespace std;

long long n, q;
long long asdf[500005];
long long val[500005]; // a[i] - b[i]
long long pre[500005];
long long t[4000040];
long long lazy[4000040];

void propogate(long long v) {
    lazy[v * 2] += lazy[v];
    lazy[v * 2 + 1] += lazy[v];
    t[v] += lazy[v];
    lazy[v] = 0;
}

void build(long long l, long long r, long long v) {
    if (l > r) return;
    else if (l == r) {
        t[v] = pre[l];
    }
    else {
        long long mid = (l + r) / 2;
        build(l, mid, v * 2);
        build(mid + 1, r, v * 2 + 1);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
}

//long long get(long long l, long long r, long long v, long long ind) {
//    if (l > r || l > ind || r < ind) return 0;
//    else if (l == r) {
//        propogate(v);
//        return t[v];
//    }
//    else {
//        propogate(v);
//        long long mid = (l + r) / 2;
//        return max(get(l, mid, v * 2, ind), get(mid + 1, r, v * 2 + 1, ind));
//    }
//}

void add(long long tl, long long tr, long long v, long long l, long long r, long long amnt) {
    if (tl > tr || l > r) return;
    else if (tl == l && tr == r) {
        lazy[v] += amnt;
        propogate(v);
    }
    else {
        propogate(v);
        long long mid = (tl + tr) / 2;
        add(tl, mid, v * 2, l, min(mid, r), amnt);
        add(mid + 1, tr, v * 2 + 1, max(mid + 1, l), r, amnt);
        propogate(v * 2);
        propogate(v * 2 + 1);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> q;
    long long s = 0;
    for (long long i = 0; i < n; i++) {
        cin >> val[i];
        asdf[i] = val[i];
        s += asdf[i];
    }
    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        val[i] -= x;
    }
    for (long long i = 0; i < n - 1; i++) {
        long long x;
        cin >> x;
    }
    for (long long i = n - 1; i >= 0; i--) {
        pre[i] = val[i] + pre[i + 1];
    }
    build(0, n - 1, 1);
    while (q--) {
        long long i, a, b, c;
        cin >> i >> a >> b >> c;
        i--;
        long long dv = (a - b) - val[i];
        val[i] += dv;
        add(0, n - 1, 1, 0, i, dv);
        s += a - asdf[i];
        asdf[i] = a;
        cout << s - max(0ll, t[1]) << endl;
    }
    return 0;
}
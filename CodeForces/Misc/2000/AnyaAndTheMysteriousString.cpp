//
// Created by JMKov on 5/21/2024.
//
#include <iostream>
#include <set>

using namespace std;

long long n, m;
string s;
set<long long> inds[2];
bool works[200002][2];
long long arr[200002];
long long t[800008];
long long lazy[800008];

void push(long long v) {
    lazy[v * 2] += lazy[v];
    lazy[v * 2 + 1] += lazy[v];
    lazy[v] = 0;
}

void build(long long tl, long long tr, long long v) {
    if (tl > tr) return;
    else if (tl == tr) {
        t[v] = arr[tl];
    }
    else {
        long long mid = (tl + tr) / 2;
        build(tl, mid, v * 2);
        build(mid + 1, tr, v * 2 + 1);
    }
}

void add(long long tl, long long tr, long long l, long long r, long long v, long long x) {
    if (tl > tr || l > r) return;
    else if (tl == l && tr == r) {
        lazy[v] += x;
    }
    else {
        push(v);
        long long mid = (tl + tr) / 2;
        add(tl, mid, l, min(mid, r), v * 2, x);
        add(mid + 1, tr, max(l, mid + 1), r, v * 2 + 1, x);
    }
}

long long get(long long tl, long long tr, long long ind, long long v) {
    if (tl > tr || tl > ind || tr < ind) return 0;
    else if (tl == tr) {
        arr[ind] += lazy[v];
        arr[ind] %= 26;
        lazy[v] = 0;
        return arr[ind];
    }
    else {
        push(v);
        long long mid = (tl + tr) / 2;
        return get(tl, mid, ind, v * 2) +
            get(mid + 1, tr, ind, v * 2 + 1);
    }
}

void replace(long long i1, bool b) {
    if (i1 + 1 + b >= n || i1 < 0) return;
    if (works[i1][b]) {
        inds[b].erase(i1);
        works[i1][b] = false;
    }
    long long a = get(0, n - 1, i1, 1);
    long long c = get(0, n - 1, i1 + 1 + b, 1);
//    cout << a << " " << c << endl;
    if (a == c) {
        works[i1][b] = true;
        inds[b].insert(i1);
    }
}


void q1(long long l, long long r, long long x) {
    add(0, n - 1, l, r, 1, x);
    replace(l - 1, false);
    replace(l - 1, true);
    replace(l - 2, true);
    replace(r, false);
    replace(r, true);
    replace(r - 1, true);
}

bool q2(long long l, long long r) {
    return inds[0].lower_bound(l) != inds[0].lower_bound(r) && (r - l >= 1) ||
        inds[1].lower_bound(l) != inds[1].lower_bound(r - 1) && (r - l >= 2);
}

void solve() {
    cin >> n >> m >> s;
    for (long long i = 0; i < n; i++) arr[i] = s[i] - 'a';
    for (long long i = 0; i < n - 2; i++) {
        works[i][0] = (arr[i] == arr[i + 1]);
        works[i][1] = (arr[i] == arr[i + 2]);
    }
    if (n > 1) works[n - 2][0] = arr[n - 2] == arr[n - 1];

    for (long long i = 0; i < n; i++) {
        if (works[i][0]) inds[0].insert(i);
        if (works[i][1]) inds[1].insert(i);
    }

    build(0, n - 1, 1);
    for (long long i = 0; i < m; i++) {
        long long u;
        cin >> u;
        if (u == 1) {
            long long a, b, c;
            cin >> a >> b >> c;
            a--; b--;
            q1(a, b, c);
        }
        else {
            long long a, b;
            cin >> a >> b;
            a--; b--;
            cout << (q2(a, b) ? "NO" : "YES") << endl;
        }
    }
    inds[0].clear();
    inds[1].clear();
    for (long long i = 0; i < n; i++) {
        arr[i] = 0;
        works[i][0] = false;
        works[i][1] = false;
    }
    for (long long i = 0; i < 4 * n + 10; i++) {
        t[i] = 0;
        lazy[i] = 0;
    }
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
//2 3
//ae
//1 1 1 30
//2 1 2
//2 1 1
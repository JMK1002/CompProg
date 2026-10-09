//
// Created by JMKov on 7/8/2023.
//
#include <iostream>
using namespace std;

int t[800010];
string s;
int q;

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = 1 << (s[tl] - 'a');
    }
    else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        t[v] = (t[v * 2] | t[v * 2 + 1]);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return 0;
    }
    else if (l == tl && r == tr) {
        return t[v];
    }
    else {
        int tm = (tl + tr) / 2;
        return query(v * 2, tl, tm, l, min(tm, r)) | query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }
}

int solve() {
    build(1, 0, s.size() - 1);
    while (q--) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        if (u == v || s[u] != s[v]) {
            cout << "Yes" << endl;
            continue;
        }
        int ret = query(1, 0, s.size() - 1, u, v);
        int count = 0;
        while (ret) {
            count += (ret & 1);
            ret >>= 1;
        }
//        cout << count << endl;
        if (count >= 3) {
            cout << "Yes" << endl;
            continue;
        }
        cout << "No" << endl;
    }
    return 0;
}

int main() {
    cin >> s >> q;
    solve();
    return 0;
}
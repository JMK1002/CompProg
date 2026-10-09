//
// Created by JMKov on 7/13/2023.
//
#include <iostream>
using namespace std;

pair<int, int> tree[800010];
int arr[200010];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v].second = arr[tl];
    }
    else {
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        tree[v].second = tree[v * 2].second + tree[v * 2 + 1].second;
    }
}

int amnt = 0;

void update(int v, int index, int tl, int tr) {
    if (tree[v].first == tree[v].second || (amnt == 0) || tr < index) return;
    if (tl == tr) {
        int asdf = min(amnt, tree[v].second - tree[v].first);
        tree[v].first += asdf;
        amnt -= asdf;
    }
    else {
        int tm = (tl + tr) / 2;
        update(v * 2, index, tl, tm);
        update(v * 2 + 1, index, tm + 1, tr);
        tree[v].first = tree[v * 2].first + tree[v * 2 + 1].first;
    }
}

int query(int v, int index, int tl, int tr) {
    if (tl == tr) {
        return tree[v].first;
    }
    else {
        int tm = (tl + tr) / 2;
        if (index <= tm) {
            return query(v * 2, index, tl, tm);
        }
        else {
            return query(v * 2 + 1, index, tm + 1, tr);
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    build(1, 0, n - 1);
//    for (int i = 0; i < 4 * n; i++) {
//        cout << tree[i].first << " " << tree[i].second << endl;
//    }
//    cout << endl;
//    amnt = 23;
//    update(1, 2, 0, n - 1);
//    amnt = 2;
//    update(1, 2, 0, n - 1);
//    for (int i = 0; i < 4 * n; i++) {
//        cout << tree[i].first << " " << tree[i].second << endl;
//    }
//    cout << endl;
//    return 0;
    int m;
    cin >> m;
    while (m--) {
        int t;
        cin >> t;
        if (t == 1) {
            int in, v;
            cin >> in >> v;
            amnt = v;
            update(1, in - 1, 0, n - 1);
        }
        else {
            int in;
            cin >> in;
            cout << query(1, in - 1, 0, n - 1) << endl;
        }
//        for (int i = 0; i < 4 * n; i++) {
//            cout << tree[i].first << " " << tree[i].second << endl;
//        }
//        cout << endl;
    }
    return 0;
}
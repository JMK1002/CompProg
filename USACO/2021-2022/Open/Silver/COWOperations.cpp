//
// Created by JMKov on 12/12/2023.
//
#include <iostream>
using namespace std;

int t[1000000];
int arr[200002];

int combine(int a, int b) {
    if (a == -1) return b;
    else if (b == -1) return a;
    else if (a == b) return -1;
    else return (3 - a - b);
}

void build(int v, int l, int r) {
    if (l == r) {
        t[v] = arr[l];
    }
    else {
        int mid = (l + r) / 2;
        build(v * 2, l, mid);
        build(v * 2 + 1, mid + 1, r);
        t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }
}

int query(int v, int l, int r, int tl, int tr) {
    if (l > r || tl > tr) return -1;
    else if (l == tl && r == tr) {
        return t[v];
    }
    else {
        int mid = (l + r) / 2;
        return combine(query(2 * v, l, mid, tl, min(mid, tr)),
                       query(2 * v + 1, mid + 1, r, max(tl, mid + 1), tr));
    }
}

int main() {
    string s;
    int q;
    cin >> s >> q;
    int n = s.size();
    for (int i = 0; i < n ; i++) {
        char c = s[i];
        if (c == 'C') arr[i] = 0;
        else if (c == 'O') arr[i] = 1;
        else if (c == 'W') arr[i] = 2;
    }

    build(1, 0, n - 1);
//    for (int i = 0; i < 20; i++) cout << arr[i] << " ";
//    cout << endl;
//    for (int i = 0; i < 20; i++) cout << t[i] << " ";
//    cout << endl;

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        cout << ((query(1, 0, n - 1, a, b) == 0) ? "Y" : "N");
    }
    return 0;
}
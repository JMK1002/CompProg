#include <iostream>
using namespace std;

int arr[200005];
int run[200005];
int last[200005];
int nxt[200005];
int lft[200005];
int t[1000000];
int n, q;

void asdf() {
    for (int i = 1; i <= n; i++) run[arr[i]] = 0;
    for (int i = 0; i <= n; i++) {
        arr[i] = 0;
        last[i] = 0;
        nxt[i] = 0;
        lft[i] = 0;
    }
    for (int i = 0; i <= n * 4; i++) t[i] = 0;
}

int get(int v, int tl, int tr, int l, int r) {
    if (tl > tr || l > r || tl > l || tr < r) return 0;
    else if (tl == l && tr == r) {
        return t[v];
    }
    else {
        int tm = (tl + tr) / 2;
        return max(
            get(v * 2, tl, tm, l, min(tm, r)),
            get(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r)
        );
    }
}

void update(int v, int tl, int tr, int ind, int val) {
    if (tl > tr || tl > ind || tr < ind) return;
    else if (tl == tr) {
        t[v] = val;
    }
    else {
        int tm = (tl + tr) / 2;
        update(v * 2, tl, tm, ind, val);
        update(v * 2 + 1, tm + 1, tr, ind, val);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        last[i] = run[arr[i]];
        run[arr[i]] = i;
    }
    for (int i = 1; i <= n; i++) run[arr[i]] = n + 1;
    for (int i = n; i >= 1; i--) {
        nxt[i] = run[arr[i]];
        run[arr[i]] = i;
    }


    lft[1] = 1;
    for (int i = 2; i <= n; i++) {
        int k = lft[i - 1];
        while(last[i] != 0 && get(1, 1, n, k, last[i] - 1) > last[i]) {
            k++;
        }
        if (last[i] != 0) {
            update(1, 1, n, last[i], i);
        }
        lft[i] = k;
    }
    // for (int i = 1; i < 10; i++) cout << lft[i] << " ";
    // cout << endl;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << ((l >= lft[r]) ? "YES" : "NO") << endl;
    }
    asdf();
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
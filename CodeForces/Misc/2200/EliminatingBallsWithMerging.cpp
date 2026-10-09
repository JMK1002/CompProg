//
// Created by JMKov on 9/9/2024.
//
#include <iostream>
using namespace std;

long long n;
long long arr[200005];
long long pre[200005];
bool works[200005];
pair<long long, long long> t[1000000];

void clean() {
    for (long long i = 0; i <= n; i++) {
        arr[i] = 0;
        pre[i] = 0;
        works[i] = false;
    }
    for (long long i = 0; i <= 4 * n; i++) {
        t[i] = {0, 0};
    }
}

void build(long long v, long long l, long long r) {
    if (l > r) return;
    else if (l == r) {
        t[v] = {arr[l], l};
    }
    else {
        long long m = (l + r) / 2;
        build(v * 2, l, m);
        build(v * 2 + 1, m + 1, r);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
}

pair<long long, long long> get(long long v, long long l, long long r, long long tl, long long tr) {
    if (l > r || tl > tr || tl > l || tr < r) return {0, 0};
    else if (tl == l && tr == r) {
        return t[v];
    }
    else {
        long long m = (tl + tr) / 2;
        return max(
                get(v * 2, l, min(r, m), tl, m),
                get(v * 2 + 1, max(l, m + 1), r, m + 1, tr)
        );
    }
}

// inclusive
long long sum(long long l, long long r) {
    return pre[r] - pre[l - 1];
}

// l and r are inclusive for everything but prefix sums
void dfs(long long l, long long r) {
    if (r < l) return;
    long long mx = get(1, l, r, 1, n).second;
    works[mx] = true;

    long long ls = max(0ll, sum(l, mx - 1));
    long long rs = max(0ll, sum(mx + 1, r));

    if (ls >= arr[mx]) dfs(l, mx - 1);
    if (rs >= arr[mx]) dfs(mx + 1, r);


}

void solve() {
    cin >> n >> n;
    for (long long i = 1; i <= n; i++) cin >> arr[i];
    for (long long i = 1; i <= n; i++) pre[i] = pre[i - 1] + arr[i];
    build(1, 1, n);

//    for (long long i = 1; i <= n; i++) {
//        for (long long j = 1; j <= i; j++) {
//            cout << get(1, j, i, 1, n).second << " ";
//        }
//        cout << endl;
//    }
    dfs(1, n);
    long long ans = 0;
    for (long long i = 1; i <= n; i++) ans += works[i];
    cout << ans << endl;

    clean();
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie(nullptr);
    long long _;
    cin >> _;
    while (_--) solve();
    return 0;
}
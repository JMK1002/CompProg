#include <iostream>
#include <set>
#include <vector>
using namespace std;

long long n, m;
long long arr[200005];
long long cnt[200005];
long long t[1000000];
set<long long> ind[200005];

void build(long long v, long long tl, long long tr) {
    if (tl > tr) return;
    else if (tl == tr) {
        t[v] = arr[tl];
    }
    else {
        long long tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
}

long long query(long long v, long long tl, long long tr, long long l, long long r) {
    if (tl > tr || l > r || tl > l || r > tr) return 0;
    else if (tl == l && tr == r) {
        return t[v];
    }
    else {
        long long tm = (tl + tr) / 2;
        return max(
            query(v * 2, tl, tm, l, min(tm, r)),
            query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)
        );
    }
}

void dfs(long long height, long long l, long long r) {
    if (l > r) return;
    long long mx = query(1, 0, n - 1, l, r);

    cnt[r - l + 1] += height - mx;

    vector<long long> positions;
    positions.push_back(l - 1);
    auto ptr = ind[mx].lower_bound(l);
    while (ptr != ind[mx].end() && *ptr <= r) {
        positions.push_back(*ptr);
        ptr++;
    }
    positions.push_back(r + 1);
    for (long long i = 0; i < positions.size() - 1; i++) {
        dfs(mx, positions[i] + 1, positions[i + 1] - 1);
    }
}

void solve() {
    cin >> n;
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
        ind[arr[i]].insert(i);
    }
    cin >> m;
    build(1, 0, n - 1);
    dfs(n + 1, 0, n - 1);
    cnt[n]--;
    long long ans = 0;
    for (long long i = n; i >= 1; i--) {
        long long k = min(m / i, cnt[i]);
        m -= k * i;
        ans += k * (i - 1);
        cnt[i] -= k;
        if (m == 0) break;
        if (cnt[i] == 0) continue;
        ans += max(0ll, m - 1);
        m = 0;
        break;
    }
    // for (long long i = 0; i <= n; i++) cout << cnt[i] << " ";
    // cout << endl
    cout << ans << endl;
    for (long long i = 0; i <= n; i++) {
        cnt[i] = 0;
        arr[i] = 0;
        ind[i].clear();
    }
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
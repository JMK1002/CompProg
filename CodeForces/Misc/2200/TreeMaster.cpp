#include<bits/stdc++.h>
#define int long long

using namespace std;
#define size(u) (int)(u).size()
#define pb push_back
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

constexpr int MAXN = 1e5+4, R = 2500;
constexpr int LOG = 20;
int a[MAXN], p[MAXN], up[MAXN][LOG], dpt[MAXN], sum[MAXN];
vector<int> c[MAXN];

int lca(int a, int b) {
    if (a == b) return a;
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[a][i] != up[b][i])
            a = up[a][i], b = up[b][i];
    }
    return up[a][0];
}

int dist(int a, int b) {
    return dpt[a] - dpt[lca(a, b)];
}

int fazai(int x, int y) {
    int ans = 0;
    while (x != y) {
        ans += a[x] * a[y];
        x = p[x], y = p[y];
    }
    return ans + sum[x];
}

struct pair_hash {
    int operator()(pair<int, int> a) const {
        return a.first << 30 | a.second;
    }
};

signed main() {
    fastio;
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        c[p[i]].pb(i);
        up[i][0] = p[i];
    }
    sum[1] = a[1] * a[1];
    queue<array<int, 3>> qq; qq.push({1, a[1] * a[1], 0});
    while (!qq.empty()) {
        auto pf = qq.front(); qq.pop();
        int cur = pf[0], d = pf[2], s = pf[1];
        for (auto u : c[cur]) {
            dpt[u] = 1 + d;
            sum[u] = s + a[u] * a[u];
            qq.push({u, sum[u], dpt[u]});
        }
    }
    for (int i = 1; i < LOG; i++) {
        for (int u = 1; u <= n; u++) {
            up[u][i] = up[up[u][i-1]][i-1];
        }
    }
    unordered_map<pair<int, int>, int, pair_hash> mp;
    auto fazesalva = [&] (int x, int y) -> int {
        vector<pair<int, int>> tos;
        while (x != y && mp.find({x, y}) == mp.end()) {
            tos.pb({x, y});
            x = p[x], y = p[y];
            if (x > y) swap(x, y);
        }
        int ans = 0;
        if (mp.find({x, y}) != mp.end()) {
            ans = mp[{x, y}];
        } else {
            ans = sum[x];
        }
        while (!tos.empty()) {
            auto pf = tos.back();
            ans += a[pf.first] * a[pf.second];
            mp[{pf.first, pf.second}] = ans;
            tos.pop_back();
        }
        return ans;
    };
    while (q--) {
        int x, y; cin >> x >> y;
        int d = dist(x, y);
        if (x > y) swap(x, y);
        if (d < R) {
            cout << fazai(x, y) << '\n';
        } else {
            cout << fazesalva(x, y) << '\n';
        }
    }
}
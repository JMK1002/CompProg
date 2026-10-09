#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define F first
#define S second

using namespace std;

void solve(){
    int n, m, k; cin >> n >> m >> k;

    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    vector<vector<int>> adj(n);
    vector<int> deg(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        deg[v]++;
    }
    vector<int> q;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) {
            q.push_back(i);
        }
    }
    for (int i = 0; i < n; i++) {
        int x = q[i];
        for (auto y : adj[x]) {
            if (--deg[y] == 0) {
                q.push_back(y);
            }
        }
    }
    vector<ll> dp(n);
    for (int i = n - 1; i >= 0; i--) {
        int x = q[i];
        for (auto y : adj[x]) {
            dp[x] = max(dp[x], dp[y] + (h[y] - h[x] + k) % k);
        }
    }
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(),
         [&](int i, int j) {
             return h[i] < h[j];
         });
    ll ans = 1e18;
    for (int i = 0; i < n; i++) {
        dp[i] += h[i];
    }
    ll res = *max_element(dp.begin(), dp.end());

    for (auto i : p) {
        ans = min(ans, res - h[i]);
        res = max(res, dp[i] + k);
    }
    cout << ans << "\n";

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int T = 1; cin >> T;
    while(T--){
        solve();
    }
}
#include <bits/stdc++.h>
using namespace std;

long long n, q;
long long col[200005];
set<pair<long long, long long>> adj[200005];
pair<long long, long long> par[200005];
map<long long, long long> mp[200005];
long long ans = 0;

void dfs(long long v) {
	for (pair<long long, long long> e : adj[v]) {
		if (e.first == par[v].first) continue;
		par[e.first] = {v, e.second};
		dfs(e.first);
	}
	mp[par[v].first][col[v]] += par[v].second;
	if (col[par[v].first] != col[v]) {
		ans += par[v].second;
	}
}

void solve() {
	cin >> n >> q;
	col[0] = -1;
	for (long long i = 1; i <= n; i++) cin >> col[i];
	for (long long i = 0; i < n - 1; i++) {
		long long u, v, c;
		cin >> u >> v >> c;
		adj[u].insert({v, c});
		adj[v].insert({u, c});
	}

	dfs(1);
	while (q--) {
		long long v, x;
		cin >> v >> x;
		ans += mp[v][col[v]];
		if (col[par[v].first] == col[v]) ans += par[v].second;
		ans -= mp[v][x];
		if (col[par[v].first] == x) ans -= par[v].second;

		mp[par[v].first][col[v]] -= par[v].second;
		mp[par[v].first][x] += par[v].second;

		col[v] = x;
		cout << ans << endl;
	}
	ans = 0;
	for (int i = 0; i <= n; i++) {
		col[i] = 0;
		adj[i].clear();
		par[i] = {0, 0};
		mp[i].clear();
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
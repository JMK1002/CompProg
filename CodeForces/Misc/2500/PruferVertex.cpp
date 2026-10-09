#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 998244353;

int n, m, k, tot;
set<int> adj[200005];
int ans[200005];
bool explored[200005];
bool withRoot[200005];
int sz[200005];
int subSz[200005];
int par[200005];

int binpow(int a, int b) {
	if (b == -1) return binpow(a, mod - 2);
	int res = 1;
	int run = a;
	while (b) {
		if (b & 1) res *= run;
		run *= run;
		run %= mod;
		res %= mod;
		b >>= 1;
	}
	return res;
}

int inv(int v) {
	return binpow(v, mod - 2);
}

void asdf(int v, int p) {
	withRoot[v] = true;
	for (int e : adj[v]) {
		if (e == p) continue;
		asdf(e, v);
	}
}

void szDfs(int v, int p, int val) {
	par[v] = p;
	sz[v] = val;
	for (int e : adj[v]) {
		if (e == p) continue;
		szDfs(e, v, val);
	}
}

int dfs(int v) {
	int res = 1;
	explored[v] = true;
	for (int e : adj[v]) {
		if (explored[e]) continue;
		res += dfs(e);
	}
	subSz[v] = res;
	return res;
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	tot = 1;
	k = 0;


	szDfs(n - 1, n - 1, dfs(n - 1));
	tot *= sz[n - 1];
	tot %= mod;
	k++;
	for (int i = 0; i < n; i++) {
		if (explored[i]) continue;
		szDfs(i, i, dfs(i));
		tot *= sz[i];
		tot %= mod;
		k++;
	}
	tot *= binpow(n, k - 2);
	tot %= mod;
	asdf(n - 1, n - 1);

	if (withRoot[n - 2]) {
		int run = n - 2;
		while (par[run] != n - 1) run = par[run];
		ans[run] = tot;
	}
	else {
		for (int e : adj[n - 1]) {
			ans[e] = tot * subSz[e] % mod * inv(sz[n - 1]) % mod;
		}
		for (int i = 0; i < n; i++) {
			if (withRoot[i] || i == n - 2) continue;
			ans[i] = tot * inv(n) % mod * inv(sz[n - 1] * sz[i] % mod) % mod * (sz[n - 1] + sz[i]) % mod * sz[i] % mod * inv(sz[n - 1] + sz[i]) % mod;
		}
		for (int i = 0; i < n; i++) withRoot[i] = false;
		asdf(n - 2, n - 2);
		for (int i = 0; i < n; i++) {
			if (!withRoot[i]) continue;
			ans[i] = tot * inv(n) % mod * inv(sz[n - 1] * sz[i] % mod) % mod * (sz[n - 1] + sz[i]) % mod;
		}
		// int s = 0;
		// for (int i = 0; i < n; i++) s += ans[i];
		// s %= mod;
		// ans[n - 2] = (tot - s + mod) % mod;
	}
	for (int i = 0; i < n - 1; i++) cout << ans[i] << " ";
	cout << endl;

	for (int i = 0; i <= n; i++) {
		adj[i].clear();
		ans[i] = 0;
		explored[i] = false;
		withRoot[i] = false;
		sz[i] = 0;
		subSz[i] = 0;
		par[i] = 0;
	}
}

signed main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}

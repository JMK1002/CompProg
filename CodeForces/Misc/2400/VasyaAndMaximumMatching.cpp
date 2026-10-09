#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 998244353;

int n;
set<int> children[300005];
int par[300005];
int dp[2][300005]; // answer for subtree, 0 if the root was a singular node and 1 if it was linked (so perfect matching)
int tot[300005]; // prod of dp[0] + 2 * dp[1] of children

int inv(int a) {
  return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

void dfs(int v, int p) {
	par[v] = p;
	children[v].erase(p);
	for (int e : children[v]) {
		dfs(e, v);
	}
}

void dfs2(int v) {
	for (int e : children[v]) {
		dfs2(e);
	}

	dp[0][v] = 1;
	tot[v] = 1;
	for (int e : children[v]) {
		tot[v] *= (dp[0][e] + 2 * dp[1][e]) % mod;
		tot[v] %= mod;
		dp[0][v] *= (dp[0][e] + dp[1][e]) % mod;
		dp[0][v] %= mod;
	}

	for (int e : children[v]) {
		dp[1][v] += tot[v] * inv((dp[0][e] + 2 * dp[1][e]) % mod) % mod
			* tot[e] % mod;
		dp[1][v] %= mod;
	}
}

void solve() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		children[u].insert(v);
		children[v].insert(u);
	}
	dfs(0, 0);
	dfs2(0);
	cout << (dp[0][0] + dp[1][0]) % mod << endl;
}

signed main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}

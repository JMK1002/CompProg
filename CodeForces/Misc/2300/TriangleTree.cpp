#include <iostream>
#include <set>
using namespace std;

long long n;
set<long long> adj[300005];
long long par[300005];
long long sz[300005];
long long d[300005];
long long cnt[300005];
long long pre[300005];
long long ans = 0;
long long amnt = 0;

void dfs(long long v, long long p) {
	sz[v] = 1;
	adj[v].erase(p);
	par[v] = p;
	d[v] = d[par[v]] + 1;
	cnt[d[v]]++;
	for (long long e : adj[v]) {
		dfs(e, v);
		sz[v] += sz[e];
	}
	for (long long e : adj[v]) {
		ans -= d[v] * (sz[e]) * (sz[v] - sz[e] - 1); // counts twice, so no need to *2
		amnt += (sz[e]) * (sz[v] - sz[e] - 1);
	}
}

void dfs2(long long v) {
	ans += 2 * d[v] * (pre[d[v] + 1] - (sz[v] - 1));
	ans += d[v] * (cnt[d[v]] - 1);
	for (long long e : adj[v]) {
		dfs2(e);
	}
}

void solve() {
	cin >> n;
	for (long long i = 0; i < n - 1; i++) {
		long long u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	dfs(0, 0);
	ans -= amnt / 2;
	pre[n + 1] = 0;
	for (long long i = n; i >= 0; i--) pre[i] = pre[i + 1] + cnt[i];
	dfs2(0);
	cout << ans << endl;

	for (int i = 0; i <= n + 2; i++) {
		adj[i].clear();
		par[i] = 0;
		sz[i] = 0;
		d[i] = 0;
		cnt[i] = 0;
		pre[i] = 0;
	}
	ans = 0;
	amnt = 0;

	// ! sum of min(d_u, d_v) for all u, v with lca neq u or v
	// ?	can be done with complementary counting if we have sz[v]
	// ! negative sum of 2 * all lca depths (do with dfs)
	// ! minus amount of lca pairs that exist
}

int main() {
	long long t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
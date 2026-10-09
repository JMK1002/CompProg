#include <iostream>
#include <set>
using namespace std;

long long n;
set<pair<long long, long long>> adj[200005];
long long par[200005];
long long sz[200005];
long long l, h;

void dfs(long long v, long long p) {
	par[v] = p;
	sz[v] = 1;
	for (pair<long long, long long> e : adj[v]) {
		if (e.first == p) continue;
		dfs(e.first, v);
		sz[v] += sz[e.first];
	}
	if (v == p) return;
	l += (sz[v] % 2) * adj[v].lower_bound({p, -1})->second;
	h += min(sz[v], 2 * n - sz[v]) *  adj[v].lower_bound({p, -1})->second;
}

void solve() {
	cin >> n;
	for (long long i = 0; i < 2 * n - 1; i++) {
		long long u, v, t;
		cin >> u >> v >> t;
		u--; v--;
		adj[u].insert({v, t});
		adj[v].insert({u, t});
	}
	dfs(0, 0);
	cout << l << " " << h << endl;
	l = 0; h = 0;
	for (long long i = 0; i <= 2 * n; i++) {
		adj[i].clear();
		par[i] = 0;
		sz[i] = 0;
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
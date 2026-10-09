#include <iostream>
#include <set>
using namespace std;

int n;
pair<int, int> bounds[200005];
set<int> adj[200005];
int a[200005];
int par[200005];

void dfs(int v, int p) {
	par[v] = p;
	int mx = 0;
	for (int e : adj[v]) {
		if (e == p) continue;
		dfs(e, v);
		mx = max(mx, a[e]);
	}
	a[v] = max(bounds[v].first, min(mx, bounds[v].second));
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> bounds[i].first >> bounds[i].second;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	dfs(0, 0);
	long long ans = a[0];
	for (int i = 0; i < n; i++) {
		ans += max(0, a[i] - a[par[i]]);
	}
	cout << ans << endl;

	for (int i = 0; i <= n; i++) {
		bounds[i] = make_pair(0, 0);
		adj[i].clear();
		a[i] = 0;
		par[i] = 0;
	}
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
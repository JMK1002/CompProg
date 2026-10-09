#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int n, q;
int par[2004];
int dist[2004];
set<int> adj[2004];

void dfs(int v, int p) {
	dist[v] = dist[p] + 1;
	par[v] = p;
	for (int e : adj[v]) {
		if (e == p) continue;
		dfs(e, v);
	}
}

void solve() {
	cin >> n >> q;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	dfs(1, 1);
	while (q--) {
		int v, k;
		cin >> v >> k;
		vector<pair<int, int>> imp;
		int a = v;
		a = par[a];
		while (a != 1) {
			imp.push_back({adj[a].size(), a});
			a = par[par[a]];
		}
		sort(imp.begin(), imp.end());
		for (int i = 0; !imp.empty() && i < k; i++) imp.pop_back();
		int ans = dist[v] - 1;
		for (pair<int, int> i : imp) ans += 2 * (i.first - 1);
		cout << ans << endl;
	}

	for (int i = 0; i <= n; i++) {
		adj[i].clear();
		dist[i] = 0;
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
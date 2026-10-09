#include <bits/stdc++.h>
using namespace std;

set<int> adj[200005];
bool col[200005];

void dfs(int v, int p) {
	col[v] = !col[p];
	for (int e : adj[v]) {
		if (e == p) continue;
		dfs(e, v);
	}
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	dfs(1, 1);
	for (int i = 1; i <= n; i++) cout << ((long long) adj[i].size() * (col[i] ? 1 : -1)) << " ";
	
	cout << endl;
	for (int i = 0; i <= n; i++) {
		adj[i].clear();
		col[i] = 0;
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
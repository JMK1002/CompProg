#include <bits/stdc++.h>
using namespace std;

int n, k;
int w[200005];
int col[200005];
set<int> adj[200005];
long long ans = 0;

set<int> dfs(int v, int p, int hc) {
	if (col[v] != -1) hc = v;
	set<int> curr;
	set<int> too;
	for (int e : adj[v]) {
		if (e == p) continue;
		set<int> seen = dfs(e, v, hc);
		if (seen.size() < curr.size()) swap(seen, curr);
		for (int j : seen) {
			int sz = curr.size();
			curr.insert(j);
			if (j != col[v] && sz == curr.size()) {
				too.insert(j);
			}
		}
	}
	if (col[v] != -1) {
		curr.insert(col[v]);
		if (too.size() >= 1) ans += w[v];
		return curr;
	}
	if (too.size()) {
		col[v] = *too.begin();
		if (too.size() > 1) ans += w[v];
	}
	else if (adj[v].size() != 1) {
		int c = -1;
		for (int e : adj[v]) {
			if (e == p || col[e] == -1) continue;
			c = col[e];
		}
		col[v] = c;
	}
	return curr;
}

void dfs2(int v, int p) {
	if (col[v] == -1 && v == p) col[v] = 1;
	else if (col[v] == -1) col[v] = col[p];
	for (int e : adj[v]) {
		if (e == p) continue;
		dfs2(e, v);
	}
}


void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> w[i];
	for (int i = 0; i < n; i++) cin >> col[i];
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		// u = (i + 2) / 2; v = i + 2;
		u--; v--;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	for (int i = 0; i < n; i++) if (col[i] == 0) col[i] = -1;
	dfs(0, 0, -1);
	dfs2(0, 0);
	cout << ans << endl;
	for (int i = 0; i < n; i++) cout << col[i] << " ";
	cout << endl;

	for (int i = 0; i <= n; i++) {
		w[i] = 0;
		col[i] = 0;
		adj[i].clear();
	}
	ans = 0;
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
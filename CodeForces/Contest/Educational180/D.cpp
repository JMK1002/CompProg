#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int n;
set<int> adj[200005];
int col[200005];
vector<pair<int, int>> edges;

void dfs(int v, int p) {
	if (col[v] == 0) col[v] = (col[p] == 1) ? 2 : 1;
	for (int e : adj[v]) {
		if (e == p) continue;
		dfs(e, v);
	}
}

void solve() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].insert(v);
		adj[v].insert(u);;
	}
	int nd = -1;
	for (int i = 0; i < n; i++) {
		if (adj[i].size() == 2) nd = i;
	}
	if (nd == -1) {
		cout << "NO" << endl;
		return;
	}
	int x = *adj[nd].begin();
	col[x] = 1;
	col[nd] = 1;
	dfs(x, x);
	adj[x].erase(nd);
	adj[nd].erase(x);
	edges.push_back({x, nd});

	for (int i = 0; i < n; i++) {
		if (col[i] == 2) continue;
		for (int e : adj[i]) edges.push_back({i, e});
	}
	cout << "YES" << endl;
	for (pair<int, int> p : edges) cout << p.first + 1 << " " << p.second + 1 << endl;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
		for (int i = 0; i <= n; i++) {
			col[i] = 0;
			adj[i].clear();
		}
		edges.clear();
	}
}
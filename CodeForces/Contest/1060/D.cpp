#include <bits/stdc++.h>
using namespace std;

int n;
set<int> adj[200005];
bool dist[200005];
int par[200005];

void dfs(int v, int p) {
	par[v] = p;
	dist[v] = !dist[p];
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
		adj[v].insert(u);
	}
	dfs(n - 1, n - 1);
	queue<int> leaves;
	for (int i = 0; i < n; i++) if (adj[i].size() <= 1 && i != n - 1) leaves.push(i);
	bool t = 0;
	vector<pair<int, int>> ans;

	while (!leaves.empty()) {
		int l = leaves.front();
		if (t ^ dist[0] ^ dist[leaves.front()]) {
			t = !t;
			ans.push_back({2, l});
			ans.push_back({1, 0});
			leaves.pop();
			int j = par[l];
			adj[j].erase(l);
			if (adj[j].size() <= 1 && j != n - 1) leaves.push(j);
			adj[l].clear();
		}
		else {
			t = !t;
			ans.push_back({1, 0});
		}
	}
	cout << ans.size() << endl;
	for (pair<int, int> p : ans) {
		if (p.first == 1) cout << 1 << endl;
		else cout << p.first << " " << p.second + 1 << endl;
	}
	cout << endl;

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
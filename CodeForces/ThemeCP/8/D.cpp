#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, pair<int, int>>> edges;
int par[200005];
int mn[200005];
set<int> adj[200005];
int tim[200005];
int cnt = 1;
vector<pair<int, int>> ans;

void dfs(int v) {
	if (tim[v]) return;
	tim[v] = cnt;
	for (int e : adj[v]) {
		dfs(e);
	}
}

int rt(int a) {
	int res = a;
	while (par[res] != res) {
		res = par[res];
	}
	while (par[a] != a) {
		int b = a;
		a = par[a];
		par[b] = res;
	}
	return res;
}

void combine(int a, int b, int w) {
	int ra = rt(a);
	int rb = rt(b);
	if (ra == rb) return;
	if (ra == 0) {
		swap(ra, rb);
	}
	par[ra] = rb;
	mn[rb] = min(mn[rb], mn[ra]);
	mn[rb] = min(mn[rb], w);
	adj[ra].insert(rb);
	adj[rb].insert(ra);
	if (rb == 0) {
		cnt++;
		dfs(ra);
		while (ans.back().second >= mn[rb] + w) ans.pop_back();
		ans.push_back({cnt, mn[rb] + w});
	}
}

int getMn(int a) {
	return mn[rt(a)];
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		edges.push_back({w, {u, v}});
	}
	sort(edges.begin(), edges.end());
	for (int i = 0; i < n; i++) {
		par[i] = i;
		mn[i] = 2e9;
	}
	tim[0] = cnt;
	ans.push_back({0, -1e9});
	for (int i = 0; i < m; i++) {
		combine(edges[i].second.first, edges[i].second.second, edges[i].first);
	}
	// for (int i = 0; i < n; i++) cout << tim[i] << " ";
	// cout << endl;
	// for (pair<int, int> p : ans) cout << p.first << " " << p.second << endl;
	cout << (lower_bound(ans.begin(), ans.end(), make_pair(tim[n - 1], (int) -2e9))->second) << endl;

	for (int i = 0; i <= n; i++) {
		par[i] = 0;
		mn[i] = 0;
		adj[i].clear();
		tim[i] = 0;
	}
	ans.clear();
	cnt = 1;
	edges.clear();
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
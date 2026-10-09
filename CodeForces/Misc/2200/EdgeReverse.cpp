#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
set<pair<int, int>> adj[200005];
set<pair<int, int>> radj[200005];
bool explored[200005];
vector<int> topo;

void go(int v, int mx) {
	explored[v] = true;
	for (pair<int, int> e : adj[v]) {
		if (explored[e.first]) continue;
		go(e.first, mx);
	}
	for (pair<int, int> e : radj[v]) {
		if (explored[e.first] || e.second > mx) continue;
		go(e.first, mx);
	}
}

void dfs(int v, int mx) {
	explored[v] = true;
	for (pair<int, int> e : adj[v]) {
		if (explored[e.first]) continue;
		dfs(e.first, mx);
	}
	for (pair<int, int> e : radj[v]) {
		if (explored[e.first] || e.second > mx) continue;
		dfs(e.first, mx);
	}
	topo.push_back(v);
}

bool works(int amnt) {
	for (int i = 1; i <= n; i++) explored[i] = false;
	topo.clear();
	for (int i = 1; i <= n; i++) if (!explored[i]) dfs(i, amnt);
	for (int i = 1; i <= n; i++) explored[i] = false;
	go(topo[topo.size() - 1], amnt);
	int cnt = 0;
	for (int i = 1; i <= n; i++) cnt += explored[i];
	if (cnt < n) {
		return false;
	}
	return true;
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].insert({v, w});
		radj[v].insert({u, w});
	}

	int low = 0;
	int high = 1e9+2;
	if (!works(high)) {
		cout << -1 << endl;
		return;
	}
	if (works(low)) {
		cout << 0 << endl;
		return;
	}

	while (high - low > 1) {
		int mid = (high + low) / 2;
		if (!works(mid)) low = mid;
		else high = mid;
	}

	cout << high << endl;
	return;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
		for (int i = 0; i <= n; i++) {
			adj[i].clear();
			radj[i].clear();
			explored[i] = false;
		}
		topo.clear();
	}
	return 0;
}
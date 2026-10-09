#include <iostream>
#include <set>
using namespace std;

int n;
set<int> adj[200005];
int col[200005];
int cnt = 0;
bool explored[200005];

void dfs(int v, int p) {
	int grn = 0;
	int ylw = 0;
	for (int e : adj[v]) {
		if (e == p) continue;
		dfs(e, v);
		grn += col[e] == 1;
		ylw += col[e] == 2;
	}
	if (grn >= 3 || ylw) col[v] = 3;
	else if (grn == 2) col[v] = 2;
	else col[v] = 1;
	cnt += col[v] == 3;
}

void dfs2(int v, int p) {
	explored[v] = true;
	cout << "1 " << v << endl;
	for (int e : adj[v]) {
		if (e == p) continue;
		dfs2(e, v);
	}
}

void solve() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	dfs(1, 1);
	cout << n + cnt << endl;
	for (int i = 1; i <= n; i++) {
		if (col[i] == 3) {
			cout << "2 " << i << endl;
			for (int j : adj[i]) adj[j].erase(i);
			adj[i].clear();
		}
	}
	for (int i = 1; i <= n; i++) if (adj[i].size() <= 1 && !explored[i]) dfs2(i, i);
	for (int i = 0; i <= n + 1; i++) {
		adj[i].clear();
		col[i] = 0;
		explored[i] = false;
	}
	cnt = 0;
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
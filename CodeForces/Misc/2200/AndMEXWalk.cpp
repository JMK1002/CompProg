#include <iostream>
#include <set>
using namespace std;

int n, m;
set<pair<int, int>> adj[100005];
int comp[30][100005];
bool works[30][100005];
int cnt;

void dfs(int v, int i, int pow) {
	comp[i][v] = cnt;
	for (pair<int, int> e : adj[v]) {
		if ((e.second & 1) == 0) works[i][cnt] = true;
		if ((e.second & pow) == 0) continue;
		if (comp[i][e.first]) continue;
		dfs(e.first, i, pow);
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		adj[u].insert({v, w});
		adj[v].insert({u, w});
	}
	for (int i = 0, pow = 1; i < 30; i++, pow <<= 1) {
		cnt = 1;
		for (int j = 0; j < n; j++) {
			if (comp[i][j]) continue;
			dfs(j, i, pow);
			cnt++;
		}
	}

	int q;
	cin >> q;
	while (q--) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		bool zero = false;
		bool one = false;
		for (int i = 0; i < 30; i++) {
			if (comp[i][u] == comp[i][v]) zero = true;
			if (i != 0 && works[i][comp[i][u]]) one = true;
		}
		if (zero) cout << 0 << endl;
		else if (one) cout << 1 << endl;
		else cout << 2 << endl;
	}

	for (int i = 0; i <= n; i++) {
		adj[i].clear();
		for (int j = 0; j < 30; j++) {
			comp[j][i] = 0;
			works[j][i] = false;
		}
	}
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
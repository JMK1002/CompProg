#include <iostream>
#include <set>
#include <map>
using namespace std;

int n, m, k;
map<int, set<int>> adj;
map<int, bool> coloring;
map<int, bool> explored;

void addEdge(int a, int b) {
	adj[a].insert(b);
	adj[b].insert(a);
}

bool dfs(int v, int p) {
	explored[v] = true;
	coloring[v] = !coloring[p];
	for (int e : adj[v]) {
		if (e == p) continue;
		if (explored[e] && coloring[e] == coloring[v]) return false;
		else if (explored[e]) continue;
		if (!dfs(e, v)) return false;
	}
	return true;
}

void solve() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n + m; i++) {
		addEdge(i, -i);
	}
	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int mx, my;
		mx = min(x1, x2);
		my = min(y1, y2);
		if ((mx == x1) ^ (my == y1)) {// forward slash
			addEdge(mx, -(my + n));
			addEdge((my + n), -mx);
		}
		else {//back slash
			addEdge(mx, (my + n));
			addEdge(-mx, -(my + n));
		}
	}
	bool ans = true;
	for (int i = 1; i <= n + m; i++) if (!explored[i]) ans &= dfs(i, i);
	if (ans) cout << "YES" << endl;
	else cout << "NO" << endl;

	adj.clear();
	explored.clear();
	coloring.clear();
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
// 4 1 /
// 5 1 \
// 7 1 \
// 2 2 \
// 8 1 \
// 2 2 /

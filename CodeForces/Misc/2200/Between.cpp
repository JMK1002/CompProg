#include <iostream>
#include <set>
#include <queue>
#include <vector>
using namespace std;

int n, m;
set<int> adj[1505];
vector<int> arrs[1505];
int dist[1505];

void solve() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[v].insert(u);
	}
	queue<int> q;
	q.push(1);
	dist[1] = 1;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int e : adj[v]) {
			if (dist[e]) continue;
			dist[e] = dist[v] + 1;
			q.push(e);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (dist[i] == 0) {
			cout << "INFINITE" << endl;
			return;
		}
		arrs[dist[i]].push_back(i);
		ans += dist[i];
	}

	cout << "FINITE" << endl;
	cout << ans << endl;
	for (int i = n; i >= 1; i--) {
		for (int j = i; j <= n; j++) {
			for (int k : arrs[j]) cout << k << " ";
		}
	}
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
			arrs[i].clear();
			dist[i] = 0;
		}
	}
	return 0;
}
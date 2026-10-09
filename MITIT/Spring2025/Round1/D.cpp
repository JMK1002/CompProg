#include <iostream>
#include <set>
#include <queue>
#include <vector>
using namespace std;

int n, m, k;
int arr[200005];
set<int> adj[200005];
int dist[200005];

void addEdge(int u, int v) {
	adj[u].insert(v);
	adj[v].insert(u);
}

void solve() {
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) cin >> arr[i];
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		addEdge(u, v);
	}

	// ! ITS ONE INDEXED!!!!
	
	vector<pair<int, int>> ans;
	for (int i = 0; i < k; i++) {
		if ((i ? arr[i - 1] : 1) != arr[i]) {
			ans.push_back({i ? arr[i - 1] : 1, arr[i]});
			addEdge(i ? arr[i - 1] : 1, arr[i]);
		}
	}

	for (int i = 1; i <= n; i++) dist[i] = -1;
	queue<int> q;
	q.push(1);
	dist[1] = 0;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int e : adj[v]) {
			if (dist[e] == -1) {
				dist[e] = dist[v] + 1;
				q.push(e);
			}
		}
	}

	for (int i = 0; i < k - 1; i++) {
		if (dist[arr[i]] >= dist[arr[i + 1]]) {
			cout << -1 << endl;
			return;
		}
	}
	cout << ans.size() << endl;
	for (pair<int, int> p : ans) cout << p.first << " " << p.second << endl;
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
			arr[i] = 0;
			dist[i] = 0;
		}
	}
	return 0;
}
#include <iostream>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 2000000000;

int n, m, l;
int arr[400005];
bool explored[400005];
int dist[400005];
bool ans[400005];
set<int> adj[400005]; // node v is even node v + n is odd

void solve() {
	cin >> n >> m >> l;
	for (int i = 0; i < l; i++) cin >> arr[i];
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].insert(v + n);
		adj[v + n].insert(u);
		adj[v].insert(u + n);
		adj[u + n].insert(v);
	}

	for (int i = 0; i <= 2 * n; i++) {
		dist[i] = INF;
		explored[i] = false;
	}
	queue<int> q;
	q.push(0);
	explored[0] = true;
	dist[0] = 0;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int e : adj[v]) {
			if (explored[e]) continue;
			q.push(e);
			explored[e] = true;
			dist[e] = dist[v] + 1;
		}
	}

	// for (int i = 0; i < 2 * n; i++) cout << dist[i] << " ";
	// cout << endl;

	int sum = 0;
	int mn[2] = {0, INF};
	for (int i = 0; i < l; i++) {
		sum += arr[i];
		mn[arr[i] % 2] = min(mn[arr[i] % 2], arr[i]);
	}
	mn[0] = sum - mn[0];
	mn[1] = sum - mn[1];
	if (mn[0] % 2 == 1) swap(mn[0], mn[1]);
	for (int i = 0; i < n; i++) ans[i] |= dist[i] <= mn[0];
	for (int i = n; i < 2 * n; i++) ans[i % n] |= dist[i] <= mn[1];
	for (int i = 0; i < n; i++) cout << ans[i];
	cout << endl;

	for (int i = 0; i < 2 * n; i++) {
		arr[i] = 0;
		explored[i] = 0;
		dist[i] = 0;
		ans[i] = 0;
		adj[i].clear();
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
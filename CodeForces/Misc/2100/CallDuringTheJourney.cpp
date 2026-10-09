#include <iostream>
#include <set>
#include <vector>
using namespace std;

const long long INF = 1e17; // TODO CHANGE

int n, m, t0, t1, t2;
vector<pair<int, pair<int, bool>>> adj[100005]; // {u, {w, isBus}}
bool explored[100005];
long long dist[100005];

bool djikstra(int start) {
	for (int i = 0; i < n; i++) {
		dist[i] = INF;
		explored[i] = false;
	}
	dist[0] = start;
	set<pair<long long, int>> q;
	for(int i = 0; i < n; i++) q.insert({dist[i], i});

	while (!q.empty()) {
		int v = q.begin()->second;
		q.erase(q.begin());
		explored[v] = true;
		for (auto e : adj[v]) {
			if (explored[e.first]) continue;
			long long endTime = dist[v] + e.second.first;
			if (e.second.second && !(endTime <= t1 || dist[v] >= t2)) {
				endTime = t2 + e.second.first;
			}
			if (dist[e.first] > endTime) {
				q.erase({dist[e.first], e.first});
				dist[e.first] = endTime;
				q.insert({dist[e.first], e.first});
			}
		}
	}
	return dist[n - 1] <= t0;
} 

void solve() {
	cin >> n >> m >> t0 >> t1 >> t2;
	for (int i = 0; i < m; i++) {
		int u, v, w1, w2;
		cin >> u >> v >> w1 >> w2;
		u--; v--;
		adj[u].push_back({v, {w1, true}});
		adj[v].push_back({u, {w1, true}});
		adj[u].push_back({v, {w2, false}});
		adj[v].push_back({u, {w2, false}});
	}
	int low = 0;
	int high = t0 + 1;
	if (!djikstra(low)) {
		cout << -1 << endl;
		return;
	}
	while (high - low > 1) {
		int mid = (high + low) / 2;
		if (djikstra(mid)) low = mid;
		else high = mid;
	}
	cout << low << endl;
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
			explored[i] = false;
			dist[i] = 0;
		}
	}
	return 0;
}
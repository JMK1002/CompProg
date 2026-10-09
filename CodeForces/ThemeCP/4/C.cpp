#include <bits/stdc++.h>
using namespace std;

long long n, m, h;
bool horse[200005];
set<pair<long long, long long>> adj[400005];

vector<long long> djikstra(long long v) {
	vector<long long> dist(2 * n + 5);
	vector<bool> explored(2 * n + 5);
	for (long long i = 1; i <= 2 * n; i++) dist[i] = 1e18;
	dist[v] = 0;
	set<pair<long long, long long>> q;
	q.insert({dist[v], v});
	while (!q.empty()) {
		long long u = q.begin()->second;
		q.erase(q.begin());
		explored[u] = true;
		for (pair<long long, long long> e : adj[u]) {
			if (explored[e.first] || dist[e.first] <= dist[u] + e.second) continue;
			q.erase({dist[e.first], e.first});
			dist[e.first] = dist[u] + e.second;
			q.insert({dist[e.first], e.first});
		}
	}
	return dist;
}

void solve() {
	cin >> n >> m >> h;
	for (long long i = 0; i < h; i++) {
		long long x;
		cin >> x;
		horse[x] = true;
	}
	for (long long i = 0; i < m; i++) {
		long long u, v, w;
		cin >> u >> v >> w;
		adj[u].insert({v, w});
		adj[v].insert({u, w});
		adj[u + n].insert({v + n, w / 2});
		adj[v + n].insert({u + n, w / 2});
		if (horse[u]) adj[v].insert({u + n, w});
		if (horse[v]) adj[u].insert({v + n, w});
	}
	vector<long long> v1 = djikstra(1 + n * horse[1]);
	vector<long long> v2 = djikstra(n + n * horse[n]);
	long long ans = 1e18;
	for (long long i = 1; i <= n; i++) {
		ans = min(ans, min(min(max(v1[i], v2[i]), max(v1[i], v2[i + n])), min(max(v1[i + n], v2[i]), max(v1[i + n], v2[i + n]))));
	}
	if (ans == (long long) 1e18) cout << -1 << endl;
	else cout << ans << endl;
	for (long long i = 0; i <= n; i++) horse[i] = 0;
	for (long long i = 0; i <= 2 * n + 2; i++) adj[i].clear();
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	long long t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

long long n, m;
long long arr[200005];
vector<pair<long long, pair<long long, long long>>> edges;
set<pair<long long, long long>> adj[200005];
long long cnt[200005];

bool works(long long amnt) {
	for (long long i = 0; i <= n; i++) {
		adj[i].clear();
		cnt[i] = 0;
	}
	for (long long i = 0; i < amnt; i++) {
		auto edge = edges[i];
		adj[edge.second.first].insert({edge.second.second, edge.first});
	}
	cnt[0] = 0;
	for (long long i = 1; i < n; i++) cnt[i] = -1000000000000000000;
	for (long long i = 0; i < n; i++) {
		cnt[i] += arr[i];
		for (pair<long long, long long> e : adj[i]) {
			if (cnt[i] < e.second) continue;
			cnt[e.first] = max(cnt[e.first], cnt[i]);
		}
	}
	return cnt[n - 1] >= 0;
}

void solve() {
	cin >> n >> m;
	for (long long i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (long long i = 0; i < m; i++) {
		long long u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		edges.push_back({w, {u, v}});
	}
	sort(edges.begin(), edges.end());
	if (!works(m)) {
		cout << -1 << endl;
		return;
	}

	long long low = 0;
	long long high = m;
	while (high - low > 1) {
		long long mid = (low + high) / 2;
		if (works(mid)) high = mid;
		else low = mid;
	}

	cout << edges[high - 1].first << endl;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	long long t;
	cin >> t;
	while (t--) {
		solve();
		edges.clear();
	}
	return 0;
}
// 1
// 5 17
// 6 1 3 8 4
// 1 2 6
// 1 5 7
// 3 5 2
// 1 5 5
// 1 4 2
// 3 5 5
// 2 4 7
// 1 2 5
// 2 3 1
// 1 2 10
// 2 4 7
// 2 3 6
// 1 4 6
// 2 4 1
// 1 4 8
// 1 2 10
// 1 4 10
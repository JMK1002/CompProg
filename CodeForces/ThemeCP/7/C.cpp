#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[100005];
bool explored[100005];
int dist[100005];
int cnt[100005];

int bfs(int v) {
	for (int i = 0; i < n; i++) explored[i] = false;
	queue<pair<int, int>> q;
	q.push({v, 0});
	explored[v] = true;
	int res = v;
	while (!q.empty()) {
		int x = q.front().first;
		int w = q.front().second;
		dist[x] = max(w, dist[x]);
		res = x;
		q.pop();
		for (int e : adj[x]) {
			if (explored[e]) continue;
			q.push({e, w + 1});
			explored[e] = true;
		}
	}
	return res;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bfs(bfs(bfs(0)));
	for (int i = 0; i < n; i++) cnt[dist[i]]++;
	int ans = 1;

	for (int i = 0; i < n; i++) {
		ans += cnt[i];
		cout << min(ans, n) << " ";
	}	
	cout << endl;
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
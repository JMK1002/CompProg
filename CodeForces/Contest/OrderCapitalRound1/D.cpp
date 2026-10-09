#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;

int n, m;
vector<int> nodes[5005];
pair<int, int> dist[25000000];
vector<int> adj[5005];
int sz[5005];
int pre[5005];
int cnt = 0;

int sect(int v) {
	return lower_bound(pre + 1, pre + (n + 1), v) - pre;
}

int nxt(int v) {
	int s = sect(v);
	return nodes[s][(v - nodes[s][0] + 1) % sz[s]];
}

void solve() {
	cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		sz[u]++;
		sz[v]++;
	}
	for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + sz[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < sz[i]; j++) {
			nodes[i].push_back(++cnt);
		}
	}

	for (int i = 1; i <= cnt; i++) dist[i] = {INF, INF};
	dist[nodes[1][0]] = {0, 0};
	queue<int> q;
	q.push(nodes[1][0]);
	while (!q.empty()) {
		int v = q.front();
		q.pop();

		int t = dist[v].first;
		int nd = sect(v);
		int p = adj[nd][t % sz[nd]];
		p = nodes[p][(t + 1) % nodes[p].size()];
		if (dist[p] == make_pair(INF, INF)) {
			q.push(p);
		}
		dist[p] = min(dist[p], {dist[v].first + 1, dist[v].second});

		int asdf = nxt(v);
		if (dist[asdf] == make_pair(INF, INF)) {
			q.push(asdf);
		}
		dist[asdf] = min(dist[asdf], {dist[v].first + 1, dist[v].second + 1});
	}
	pair<int, int> ans = {INF, INF};
	for (int i : nodes[n]) {
		ans = min(ans, dist[i]);
	}
	cout << ans.first << " " << ans.second << endl;
	for (int i = 0; i <= cnt; i++) {
		dist[i] = {0, 0};
	}
	for (int i = 0; i <= n; i++) {
		nodes[i].clear();
		adj[i].clear();
		sz[i] = 0;
		pre[i] = 0;
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
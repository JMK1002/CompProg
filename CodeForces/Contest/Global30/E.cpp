#include <bits/stdc++.h>
using namespace std;

long long n, m;
set<pair<long long, long long>> adj[1000005]; // {v, ind}
long long w[1000005];
pair<long long, long long> edges[1000005];
vector<long long> inc; // increasing weight edge list
bool explored[1000005];
long long par[1000005];
long long sz[1000005];
vector<long long> added[1000005];

long long rt(long long a) {
	long long res = a;
	while (par[res] != res) res = par[res];
	while (a != res) {
		long long x = par[a];
		par[a] = res;
		a = x;
	}
	return res;
}

void combine(long long a, long long b) {
	long long ra = rt(a);
	long long rb = rt(b);
	if (ra == rb) return;
	if (sz[rb] < sz[ra]) swap(ra, rb);
	par[ra] = rb;
	sz[rb] += sz[ra];
	for (long long i : added[ra]) added[rb].push_back(i);
	added[ra].clear();
}

void bfs(long long x, long long maxInd) {
	queue<long long> q;
	q.push(x);
	explored[x] = true;
	while (!q.empty()) {
		long long v = q.front();
		q.pop();
		for (pair<long long, long long> e : adj[v]) {
			if (e.second > maxInd) continue;
			combine(x, e.first);
			if (explored[e.first]) continue;
			q.push(e.first);
			explored[e.first] = true;
		}
	}
}

void solve() {
	cin >> n >> m;
	long long ans = 0; // ! need to make a long long
	for (long long i = 0; i < m; i++) {
		long long u, v, x;
		cin >> u >> v >> x;
		u--; v--;
		edges[i] = {u, v};
		if (u != v) {
			adj[u].insert({v, i});
			adj[v].insert({u, i});
		}
		w[i] = x;
		ans += w[i];
		while (!inc.empty() && w[inc.back()] >= w[i]) inc.pop_back();
		inc.push_back(i);
	}
	for (long long i = 0; i < n; i++) {
		par[i] = i;
		sz[i] = 1;
		if (adj[i].size() % 2 == 1) added[i].push_back(i);
	}

	for (int i = 0; i < m; i++) {
		bfs(edges[i].first, i);
		bfs(edges[i].second, i);
		long long r = rt(edges[i].first);
		while (added[r].size() >= 2) {
			added[r].pop_back();
			added[r].pop_back();
			ans += w[i];
		}
	}
	cout << ans << endl;
	for (long long i = 0; i <= n; i++) {
		adj[i].clear();
		explored[i] = false;
		par[i] = 0;
		sz[i] = 0;
		added[i].clear();
	}
	for (long long i = 0; i <= m; i++) {
		w[i] = 0;
		edges[i] = {0, 0};
	}
	inc.clear();
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
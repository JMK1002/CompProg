#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
int nxt[200005];
bool explored[200005];
int dist[200005];

vector<int> dfs(int v) {
	int a = v;
	int b = nxt[v];
	vector<int> res;
	while (!explored[a] && a != b) {
		a = nxt[a];
		b = nxt[nxt[b]];
	}
	if (!explored[a]) {
		res.push_back(a);
		a = nxt[a];
		while (a != b) {
			res.push_back(a);
			a = nxt[a];
		}
		bool hasExplored = false;
		for (int i : res) if (explored[i]) hasExplored = true;
		if (hasExplored) res.clear();
	}

	while (v != a) {
		explored[v] = true;
		v = nxt[v];
	}
	for (int i : res) explored[i] = true;

	return res;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> nxt[i];
		nxt[i]--;
		dist[i] = -1;
	}
	for (int i = 0; i < n; i++) {
		if (!explored[i]) {
			vector<int> cycle = dfs(i);
			for (int i : cycle) dist[i] = 0;
		}
	}
	for (int i = 0; i < n; i++) explored[i] = (dist[i] == 0);
	for (int i = 0; i < n; i++) {
		if (dist[i] != -1) continue;
		vector<int> path;
		int a = i;
		while (dist[a] == -1) {
			path.push_back(a);
			a = nxt[a];
		}
		reverse(path.begin(), path.end());
		for (int i : path) {
			dist[i] = dist[a] + 1;
			a = i;
		}
	}
	int mx = 0;
	for (int i = 0; i < n; i++) mx = max(mx, dist[i]);
	cout << mx + 2 << endl;
	for (int i = 0; i <= n; i++) {
		explored[i] = 0;
		nxt[i] = 0;
		dist[i] = 0;
	}
}

signed main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}

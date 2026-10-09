#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
set<int> adj[200005];
int cnt[200005];
int sz[200005]; // number of leafs
int run = 0; // maximize run
int ignoredNode = -1;
int ans = 0;

void fillSz(int v, int p) {
	sz[v] = (adj[v].size() == 1 && ignoredNode != v);
	for (int e : adj[v]) {
		if (e == p) continue;
		fillSz(e, v);
		sz[v] += sz[e];
	}
}

void oddDfs(int v, int p) {
	cnt[v] = run;
	for (int e : adj[v]) {
		if (e == p) continue;
		if (sz[e] % 2 == 1) run++;
		else run--;
		oddDfs(e, v);
		// reversing it when going back up to parent
		if (sz[e] % 2 == 1) run--;
		else run++;
	}
}

void evenDfs(int v, int p) {
	for (int e : adj[v]) {
		if (e == p) continue;
		ans += (sz[e] % 2 == 1);
		evenDfs(e, v);
	}
}

void solve() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	int cntLeafs = 0;
	for (int i = 0; i < n; i++) cntLeafs += adj[i].size() == 1;
	int root = 0;
	while (adj[root].size() == 1) root++;

	fillSz(root, root);
	if (cntLeafs % 2 == 1) {
		oddDfs(root, root);
		ignoredNode = n;
		cnt[n] = -1e9;
		for (int i = 0; i < n; i++) if (adj[i].size() == 1 && cnt[i] > cnt[ignoredNode]) ignoredNode = i;
		fillSz(root, root);
	}
	evenDfs(root, root);

	cout << ans << endl;

	run = 0;
	ignoredNode = -1;
	ans = 0;
	for (int i = 0; i <= n; i++) {
		adj[i].clear();
		cnt[i] = 0;
		sz[i] = 0;
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

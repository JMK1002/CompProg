#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n;
set<int> adj[200005];
int dp[200005];
int par[200005];
vector<int> help[200005];

void dfs(int v, int p) {
	int cnt = 0;
	dp[v] = 0;
	for (int e : adj[v]) {
		if (e == p) continue;
		dfs(e, v);
		dp[v] += dp[e];
		cnt += (dp[e] == 0);
	}
	dp[v] += max(0, cnt - 1);
}

void dfs2(int v, int p) {
	par[v] = p;
	for (int e : adj[v]) {
		if (e == p) continue;
		dfs2(e, v);
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

	if (n == 2) {
		cout << 1 << endl; 
		return;
	}
	else if (n == 1) {
		cout << 0 << endl;
		return;
	}

	int rt = 0;
	for (int i = 0; i < n; i++) if (adj[i].size() > 1) rt = i;
	dfs2(rt, rt);
	for (int i = 0; i < n; i++) {
		if (adj[i].size() > 1) continue;
		int x = i;
		while (adj[x].size() - (par[x] != x) <= 1) {
			x = par[x];
		}
		help[x].push_back(i);
	}
	int ans = 1;
	for (int i = 0; i < n; i++) {
		if (help[i].size() >= 2) {
			dfs(help[i][0], help[i][0]);
			ans = dp[i];
			break;
		}
	}

	if (n == 1) ans = -1;
	cout << ans + 1 << endl;

}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
		for (int i = 0; i <= n; i++) {
			dp[i] = 0;
			adj[i].clear();
			help[i].clear();
			par[i] = 0;
		}
	}
	return 0;
}
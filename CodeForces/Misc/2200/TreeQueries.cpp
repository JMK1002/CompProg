#include <iostream>
#include <set>
using namespace std;

int n;
set<int> adj[200005];
int dp[200005];

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

void solve() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	int ans = n+2;
	for (int i = 0; i < n; i++) {
		dfs(i, i);
		ans = min(ans, dp[i]);
	}
	if (n == 1) ans = -1;
	cout << ans + 1 << endl;
	for (int i = 0; i <= n; i++) {
		dp[i] = 0;
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
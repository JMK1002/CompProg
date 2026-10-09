#include <bits/stdc++.h>
using namespace std;

#define int long long

pair<int, int> arr[1004];
set<int> adj[1004];
int ans[1004];
int col = 1;

void dfs(int v, int p) {
	ans[v] = col;
	for (int e : adj[v]) {
		if (e == p) continue;
		dfs(e, v);
	}
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first;
		arr[i].second = i;
	}

	sort(arr, arr + n);
	reverse(arr, arr + n);
	for (int i = 0; i < n; i++) {
		if (!adj[arr[i].second].empty()) continue;
		for (int j = 0; j < arr[i].first; j++) {
			cout << "? " << arr[i].second + 1 << endl;
			cout.flush();
			int x;
			cin >> x;
			x--;
			adj[arr[i].second].insert(x);
			adj[x].insert(arr[i].second);
			if (adj[x].size() != 1) break;
		}
	}

	for (int i = 0; i < n; i++) {
		if (!ans[i]) dfs(i, i);
		col++;
	}

	cout << "! ";
	for (int i = 0; i < n; i++) cout << ans[i] << " ";
	cout << endl;

	col = 1;
	for (int i = 0; i <= n; i++) {
		arr[i] = {0, 0};
		adj[i].clear();
		ans[i] = 0;
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

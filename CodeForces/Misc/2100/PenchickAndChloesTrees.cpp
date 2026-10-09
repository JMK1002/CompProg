#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int par[1000005];
set<int> adj[1000005];
int ans[1000005];

void dfs(int v) {
	multiset<int> st;
	for (int e : adj[v]) {
		dfs(e);
		st.insert(ans[e]);
	}
	while (st.size() > 1) {
		int a = *st.begin();
		int b = *++st.begin();
		st.erase(st.begin());
		st.erase(st.begin());
		st.insert(max(a, b) + 1);
	}
	ans[v] = *st.begin() + (adj[v].size() == 1);
}

void solve() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> par[i];
		par[i]--;
		adj[par[i]].insert(i);
	}
	dfs(0);
	cout << ans[0] << endl;
	for (int i = 0; i <= n; i++) {
		adj[i].clear();
		par[i] = 0;
		ans[i] = 0;
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
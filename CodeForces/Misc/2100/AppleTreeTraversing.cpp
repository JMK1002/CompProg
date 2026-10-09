#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int n;
set<int> adj[200005];
bool hasApple[200005];
bool explored[200005];
int par[200005];
int mx = 0;
int other; // other leaf in diameter

void dfs(int v, int p, int d) {
	mx = max(d, mx);
	par[v] = p;
	explored[v] = true;
	for (int e : adj[v]) {
		if (e == p) continue;
		dfs(e, v, d + 1);
	}
	if (mx == d) {
		other = max(other, v);
	}

}

pair<int, pair<int, int>> getDiameter(int v) {
	mx = 0;
	other = -1;
	dfs(v, v, 0);
	other = -1;
	dfs(v, v, 0);
	int b = other;
	mx = 0;
	other = -1;
	dfs(b, b, 0);
	other = -1;
	dfs(b, b, 0);
	int a = other;
	int cnt = 1;
	while (a != b) {
		hasApple[a] = false;
		for (int e : adj[a]) {
			adj[e].erase(a);
		}
		adj[a].clear();
		a = par[a];
		cnt++;
	}
	hasApple[b] = false;
	return {cnt, ((b > other) ? make_pair(b, other) : make_pair(other, b))};
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) hasApple[i] = true;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	vector<pair<int, pair<int, int>>> ans;
	while (true) {
		for (int i = 0; i < n; i++) {
			if (!hasApple[i] || explored[i]) continue;
			ans.push_back(getDiameter(i));
		}
		for (int i = 0; i < n; i++) explored[i] = false;
		bool keepGoing = false;
		for (int i = 0; i < n; i++) if (hasApple[i]) keepGoing = true;
		if (!keepGoing) break;
	}
	sort(ans.begin(), ans.end());
	reverse(ans.begin(), ans.end());
	for (auto p : ans) cout << p.first << " " << p.second.first+1<< " " << p.second.second+1 << " ";
	cout << endl;

	for (int i = 0; i <= n; i++) {
		adj[i].clear();
		hasApple[i] = false;
		explored[i] = false;
		par[i] = 0;
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
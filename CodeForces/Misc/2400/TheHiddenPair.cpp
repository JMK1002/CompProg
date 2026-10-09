#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
set<int> adj[1005];
int depth[1005];
int par[1005];
bool inPath[1005];
map<int, vector<int>> depthToNode;

void dfs(int v, int p) {
	par[v] = p;
	depth[v] = depth[p] + 1;
	depthToNode[depth[v]].push_back(v);
	for (int e : adj[v]) {
		if (e == p) continue;
		dfs(e, v);
	}
}

pair<int, int> q(vector<int> & v) {
	cout << "? " << v.size() << " ";
	for (int i : v) cout << i << " ";
	cout << endl;
	cout.flush();
	int x, d;
	cin >> x >> d;
	return make_pair(x, d);
}

void solve() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	vector<int> all;
	for (int i = 1; i <= n; i++) all.push_back(i);
	pair<int, int> res = q(all);
	int root = res.first;
	int len = res.second;

	depth[root] = -1; // makes depth[root] = 0 in the end
	dfs(root, root);
	int low = 0;
	int high = (--depthToNode.end())->first + 1;
	int farthestNodeInPath = root;
	while (high - low > 1) {
		int mid = (high + low) / 2;
		res = q(depthToNode[mid]);
		if (res.second == len) {
			low = mid;
			farthestNodeInPath = res.first;
		}
		else high = mid;
	}
	// ! This doesn't add the root which is good (consider case where root is the other endpoint)
	int run = farthestNodeInPath;
	while (run != root) {
		inPath[run] = true;
		run = par[run];
	}
	vector<int> allOnOtherSide;
	for (int i : depthToNode[len - low]) if (!inPath[i]) allOnOtherSide.push_back(i);
	int otherEnd = q(allOnOtherSide).first;
	cout << "! " << otherEnd << " " << farthestNodeInPath << endl;
	cout.flush();
	string verdict;
	cin >> verdict;

	for (int i = 0; i <= n; i++) {
		adj[i].clear();
		depth[i] = 0;
		par[i] = 0;
		inPath[i] = false;
	}
	depthToNode.clear();
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

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n, k;
set<int> adj[102];
int par[102];
pair<int, int> mx;
vector<int> ans;
int dCnt = 0;
int amnt = 0;

void dfs1(int v, int d) {
	for (int e : adj[v]) {
		dfs1(e, d + 1);
	}
	mx = max(mx, make_pair(d, v));
}

void dfs2(int v) {
	ans.push_back(v);
	if (ans.size() == amnt) return;
	set<int> two;
	set<int> one;
	for (int e : adj[v]) {
		if (adj[e].find(v) == adj[e].end()) one.insert(e);
		else two.insert(e);
	}
	int asdf = 0;
	while (dCnt > 0 && !two.empty()) {
		dCnt--;
		int e = *two.begin();
		adj[v].erase(e);
		two.erase(e);
		one.insert(e);
		dfs2(e);
		asdf++;
	}
	if (!asdf) dfs2(*one.begin());
}

void solve() {
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		cin >> par[i];
		par[i]--;
		adj[par[i]].insert(i);
	}
	dfs1(0, 0);
	for (int i = 1; i < n; i++) adj[i].insert(par[i]);
	int a = mx.second;
	while (a != 0) {
		adj[a].erase(par[a]);
		a = par[a];
	}
	dCnt = max(0, (k - (mx.first + 1)));
	amnt = dCnt * 2 + min(k, (mx.first + 1));
	dfs2(0);
	cout << amnt-1 << endl;
	for (int i : ans) cout << i+1 << " ";
	cout << endl;
	for (int i = 0; i <= n; i++) {
		adj[i].clear();
		par[i] = 0;
	}
	mx = {0, 0};
	ans.clear();
	dCnt = 0;
	amnt = 0;
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
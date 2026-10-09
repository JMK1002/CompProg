#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int n;
set<pair<int, int>> adj[500005];
vector<int> prts[500005];
int sz[500005];
int sm[500005];
int col[500005];
long long ans = 0;

void dfs(int v, int p) {
	sz[v] = 1;
	int st, ind;
	if (col[v] != -1) {
		st = sm[col[v]];
		ind = prts[col[v]].size();
	}
	for (pair<int, int> e : adj[v]) {
		if (e.first == p) continue;
		col[e.first] = e.second;
		dfs(e.first, v);
		sz[v] += sz[e.first];
	}
	if (col[v] == -1) return;
	long long cnt = 0;
	while (prts[col[v]].size() > ind) {
		cnt += prts[col[v]].back();
		prts[col[v]].pop_back();
	}
	int cmpSz = sz[v] - (sm[col[v]] - st);
	prts[col[v]].push_back(cmpSz);
	sm[col[v]] += cmpSz;
	ans += cnt * cmpSz;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].insert({v, c});
		adj[v].insert({u, c});
	}
	col[1] = -1;
	dfs(1, 1);

	for (int col = 1; col <= n; col++) {
		long long cnt = 0;
		while (!prts[col].empty()) {
			cnt += prts[col].back();
			prts[col].pop_back();
		}
		int cmpSz = n - sm[col];
		prts[col].push_back(cmpSz);
		sm[col] += cmpSz;
		ans += cnt * cmpSz;
	}

	cout << ans << endl;
	return 0;
}
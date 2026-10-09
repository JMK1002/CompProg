#include <bits/stdc++.h>
using namespace std;

int n, m;
int nxt[200005];
bool explored[200005];
vector<int> parties[200005];
int par[200005];
int sz[200005];
vector<pair<int, int>> qs;

int root(int a) {
	int res = a;
	while (par[res] != res) res = par[res];
	while (a != res) {
		int x = par[a];
		par[a] = res;
		a = x;
	}
	return res;
}

void join(int a, int b) { // ! a will be root
	int ra = root(a);
	int rb = root(b);
	if (ra == rb) return;
	sz[ra] += sz[rb];
	par[rb] = ra;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> nxt[i];
		nxt[i]--;
		par[i] = i;
		sz[i] = 1;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		char c;
		cin >> x >> c;
		x--;
		qs.push_back({x, 0});
		if (c == 'C') qs[i].second = 0;
		else if (c == 'O') qs[i].second = 1;
		else qs[i].second = 2;

		parties[qs[i].first].push_back(qs[i].second);
	}

	vector<int> run = {0, 0, 0};
	vector<int> ans[3];
	for (int i = 0; i < n; i++) {
		if (!parties[i].empty()) continue;
		join(nxt[i], i);
	}
	for (int i = 0; i < n; i++) {
		if (parties[i].empty()) continue;
		run[parties[i].back()] += sz[i];
	}
	
	reverse(qs.begin(), qs.end());
	for (pair<int, int> p : qs) {
		ans[0].push_back(run[0]);
		ans[1].push_back(run[1]);
		ans[2].push_back(run[2]);

		int i = p.first;
		run[parties[i].back()] -= sz[i];
		parties[i].pop_back();
		if (parties[i].empty()) {
			join(nxt[i], i);
			int r = root(nxt[i]);
			if (!parties[r].empty()) {
				run[parties[r].back()] += sz[i];
			}
		}
		else {
			run[parties[i].back()] += sz[i];
		}
	}
	reverse(ans[0].begin(), ans[0].end());
	reverse(ans[1].begin(), ans[1].end());
	reverse(ans[2].begin(), ans[2].end());
	for (int i = 0; i < m; i++) cout << ans[0][i] << " " << ans[1][i] << " " << ans[2][i] << endl; 
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	solve();
	return 0;
}
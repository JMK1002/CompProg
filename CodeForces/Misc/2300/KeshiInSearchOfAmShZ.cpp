#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
multiset<int> radj[200005];
multiset<int> adj[200005];
long long dp[200005];
bool explored[200005];
int cnt[200005];

void djikstra() {
	for (int i = 1; i <= n; i++) dp[i] = 1e9;
	dp[n] = 0;
	set<pair<int, int>> q;
	for (int i = 1; i <= n; i++) q.insert({dp[i], i});
	while (!q.empty()) {
		pair<int, int> v = *q.begin();
		q.erase(q.begin());
		explored[v.second] = true;
		for (int e : radj[v.second]) {
			if (explored[e]) continue;
			if (dp[v.second] + 1 + adj[e].size() - cnt[e] - 1 < dp[e]) {
				q.erase({dp[e], e});
				dp[e] = dp[v.second] + 1 + adj[e].size() - cnt[e] - 1;
				q.insert({dp[e], e});
			}
			cnt[e]++;
		}
	}
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].insert(v);
		radj[v].insert(u);
	}
	djikstra();
	cout << dp[1] << endl;
}
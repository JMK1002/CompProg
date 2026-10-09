#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int n, m;
vector<pair<pair<int, int>, int>> edges;
multiset<pair<int, int>> dp[100005]; // {edge weight, max length}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		edges.push_back({{u, v}, w});
	}

	for (int i = 0; i < n; i++) dp[i].insert({-1, 0});
	for (int i = 0; i < m; i++) {
		int u = edges[i].first.first;
		int v = edges[i].first.second;
		int w = edges[i].second;

		for (int j = 0; j < 1; j++) {
			auto p = *--dp[u].lower_bound({w, -1});
			auto prev = *--dp[v].lower_bound({w, p.second + 1});
			if (prev.second < p.second + 1) {
				auto ptr = dp[v].lower_bound({w, p.second + 1});
				while (ptr != dp[v].end() && ptr->second <= p.second + 1) {
					dp[v].erase(ptr);
					ptr = dp[v].lower_bound({w, p.second + 1});
				}
				dp[v].insert({w, p.second + 1});
			}
			swap(u, v);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) for (auto j : dp[i]) ans = max(ans, j.second);
	cout << ans << endl;
	return 0;
}
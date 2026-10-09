#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n, l = 100;
	cin >> n;
	vector<pair<int, int>> ans;
	for (int i = 1, run = 1; run < n; i++, run *= l) {
		for (int j = 1; j < l; j++) {
			int k = n / (l * run) * (l * run) + j * run;
			if (k > n) k -= l * run;
			for (; k > 0; k -= run * l) {
				ans.push_back({k, run});
			}
		}
	}
	cout << ans.size() << endl;
	for (auto p : ans) cout << p.first << " " << p.second << endl;
}

signed main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
// 1 2 3 4 5 6 7 8 9 10
// 1 2 1 4 1 2 1 8 1 2
// 1 1 3 1 1 3 1 1 9 1

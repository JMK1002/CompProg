#include <bits/stdc++.h>
using namespace std;

int n, m;
pair<int, int> tows[10005];

int getDist(pair<int, int> p) {
	int res = 1e9;
	for (int i = 0; i < m; i++) {
		res = min(res, abs(p.first - tows[i].first) + abs(p.second - tows[i].second));
	}
	return res;
}

int getVal(pair<int, int> p, pair<int, int> p2) {
	vector<int> res(4, 2e9);
	for (int i = 0; i < m; i++) {
		int x1 = tows[i].first;
		int y1 = tows[i].second;
		int x2 = p.first;
		int y2 = p.second;
		int d = abs(p.first - tows[i].first) + abs(p.second - tows[i].second);
		if (x1 <= x2 && y1 <= y2) res[0] = min(res[0], d); // a
		if (x1 > x2 && y1 <= y2) res[1] = min(res[1], d); // b
		if (x1 <= x2 && y1 > y2) res[2] = min(res[2], d); // c
		if (x1 > x2 && y1 > y2) res[3] = min(res[3], d); // d
	}

	return min((res[0] + res[2]) / 2, (res[1] + res[3]) / 2);
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> tows[i].first >> tows[i].second;
	}
	vector<pair<int, int>> pts;
	for (int i = 1; i <= n; i++) {
		pts.push_back({1, i});
		pts.push_back({i, 1});
		pts.push_back({n, i});
		pts.push_back({i, n});
	}
	int ans = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			pair<int, int> p = {tows[i].first, tows[j].second};
			int x = getVal(p);
			if (x >= 1e9) continue;
			ans = max(ans, getVal(p));
		}
	}
	for (pair<int, int> p : pts) {
		ans = max(ans, getDist(p));
	}
	cout << ans + 1 << endl;
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
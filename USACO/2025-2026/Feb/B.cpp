#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;

int n, m, k;
int prob[2][5005];
int pos[5005];
int temp[2][5005];
int dp[2][5005];
int t[5005][5005]; // tm[i][j], i is cw, j is ccw
int ans[1000005];

void solve() {
	cin >> n >> m >> k;
	// if (n == 5 && m == 10 && k == 13) {
	// 	cout << "0 0 0 125000001 375000003 0 125000001 375000003 0 0" << endl;
	// 	return;
	// }

	// k %= m;
	for (int i = 0; i < n; i++) {
		cin >> prob[0][i];
		prob[1][i] = (1 - prob[0][i] + mod) % mod;
	}
	for (int i = 0; i < n; i++) cin >> pos[i];
	vector<pair<int, int>> collisions;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			collisions.push_back({i, j});
			t[i][j] = (pos[j] < pos[i]) * m + pos[j] - pos[i];
		}
	}
	sort(collisions.begin(), collisions.end(), [&] (pair<int, int> a, pair<int, int> b) {
		return t[a.first][a.second] < t[b.first][b.second];
	});
	// for (pair<int, int> p : collisions) cout << t[p.first][p.second] << endl;

	dp[0][0] = prob[0][0];
	dp[1][0] = prob[1][0];
	int ptr = 0;
	int cnt = 0;
	for (int i = 1; i <= 2 * k; i++) {
		vector<pair<int, int>> cols;
		while (ptr < collisions.size() && t[collisions[ptr].first][collisions[ptr].second] + cnt * m == i) {
			cols.push_back(collisions[ptr]);
			ptr++;
			if (ptr == collisions.size()) {
				ptr = 0;
				cnt++;
			}
		}
		if (cols.empty()) {
			continue;
		}
		else {

			cout << "";
		}

		for (pair<int, int> p : cols) {
			int a = p.first;
			int b = p.second;
			int x = 0;
			int y = 0;
			x += prob[0][a] * ((1 - (dp[0][a] + dp[1][a]) + 2 * mod) % mod) % mod * dp[1][b] % mod;
			y += prob[1][a] * ((1 - (dp[1][a] + dp[0][a]) + 2 * mod) % mod) % mod * dp[1][b] % mod;
			x += prob[0][b] * dp[0][a] % mod;
			y += prob[1][b] * dp[0][a] % mod;

			x %= mod;
			y %= mod;
			temp[0][a] = x;
			temp[1][b] = y;
		}
		for (pair<int, int> p : cols) {
			int a = p.first;
			int b = p.second;
			dp[0][a] = temp[0][a];
			dp[1][b] = temp[1][b];
		}
		for (pair<int, int> p : cols) {
			int a = p.first;
			int b = p.second;
			temp[0][a] = 0;
			temp[1][b] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		ans[(pos[i] + k) % m] += dp[0][i];
		ans[(pos[i] - k + m * 1000000000) % m] += dp[1][i];
	}
	for (int i = 0; i < m; i++) {
		if (i != m - 1) cout << ans[i] % mod << " ";
		else cout << ans[i] % mod;
	}
	cout << endl;

	for (int i = 0; i <= n; i++) {
		prob[0][i] = 0;
		prob[1][i] = 0;
		pos[i] = 0;
		dp[0][i] = 0;
		dp[1][i] = 0;
		for (int j = 0; j <= n; j++) t[i][j] = 0;
	}
	for (int i = 0; i <= m; i++) ans[i] = 0;
}

signed main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int _;
	cin >> _;
	cout<<"";
	while (_--) {
		solve();
	}
	return 0;
}

// 5 10 3
// 1 1 1 0 1
// 0 3 4 7 9
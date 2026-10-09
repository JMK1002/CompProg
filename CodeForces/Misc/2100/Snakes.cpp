#include <iostream>
#include <vector>
using namespace std;

int n, q;
vector<pair<int, bool>> evs[22];
int dist[22][22];
int mxR[22];
int dp[2000000][22];

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> n >> q;
	for (int i = 0; i < q; i++) {
		int u;
		char c;
		cin >> u >> c;
		evs[u].push_back({i, (c == '+')});
		mxR[u] += (c == '+');
	}
	for (int i = 1; i <= n; i++) evs[i].push_back({10000000, false});
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			int r = 0;
			int l = 0;
			int iptr = 0;
			int jptr = 0;

			for (int k = 0; k <= evs[i].size() + evs[j].size() - 2; k++) {
				if (evs[i][iptr].first < evs[j][jptr].first) {
					r += evs[i][iptr].second;
					iptr++;
				}
				else {
					l += !evs[j][jptr].second;
					jptr++;
				}
				dist[i][j] = max(dist[i][j], r - l);
			}
		}
	}
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= n; j++) {
	// 		cout << dist[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	for (int i = 0; i < (1 << n); i++) {
		for (int cnt = 0, j = 1; cnt < n; j <<= 1, cnt++) {
			if ((i & j) == 0) continue;
			if (__builtin_popcount(i) == 1) {
				dp[i][cnt + 1] = 1;
				continue;
			}
			dp[i][cnt + 1] = 1000000000;
			for (int k = 1, asdf = 1; k <= n; asdf <<= 1, k++) {
				if ((asdf & (i ^ j)) == 0) continue;
				dp[i][cnt + 1] = min(dp[i][cnt + 1], dp[i ^ j][k] + dist[k][cnt + 1] + 1);
			}
		}
	}
	int ans = 1000000000;
	for (int i = 1; i <= n; i++) {
		ans = min(ans, dp[(1 << n) - 1][i] + mxR[i]);
	}
	cout << ans << endl;
	return 0;
}
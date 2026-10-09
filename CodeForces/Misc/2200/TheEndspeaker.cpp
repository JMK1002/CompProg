#include <iostream>
#include <vector>
using namespace std;

const long long mod = 1e9 + 7;
const long long INF = 2e18;

long long n, m;
long long a[300005];
long long pre[300005];
long long b[300005];
vector<long long> dp[300005];
vector<long long> cnt[300005];
vector<long long> preCnt[300005];

void solve() {
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i];
	}
	for (long long i = 1; i <= m; i++) cin >> b[i];
	for (long long i = 0; i <= n; i++) {
		dp[i] = vector<long long>(m + 2);
		cnt[i] = vector<long long>(m + 2);
		preCnt[i] = vector<long long>(m + 2);
	}

	for (long long i = 1; i <= n; i++) dp[i][0] = INF;
	for (int i = 0; i <= m; i++) {
		cnt[0][i] = 1;
		preCnt[0][i] = 1;
	}
	for (long long i = 1; i <= n; i++) {
		for (long long j = 1; j <= m; j++) {
			dp[i][j] = dp[i][j - 1];
			cnt[i][j] = cnt[i][j - 1];

			long long low = 0;
			long long high = i;
			if (pre[i] <= b[j]) low = high;
			while (high - low > 1) {
				long long mid = (low + high) / 2;
				if (pre[i] - pre[i - mid] <= b[j]) low = mid;
				else high = mid;
			}
			if (low == 0) {
				preCnt[i][j] = preCnt[i - 1][j] + cnt[i][j];
				preCnt[i][j] %= mod;
				continue;
			}

			if (dp[i][j] == dp[i - low][j] + (m - j)) {
				// int asdf = low;
				// while (asdf >= 1 && dp[i - asdf][j] == dp[i - low][j]) {
				// 	cnt[i][j] += cnt[i - asdf][j];
				// 	asdf--;
				// }
				int l = i - low;
				int r = i - 1;
				if (dp[r][j] == dp[i - low][j]) l = r;
				while (r - l > 1) {
					int mid = (l + r) / 2;
					if (dp[mid][j] == dp[i - low][j]) l = mid;
					else r = mid;
				}
				cnt[i][j] += ((preCnt[l][j] - (i - low == 0 ? 0 : preCnt[i - low - 1][j])) + mod) % mod;
				cnt[i][j] %= mod;

				// cnt[i][j] += cnt[i - low][j];
			}
			else if (dp[i][j] > dp[i - low][j] + (m - j)) {
				// int asdf = low;
				// cnt[i][j] = 0;
				// while (asdf >= 1 && dp[i - asdf][j] == dp[i - low][j]) {
				// 	cnt[i][j] += cnt[i - asdf][j];
				// 	asdf--;
				// }
				int l = i - low;
				int r = i - 1;
				if (dp[r][j] == dp[i - low][j]) l = r;
				while (r - l > 1) {
					int mid = (l + r) / 2;
					if (dp[mid][j] == dp[i - low][j]) l = mid;
					else r = mid;
				}
				cnt[i][j] = ((preCnt[l][j] - (i - low == 0 ? 0 : preCnt[i - low - 1][j])) + mod) % mod;
				cnt[i][j] %= mod;
				dp[i][j] = dp[i - low][j] + (m - j);
				// cnt[i][j] = cnt[i - low][j];
			}

			preCnt[i][j] = preCnt[i - 1][j] + cnt[i][j];
			preCnt[i][j] %= mod;
		}
	}
	if (dp[n][m] == INF) cout << -1 << endl;
	else cout << dp[n][m] << " " << cnt[n][m] << endl;

	for (long long i = 0; i <= n; i++) {
		a[i] = 0;
		pre[i] = 0;
		dp[i].clear();
		cnt[i].clear();
		preCnt[i].clear();
	}
	for (long long i = 0; i <= m; i++) {
		b[i] = 0;
	}
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	long long t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
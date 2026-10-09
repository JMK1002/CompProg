#include <bits/stdc++.h>
using namespace std;

long long n, k;
long long dp[65][65];
long long pre[65];

long long add(long long a, long long i) {
	long long run = 1 << i;
	long long res = 0;
	while (run & a) {
		res++;
		run <<= 1;
	}
	return res;
}


void solve() {
	cin >> n >> k;
	for (long long i = 1, run = 1; i <= 63; i++, run <<= 1) { // one indexed
		pre[i] = (bool) (run & n) + pre[i - 1];
	}
	for (long long r = 63, run = 1ll << 62; r >= 1; r--, run >>= 1) {
		// dp[r][r - (pre[r]) + 1] = pre[r] - 1;
		for (long long j = 1; j < 64; j++) {
			dp[r][j] = max(dp[r][j], dp[r + 1][j]);
			if (!(run & n)) continue;
			for (long long l = r + 1, run2 = 1 << r; l <= 63; l++, run2 <<= 1) {
				if (n & run2) continue;
				long long rng = pre[l] - pre[r - 1];
				if (j - (l - r + 1 - rng) < 0) continue;
				dp[r][j] = max(dp[r][j], dp[l + 1][j - (l - r + 1 - rng)] + rng - 1);
			}
		}
	}
	long long ans = 0;
	for (long long i = 0; i <= min(k, 32ll); i++) {
		ans = max(ans, dp[1][i] + k);
	}
	cout << ans << endl;
	for (long long i = 0; i <= 63; i++) {
		for (long long j = 0; j <= 63; j++) {
			dp[i][j] = 0;
		}
		pre[i] = 0;
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

//2147483647
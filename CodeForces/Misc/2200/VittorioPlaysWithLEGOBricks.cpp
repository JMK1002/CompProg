#include <iostream>
using namespace std;

long long n, h;
long long dp[302][302];
long long arr[302];

void solve() {
	cin >> n >> h;
	for (long long i = 0; i < n; i++) cin >> arr[i];
	for (long long j = 0; j < n; j++) {	
		for (long long i = 0; i < n - j; i++) {
			long long l = i;
			long long r = i + j;
			if (j == 0) {
				dp[l][r] = h;
				continue;
			}
			dp[l][r] = 1e18;
			for (long long k = l; k < r; k++) {
				dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] - max(0ll, h - (arr[r] - arr[l] - 1) / 2));
			}
		}
	}
	cout << dp[0][n - 1] << endl;

	for (long long i = 0; i <= n; i++) for (long long j = 0; j <= n; j++) {
		dp[i][j] = 0;
	}
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	long long t=1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
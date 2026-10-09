#include <iostream>
using namespace std;

long long n;
long long arr[402];
long long dp[402][402];

void solve() {
	cin >> n;
	for (long long i = 0; i < n; i++) cin >> arr[i];
	for (long long i = 1; i < n; i++) {
		for (long long l = 0; l < n; l++) {
			long long r = (l + i) % n;

			for (long long j = l + 1; j < r + (r < l) * n; j++) {
				dp[l][r] = max(dp[l][r], arr[j%n] * arr[l] * arr[r] + ((l + 1)%n != j%n)*dp[(l + 1)%n][(j - 1 + n)%n] + ((j + 1)%n != r)*dp[(j + 1)%n][(r - 1 + n)%n]);
			}
			for (long long j = l; j < r + (r < l) * n; j++) {
				dp[l][r] = max(dp[l][r], dp[l][j%n] + dp[(j + 1)%n][r]);
			}
		}
	}
	long long ans = 0;
	for (long long i = 0; i < n; i++) ans = max(ans, dp[i][(i + n - 1)%n]);
	cout << ans << endl;
	for (long long i = 0; i <= n; i++) for (long long j = 0; j <= n; j++) {
		dp[i][j] = 0;
	}
}

int main() {
	long long t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
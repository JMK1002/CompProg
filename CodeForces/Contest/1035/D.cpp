#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

long long dp[5005][5005];

void solve() {
	long long n, mod;
	cin >> n >> mod;
	dp[n][0] = 1;
	dp[n][1] = n;
	for (long long i = n - 1; i >= 1; i--) {
		for (long long j = 0; j <= n - i + 1; j++) {
			dp[i][j] = dp[i + 1][j] + (j != 0) * (i * (n - i - j + 2) % mod * dp[i + 1][j - 1] % mod);
			dp[i][j] %= mod;
		}
	}
	long long ans = 0;
	for (long long i = 0; i <= n; i++) {
		ans += dp[1][i];
		ans %= mod;
	}
	cout << ans << endl;
	for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) dp[i][j] = 0;
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
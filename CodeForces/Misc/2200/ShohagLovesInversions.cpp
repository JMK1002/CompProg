#include <iostream>
using namespace std;

long long n;
long long dp[1000005];
const long long mod = 998244353;

void solve() {
	cin >> n;
	long long ans = n - 1;
	long long run = 8;
	dp[4] = 2;
	for (long long i = 5; i <= n; i++) {
		dp[i] = run + (i - 2) * (i - 1) % mod * 499122177 % mod + 998244352;
		dp[i] %= mod;
		run += i * dp[i] % mod;
		run %= mod;
	}
	for (long long i = 4; i <= n; i++) {
		ans += dp[i];
		ans %= mod;
	}
	cout << ans << endl;
	for (long long i = 0; i <= n; i++) dp[i] = 0;
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
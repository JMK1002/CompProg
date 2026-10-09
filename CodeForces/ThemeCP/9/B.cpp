#include <bits/stdc++.h>
using namespace std;

const long long mod = 998244353;

long long n;
long long dp[400010];
long long dp2[400010];

void solve() {
	cin >> n;
	const long long asdf = 200004;
	for (long long i = 0; i < n; i++) {
		long long x;
		cin >> x;
		dp[asdf - i + x] += dp[asdf - (i - 1) + x];
		dp[asdf - i + x] %= mod;
		dp[asdf - i] = 1;
	}
	long long ans = 0;
	for (long long i = asdf - n - 1; i <= asdf + n + 1; i++) {
		ans += dp[i];
		ans %= mod;
	}
	cout << ans << endl;
	for (long long i = asdf - n - 1; i <= asdf + n + 1; i++) dp[i] = 0;
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
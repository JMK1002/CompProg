#include <bits/stdc++.h>
using namespace std;

long long n;
long long dp[2][100005]; // [0] is mn, [1] is mx
long long a[100005];
long long b[100005];

void solve() {
	cin >> n;
	for (long long i = 1; i <= n; i++) cin >> a[i];
	for (long long i = 1; i <= n; i++) cin >> b[i];
	for (long long i = 1; i <= n; i++) {
		long long x = dp[0][i - 1] - a[i];
		long long y = dp[1][i - 1] - a[i];
		long long z = b[i] - dp[0][i - 1];
		long long w = b[i] - dp[1][i - 1];
		dp[0][i] = min(min(x, y), min(z, w));
		dp[1][i] = max(max(x, y), max(z, w));
	}
	cout << dp[1][n] << endl;
	for (long long i = 0; i <= n; i++) {
		a[i] = 0;
		b[i] = 0;
		dp[1][i] = 0;
		dp[0][i] = 0;
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
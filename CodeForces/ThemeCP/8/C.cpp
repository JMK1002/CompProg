#include <bits/stdc++.h>
using namespace std;

long long n;
long long arr[200005];
long long dp[200005];

void solve() {
	cin >> n;
	for (long long i = 0; i < n; i++) cin >> arr[i];

	long long ans = 1e18;
	for (int i = 0; i < n; i++) dp[i] = 0;
	dp[0] = 1e15;
	for (long long k = 0; k < 3; k++) {
		for (long long i = 1; i < n; i++) {
			if (i == 1) dp[i] = abs(arr[i] - arr[i - 1]);
			if (i > 1) dp[i] = dp[i - 2] + abs(arr[i] - arr[i - 1]);
			if (i == 2) dp[i] = min(dp[i], max(max(arr[i], arr[i - 1]), arr[i - 2]) - min(min(arr[i], arr[i - 1]), arr[i - 2]));
			if (i > 2) dp[i] = min(dp[i], dp[i - 3] + max(max(arr[i], arr[i - 1]), arr[i - 2]) - min(min(arr[i], arr[i - 1]), arr[i - 2]));
		}
		ans = min(ans, dp[n - 1]);
		long long x = arr[n - 1];
		for (long long i = n - 1; i >= 1; i--) arr[i] = arr[i - 1];
		arr[0] = x;
		for (long long i = 0; i < n; i++) dp[i] = 0;
		dp[0] = 1e15;
	}
	cout << ans << endl;
	for (int i = 0; i <= n; i++) {
		dp[i] = 0;
		arr[i] = 0;
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
#include <bits/stdc++.h>
using namespace std;

long long n;
long long arr[200005];
long long dp[200005];
long long pre[200005];
long long mn[200005];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		pre[i] = pre[i - 1] + arr[i];
	}
	mn[n + 1] = 1e16;
	mn[n + 2] = 1e16;
	for (int i = n; i >= 1; i--) {
		dp[i] = arr[i] + dp[i + 1];
		if (i != n) {
			dp[i] = min(dp[i], arr[i] + max(arr[i + 1] - i, 0ll) + pre[n] - pre[i + 1] - (n - (i + 1)));
		}
		dp[i] = min(dp[i], arr[i] + max(0ll, arr[i + 1] - i) - pre[i + 1] + i + 2 + mn[i + 2]);
		mn[i] = min(mn[i + 1], dp[i] + pre[i - 1] - i);
	}
	cout << dp[1] << endl;
	for (int i = 0; i <= n + 3; i++) {
		arr[i] = 0;
		dp[i] = 0;
		pre[i] = 0;
		mn[i] = 0;
	}
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
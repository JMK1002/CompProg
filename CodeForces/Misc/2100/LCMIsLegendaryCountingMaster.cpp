#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int n, m;
int arr[3005];
int dp[3005][3005];

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	if (arr[0] == 0) dp[0][1]++;
	else dp[0][arr[0]]++;
	for (int i = 1; i < n; i++) {
		if (arr[i] != 0) {
			for (int j = 1; j * j <= arr[i]; j++) {
				if (arr[i] % j != 0) continue;
				dp[i][arr[i]] += dp[i - 1][arr[i] - j];
				dp[i][arr[i]] %= mod;
				if (j * j != arr[i]) dp[i][arr[i]] += dp[i - 1][arr[i] - arr[i] / j];
				dp[i][arr[i]] %= mod;
			}
		}
		else {
			for (int k = 1; k <= m; k++) {
				for (int j = k; j <= m; j += k) {
					if (j + k > m) break;
					dp[i][j + k] += dp[i - 1][j];
					dp[i][j + k] %= mod;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= m; i++) {
		ans += dp[n - 1][i];
		ans %= mod;
	}
	if (!(arr[0] == 0 || arr[0] == 1)) ans = 0;
	cout << ans << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++) dp[i][j] = 0;
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
	return 0;
}
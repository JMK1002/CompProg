#include <bits/stdc++.h>
using namespace std;

const long long inf = 1e18;

int n;
int arr[200005];
pair<long long, int> dp[200005][3];
int inv[200005];
int ans[200005];

void solve() {
	cin >> n;
	iota(inv, inv + (n + 1), 0);
	for (int i = 1; i <= n; i++) cin >> arr[i];
	sort(inv + 1, inv + (n + 1), [&] (int a, int b) {
		return arr[a] < arr[b];
	});
	sort(arr+1, arr + (n+1));
	dp[0][0] = {inf, -1};
	dp[0][1] = {inf, -1};
	dp[0][2] = {0, -1};
	for (int i = 1; i <= n; i++) {
		dp[i][0] = {dp[i - 1][2].first - arr[i], 2};
		dp[i][1] = {min(dp[i - 1][0].first, dp[i - 1][1].first), dp[i - 1][0].first > dp[i - 1][1].first};
		dp[i][2] = {dp[i - 1][1].first + arr[i], 1};
	}
	int cnt = 1;
	int a = 2;
	for (int i = n; i >= 1; i--) {
		ans[inv[i]] = cnt;
		cnt += dp[i][a].second == 2;
		a = dp[i][a].second;
	}
	cout << dp[n][2].first << " " << cnt - 1 << endl;
	for (int i = 1; i <= n; i++) cout << ans[i] << " ";
	cout << endl;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

void solve() {
	
}
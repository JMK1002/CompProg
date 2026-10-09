#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 998244353;

int n;
string s;
int dp[300005];
int pre[300005];

void solve() {
	cin >> n >> s;
	s = "_" + s;
	int cnt = 0;
	int tot = 0;
	int tot2 = 0;
	int lst = -1;
	for (int i = 1; i <= n; i++) {
		cnt -= s[i] == ')';
		cnt += s[i] == '(';

		pre[i] += pre[i - 1];
		pre[i] %= mod;

		if (s[i] == '(') {
			dp[i] = tot + 1;
			dp[i] %= mod;
			pre[i] += dp[i];
			pre[i] %= mod;
		}
		else {
			dp[i] = tot2 + 1;
			dp[i] += pre[i] - pre[lst] + mod;
			dp[i] %= mod;

			tot2 += dp[i];
			tot2 %= mod;
		}

		if (cnt <= 1) lst = i;
		tot += dp[i] * (cnt != 1 || s[i] != '(');
		tot %= mod;
	}

	int ans = 0;
	int run = 1;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '(') ans += run;
		else ans += dp[i];
		ans %= mod;
		run *= 2;
		run %= mod;
	}
	cout << ans << endl;

	for (int i = 0; i <= n; i++) {
		dp[i] = 0;
		pre[i] = 0;
	}
}

signed main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}

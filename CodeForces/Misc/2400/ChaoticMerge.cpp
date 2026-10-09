#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int MOD = 998244353;

int add(int a, int b){
	a += b;
	if (a >= MOD)
		a -= MOD;
	if (a < 0)
		a += MOD;
	return a;
}

int main() {
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(2, 0)));
	int ans = 0;
	forn(i, n + 1) forn(j, m + 1){
		if (i < n) dp[i + 1][j][0] = add(dp[i + 1][j][0], 1);
		if (j < m) dp[i][j + 1][1] = add(dp[i][j + 1][1], 1);
		if (0 < i && i < n && s[i - 1] != s[i]) dp[i + 1][j][0] = add(dp[i + 1][j][0], dp[i][j][0]);
		if (0 < j && i < n && t[j - 1] != s[i]) dp[i + 1][j][0] = add(dp[i + 1][j][0], dp[i][j][1]);
		if (0 < i && j < m && s[i - 1] != t[j]) dp[i][j + 1][1] = add(dp[i][j + 1][1], dp[i][j][0]);
		if (0 < j && j < m && t[j - 1] != t[j]) dp[i][j + 1][1] = add(dp[i][j + 1][1], dp[i][j][1]);
		ans = add(ans, dp[i][j][0]);
		ans = add(ans, dp[i][j][1]);
	}
	forn(i, n){
		int j = i;
		while (j + 1 < n && s[j] != s[j + 1]) ++j;
		int len = j - i + 1;
		int val = (len * 1ll * (len + 1) / 2) % MOD * (m + 1) % MOD;
		ans = add(ans, -val);
		i = j;
	}
	forn(i, m){
		int j = i;
		while (j + 1 < m && t[j] != t[j + 1]) ++j;
		int len = j - i + 1;
		int val = (len * 1ll * (len + 1) / 2) % MOD * (n + 1) % MOD;
		ans = add(ans, -val);
		i = j;
	}
	printf("%d\n", ans);
	return 0;
}

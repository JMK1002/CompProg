#include <bits/stdc++.h>

using namespace std;

string s;

int dp[5002], lcs[5002][5002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, a, b;
	cin >> n >> a >> b;
	cin >> s;
	for(int i = 1; i <= n; i++) {
		dp[i] = dp[i-1] + a;
		for(int j = 1; j < i; j++) {
			lcs[i][j] = (s[i-1] == s[j-1]) ? lcs[i-1][j-1] + 1: 0;
			dp[i] = min(dp[i], dp[max(j, i - lcs[i][j])] + b);
		}
	}
	cout << dp[n] << "\n";
}
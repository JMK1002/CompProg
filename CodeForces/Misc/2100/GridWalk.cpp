#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long n, a, b;

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> n >> a >> b;
	long long ans = 0;
	for (long long i = 1; i <= n; i++) ans += __gcd(i, a) + __gcd(i, b);
	long long x = n;
	long long y = n;
	while (__gcd(x, a) != 1) x--;
	while (__gcd(y, b) != 1) y--;

	if (x == n || y == n) {
		ans += (n - 1) * 2;
		cout << ans << endl;
		return 0;
	}

	ans += x - 1 + y - 1;
	vector<vector<long long>> dp((n - x) + 1);
	for (vector<long long> & v : dp) {
		vector<long long> temp((n - y) + 1);
		v = temp;
	}
	for (long long i = 0; i < dp.size(); i++) dp[i][0] = i;
	for (long long i = 0; i < dp[0].size(); i++) dp[0][i] = i;
	for (long long i = 1; i < dp.size(); i++) {
		for (long long j = 1; j < dp[0].size(); j++) {
			dp[i][j] = min(dp[i - 1][j] + __gcd(j + y, b), dp[i][j - 1] + __gcd(i + x, a));
		}
	}
	ans += dp.back().back();
	cout << ans << endl;
	return 0;
}
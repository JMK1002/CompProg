#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long mod = 998244353;

long long n;
vector<long long> vals[2];
vector<long long> dp[2];

void solve() {
	cin >> n;
	vals[0].push_back(0);
	dp[0].push_back(0);
	long long ans = 0;
	for (long long i = 1; i <= n; i++) {
		long long a;
		cin >> a;
		long long j = 1;
		for (; j * j <= a; j++) {
			vals[1].push_back(j);
			long long d;
			if (a % j == 0) {
				long long k = a / j;
				d = i * (k - 1) + dp[0][upper_bound(vals[0].begin(), vals[0].end(), j) - vals[0].begin() - 1];
			}
			else {
				long long k = a / j + (a % j != 0);
				d = i * (k - 1) + dp[0][upper_bound(vals[0].begin(), vals[0].end(), j - 1) - vals[0].begin() - 1];
			}
			d %= mod;
			dp[1].push_back(d);
		}
		for (; j >= 1; j--) {
			if (vals[1].back() >= a / j + (a % j != 0)) continue;
			vals[1].push_back(a / j + (a % j != 0));
			long long k = j;
			long long d = i * (k - 1) + dp[0][upper_bound(vals[0].begin(), vals[0].end(), a / j) - vals[0].begin() - 1];
			d %= mod;
			dp[1].push_back(d);
		}

		ans += dp[1].back();
		ans %= mod;

		vals[0] = vals[1];
		dp[0] = dp[1];
		vals[1].clear();
		dp[1].clear();
	}
	cout << ans << endl;

	vals[0].clear();
	dp[0].clear();
	vals[1].clear();
	dp[1].clear();
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
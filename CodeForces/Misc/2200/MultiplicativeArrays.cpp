#include <iostream>
#include <vector>
using namespace std;

const long long mod = 998244353;

long long k, n;
vector<long long> divs[100005];
long long dp[2][100005];
long long ans[2][100005];

void mv() {
	for (long long i = 1; i <= k; i++) {
		dp[0][i] = dp[1][i];
		dp[1][i] = 0;
		ans[0][i] = ans[1][i];
	}
}

void solve() {
	cin >> k >> n;
	for (long long i = 1; i <= k; i++) {
		dp[1][i] = 0;
		ans[1][i] = 0;
	}
	mv();
	mv();
	dp[0][1] = 1;
	long long curr = 0;
	long long h = 1;
	while (h <= n) h <<= 1;
	h >>= 1;
	while (h) {
		curr <<= 1;

		for (long long i = 1; i <= k; i++) {
			for (long long j : divs[i]) {
				dp[1][i] += dp[0][j] * dp[0][i / j] % mod;
				dp[1][i] %= mod;

				ans[1][i] += ans[0][j] * dp[0][i / j] % mod;
				ans[1][i] %= mod;
			}
		}
		mv();

		if (h & n) {
			curr++;
			for (long long i = 1; i <= k; i++) {
				for (long long j : divs[i]) {
					dp[1][i] += dp[0][j];
					dp[1][i] %= mod;
				}
				ans[1][i] += dp[1][i];
				ans[1][i] %= mod;
			}
			mv();
		}
		h >>= 1;
	}
	for (long long i = 1; i <= k; i++) cout << ans[0][i] << " ";
	cout << endl;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	for (long long i = 1; i <= 100000; i++) {
		for (long long j = 1; j * j <= i; j++) {
			if (i % j != 0) continue;
			divs[i].push_back(j);
			if (j * j != i) divs[i].push_back(i / j);
		}
	}

	long long t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
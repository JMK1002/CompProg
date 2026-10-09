#include <iostream>
using namespace std;

const long long mod = 1e9+7;

long long n, c, m;
long long dp[102][10004];
long long fact[200];
long long invFact[200];

long long inv(long long a) {
	return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

long long ch(long long a, long long b) {
	return fact[a] * invFact[b] % mod * invFact[a - b] % mod;
}

void solve() {
	cin >> n >> c >> m;
	int temp;
	for (int i = 0; i < m; i++) cin >> temp;
	for (long long i = 0; i <= m; i++) dp[1][i] = 0;
	dp[1][c] = 1;
	for (long long i = 2; i <= n; i++) {
		for (long long j = c; j <= m; j++) {
			dp[i][j] = 0;
			for (long long k = 0; k <= c; k++) {
				dp[i][j] += dp[i - 1][j - k] * ch(c, k) % mod;
				dp[i][j] %= mod;
			}
		}
	}
	cout << dp[n][m] << endl;
	for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) dp[i][j] = 0;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	long long t;
	cin >> t;
	fact[0] = 1;
	invFact[0] = 1;
	for (long long i = 1; i < 200; i++) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= mod;
		invFact[i] = inv(fact[i]);
	}
	while (t--) {
		solve();
	}
	return 0;
}

// dp[i][j] is for n=i and m=j and const c
// dp[i][j] = for (long long k = 0; k <= c; k++) dp[i - 1][j - k] * (c choose k)
// dp[1][c] = 1;
// dp[i][j] = 0 for j < c
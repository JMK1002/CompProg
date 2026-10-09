#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e6 + 5;
const int mod = 1e9 + 7;

int n, m, k;
int fact[MAXN], invFact[MAXN];

int binpow(int a, int b) {
	int res = 1;
	int run = a;
	while (b) {
		if (b & 1) res *= run;
		run *= run;
		res %= mod;
		run %= mod;
		b >>= 1;
	}
	return res;
}

int inv(int a) {
	return binpow(a, mod - 2);
}

int choose(int a, int b) {
	if (b > a || a < 0) return 0;
	return fact[a] * invFact[b] % mod * invFact[a - b] % mod;
}

void solve() {
	cin >> n >> m >> k;
	int ans = 0;

	// dp[n][m] = k * sum_i=0^(m) (m - i) * ((n - m + i - 1) choose i) * 1/2^(n - m + i)
	for (int i = 0; i <= m; i++) {
		int temp = m - i;
		temp *= choose(n - m + i - 1, i);
		temp %= mod;
		temp *= binpow(inv(2), n - m + i);
		temp %= mod;
		ans += temp;
		ans %= mod;
	}
	ans *= k;
	ans %= mod;
	if (n == m) ans = k * n % mod;
	cout << ans << endl;
}

signed main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	fact[0] = 1;
	invFact[0] = 1;
	for (int i = 1; i <= 1000000; i++) {
		fact[i] = fact[i - 1] * i % mod;
		invFact[i] = inv(fact[i]);
	}
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}

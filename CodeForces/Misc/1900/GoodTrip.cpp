#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;
long long fact[200005];

long long n, m, k;

long long bin(long long a, long long b) {
	long long res = 1;
	long long run = a;
	while (b) {
		if (b & 1) res *= run;
		res %= mod;
		run *= run;
		run %= mod;
		b >>= 1;
	}
	return res % mod;
}

void solve() {
	cin >> n >> m >> k;
	vector<long long> v;
	long long ans = 0;
	for (long long i = 0; i < m; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		v.push_back(c);
		ans += c;
		ans %= mod;
	}
	ans *= bin(n * (n - 1) / 2 % mod, mod - 2) % mod;
	ans %= mod;
	ans *= k % mod;
	ans %= mod;
 	for (long long i = 1; i <= k; i++) {
		ans += i * (i - 1) / 2 % mod * m % mod % mod *
			bin(bin(n * (n - 1) / 2 % mod, (mod - 2) % mod) % mod, i) % mod *
			bin((n * (n - 1) / 2 - 1) % mod * bin(n * (n - 1) / 2 % mod, (mod - 2) % mod) % mod, k - i) % mod
			* fact[k] % mod * bin(fact[i], mod - 2) % mod * bin(fact[k - i], mod - 2) % mod;
		ans %= mod;
	}
	cout << ans << endl;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	long long t;
	cin >> t;
	fact[0] = 1;
	for (int i = 1; i < 200005; i++) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= mod;
	}
	while (t--) {
		solve();
	}
	return 0;
}
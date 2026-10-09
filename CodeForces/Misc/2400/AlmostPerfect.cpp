#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 998244353;
int fact[300005];
int invFact[300005];
int cnt[300005];

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

int ch(int a, int b) {
	return fact[a] * invFact[b] % mod * invFact[a - b] % mod;
}

void solve() {
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i <= n / 4; i++) {
		ans += ch(n - 2 * i, 2 * i) * fact[2 * i] % mod * invFact[i] % mod * cnt[n - 4 * i] % mod;
		ans %= mod;
	}
	cout << ans << endl;
}

signed main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	fact[0] = 1;
	invFact[0] = 1;
	for (int i = 1; i <= 300000; i++) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= mod;
		invFact[i] = binpow(fact[i], mod - 2);
	}
	cnt[1] = 1;
	cnt[0] = 1;
	for (int i = 2; i <= 300000; i++) {
		cnt[i] = cnt[i - 2] * (i - 1) + cnt[i - 1];
		cnt[i] %= mod;
	}
	while (t--) {
		solve();
	}
	return 0;
}

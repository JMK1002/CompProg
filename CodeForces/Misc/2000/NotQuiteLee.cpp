#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9+7;

int n;
int cntPows[40];
int fact[200005];
int invFact[200005];

int binpow(int a, int b) {
	int res = 1;
	int run = a;
	while (b) {
		if (b & 1) res *= run;
		run *= run;
		b >>= 1;
		run %= mod;
		res %= mod;
	}
	return res;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		int cnt = 0;
		while (!(x & 1)) {
			x >>= 1;
			cnt++;
		}
		cntPows[cnt]++;
	}
	int tot = 0;
	for (int i = 0; i < 40; i++) tot += cntPows[i];
	int res = 0;
	res += binpow(2, tot) - binpow(2, tot - cntPows[0]) + mod;
	res %= mod;
	tot -= cntPows[0];
	for (int i = 1; i < 40; i++) {
		tot -= cntPows[i];
		int run = 0;
		for (int j = 2; j <= cntPows[i]; j += 2) {
			// cntPows[i] choose j
			run += fact[cntPows[i]] * invFact[j] % mod * invFact[cntPows[i] - j] % mod;
			run %= mod;
		}
		run *= binpow(2, tot);
		run %= mod;
		res += run;
		res %= mod;
	}
	cout << res << endl;
	for (int i = 0; i < 40; i++) cntPows[i] = 0;
}

signed main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	fact[0] = 1;
	invFact[0] = 1;
	for (int i = 1; i <= 200000; i++) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= mod;
		invFact[i] = binpow(fact[i], mod - 2);
	}
	int t=1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 998244353;

int n, k;
int arr[200005];

int binpow(int a, int b) {
	int res = 1;
	int run = a;
	while (b) {
		if (b & 1) res *= run;
		run *= run;
		run %= mod;
		res %= mod;
		b >>= 1;
	}
	return res;
}

int inv(int a) {
	return binpow(a, mod - 2);
}

void solve() {
	cin >> n >> k;
	int en = n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (i != 0 && arr[i] == arr[i - 1]) {
			en--;
		}
	}
	en -= arr[n - 1] == arr[0];

	int ch = 1;
	int ans = 0;
	int ch2 = 1;
	for (int i = 0; i <= en; i++) {
		ans += binpow(k - 2, en - i) * (((binpow(2, i) - ch * (1 - i % 2) % mod) % mod + mod) % mod) % mod * inv(2) % mod * ch2 % mod;
		ans %= mod;
		ch2 *= (en - i) * inv(i + 1) % mod;
		ch2 %= mod;
		if (i % 2 == 0) ch = ch * (i + 1) % mod * (i + 2) % mod * inv(i / 2 + 1) % mod * inv(i / 2 + 1) % mod;
	}
	ans *= binpow(k, n - en);
	ans %= mod;
	cout << ans << endl;
}

signed main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}

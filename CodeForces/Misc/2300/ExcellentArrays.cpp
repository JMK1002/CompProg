#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;

int n, l, r;

int binpow(int a, int b) {
	int res = 1;
	int run = a;
	while (b) {
		if (b & 1) res *= run;
		res %= mod;
		run *= run;
		run %= mod;
		b >>= 1;
	}
	return res;
}

int inv(int a) {
	return binpow(a, mod - 2);
}

int ch(int a, int b) {
	int res = 1;
	for (int i = 1; i <= a; i++) {
		res *= i;
		res %= mod;
	}
	for (int i = 1; i <= a - b; i++) {
		res *= inv(i);
		res %= mod;
	}
	for (int i = 1; i <= b; i++) {
		res *= inv(i);
		res %= mod;
	}
	return res;
}

void solve() {
	cin >> n >> l >> r;
	int ans = 0;
	for (int _ = -1; _ < n % 2; _++) {
		int cnt[] = {n / 2, n - n / 2}; // need to account for when n % 2 == 1 and swapped
		if (_ == 0) swap(cnt[0], cnt[1]);
		int curr = ch(n, cnt[0]);
		ans += min(r - n, 1 - l) * curr;
		for (int i = min(r - n, 1 - l) + 1; ; i++) {
			bool a = n + i > r;
			bool b = 1 - i < l; 
			cnt[0] -= a;
			cnt[1] -= b;
			int x = cnt[0];
			int z = cnt[0] + cnt[1];
			if (min(cnt[0], cnt[1]) < 0) break;
			if (a && b) {
				curr *= (x + 1) * (z - x + 1) % mod * inv(z + 1) % mod * inv(z + 2) % mod;
				curr %= mod;
			}
			else if (a) {
				curr *= (x + 1) * inv(z + 1) % mod;
				curr %= mod;
			}
			else {
				curr *= (z - x + 1) * inv(z + 1) % mod;
				curr %= mod;
			}
			ans += curr;
			ans %= mod;
		}
	}
	cout << ans << endl;

}

int32_t main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
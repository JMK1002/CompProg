#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 998244353;

int n, k;
int arr[200005];
int omega[200005];
int cnt[200005][15];

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

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		for (int j = 1; j * j <= arr[i]; j++) {
			if (arr[i] % j != 0) continue;
			cnt[j][omega[arr[i]]]++;
			if (j * j != arr[i]) cnt[arr[i] / j][omega[arr[i]]]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		vector<int> temp(15, 0);
		for (int a = 0; a <= 7; a++) {
			for (int b = a + 1; b <= 7; b++) {
				temp[a + b] += cnt[i][a] * cnt[i][b];
			}
		}
		for (int a = 0; a <= 7; a++) {
			temp[a * 2] += cnt[i][a] * (cnt[i][a] - 1) / 2;
		}
		for (int j = 0; j < 15; j++) cnt[i][j] = temp[j];
	}

	for (int i = n; i >= 1; i--) {
		for (int j = 0; j < 15; j++) {
			for (int m = 2; m * i <= n; m++) {
				cnt[i][j] -= cnt[i * m][j];
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 15; j++) {
			ans += binpow(j - omega[i], k) % mod * (cnt[i][j] % mod) % mod;
			ans %= mod;
		}
	}
	cout << ans << endl;

	for (int i = 0; i <= n; i++) {
		arr[i] = 0;
		for (int j = 0; j < 15; j++) cnt[i][j] = 0;
	}
}

signed main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	for (int i = 2; i <= 200000; i++) {
		if (omega[i]) continue;
		for (int j = i; j <= 200000; j += i) {
			omega[j]++;
		}
	}
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}

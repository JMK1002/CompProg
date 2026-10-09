#include <iostream>
using namespace std;

const long long mod = 1e9+7;

long long n, l, zero;
long long temp[102];
long long ans[102];

long long inv(long long a) {
	return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

void solve() {
	cin >> n >> l >> zero;
	for (long long i = 1; i <= l; i++) {
		long long invi = inv(i);
		invi %= mod;
		for (long long j = 0; j < n; j++) {
			for (long long k = 0; k <= n; k++) {
				temp[(j + k) % n] += (i / n + (j < i % n)) * invi % mod * (k == 0 ? 1 : ans[k - 1]) % mod;
				temp[(j + k) % n] %= mod;
			}
		}
		for (long long j = 0; j < n; j++) ans[j] = temp[j];
		for (long long j = 0; j < n; j++) temp[j] = 0;
	}
	for (long long i = 0; i < n; i++) cout << ans[i] << " ";
	cout << endl;
	for (long long i = 0; i < n; i++) {
		temp[i] = 0;
		ans[i] = 0;
	}
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
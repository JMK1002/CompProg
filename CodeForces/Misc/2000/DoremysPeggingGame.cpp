#include <iostream>
using namespace std;

long long n, mod;
long long cnt[5004][5004]; // num of binary strings s.t. no space exists with n / 2 consecutive zeros and j ones
long long fact[5004];

int main() { // ! Every n / 2 nodes must have one
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	
	cin >> n >> mod;
	for (long long i = 0; i < n / 2; i++) cnt[i][0] = 1;
	fact[0] = 1;
	for (long long i = 1; i < n; i++) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= mod;
		for (long long j = 1; j < n; j++) {
			cnt[i][j] = cnt[i - 1][j - 1] + cnt[i - 1][j] - (i - n / 2 - 1 >= 0 ? cnt[i - (n / 2) - 1][j - 1] : 0);
			cnt[i][j] %= mod;
			cnt[i][j] += mod;
			cnt[i][j] %= mod;
		}
	}
	// for (long long i = 0; i < n; i++) {
	// 	long long s = 0;
	// 	for (long long j = 0; j < n; j++) s += cnt[i][j];
	// 	cout << s << endl;
	// }
	long long ans = 0;
	if (n % 2 == 0) ans += fact[n - 2];
	for (long long i = 0; n - (2 + i) >= n / 2; i++) {
		long long shifts = min(i + 2 - (n % 2), (n - 1) - (2 + i) + 1);
		for (long long j = 0; j < n; j++) {
			ans += shifts * cnt[i][j] % mod * fact[(n - 1) - (2 + j)] % mod;
			ans %= mod;
		}
	}
	ans *= n;
	ans %= mod;
	cout << ans << endl;
	return 0;
}

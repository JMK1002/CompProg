#include <iostream>
using namespace std;

const long long mod = 998244353;

long long n, k;
long long dp[1000005];
long long fact[1000005];
long long invFact[1000005];

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
		res %= mod;
        a = a * a;
		a %= mod;
        b >>= 1;
    }
    return res;
}

long long inv(long long a) {
	return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

long long choose(long long a, long long b) {
	return fact[a] * invFact[b] % mod * invFact[a - b] % mod;
}

int main() {
	cin >> n >> k;
	if (k == 1) {
		cout << 1 << endl;
		return 0;
	}
	fact[0] = 1;
	invFact[0] = 1;
	for (long long i = 1; i < 1000005; i++) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= mod;
		invFact[i] = inv(fact[i]);
		invFact[i] %= mod;
	}

	dp[0] = 1;

	long long s = 1;
	for (long long i = 1; i < n; i++) {
		if (i - k >= 0) s -= dp[i - k];
		s %= mod;
		s += mod;
		s %= mod;
		dp[i] = s;
		dp[i] %= mod;
		if (i < k) dp[i] = binpow(2, i);
		s += dp[i];
		s %= mod;
		s += mod;
		s %= mod;
	}
	long long ans = 0;
	for (long long i = 0; i < n; i++) {
		ans += dp[i] * choose(n - 1, i) % mod;
		ans %= mod;
		// cout << dp[i] << " ";
	}
	cout << ans << endl;
	return 0;
}
// for (long long j = 1; j < k; j++) dp[i] += dp[i - j];

// 0 1
// 1 2
// 2 4
// 3 6
// 4 10

// 10 + 30 + 24 + 8 + 1
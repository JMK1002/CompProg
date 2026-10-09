#include <iostream>
#include <algorithm>
using namespace std;

const long long mod = 1e9+7;

long long k, n, l;
string s;
long long fact[1000005];
long long invFact[1000005];

long long inv(long long val) {
	return val <= 1 ? val : mod - (long long)(mod / val) * inv(mod % val) % mod;
}

long long ch(long long a, long long b) {
	if (b > a) return 0;
	return fact[a] * invFact[b] % mod * invFact[a - b] % mod;
}

long long binpow(long long a, long long b) {
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

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);

	fact[0] = 1;
	invFact[0] = 1;
	for (long long i = 1; i < 1000005; i++) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= mod;
		invFact[i] = inv(fact[i]);
	}

	cin >> k >> n >> l >> s;
	reverse(s.begin(), s.end());
	long long cnt = 0;
	long long ans = 1;
	for (long long i = 0; i < n; i++) {
		if (s[i] == 'O') cnt++;
		else {
			ans *= ch(cnt, k);
			ans %= mod;
			cnt -= k;
		}
	}
	cout << binpow(ans, l) << endl;
	return 0;
}
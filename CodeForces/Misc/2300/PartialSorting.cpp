#include <iostream>
using namespace std;

long long n, m;
long long fact[3000005];
long long invFact[3000005];

long long choose(long long a, long long b) {
    return fact[a] * invFact[b] % m * invFact[a - b] % m;
}

long long qpow(long long a, long long b) {
	long long ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return ans;
}


int main() {
    istream::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    fact[0] = 1;
    invFact[0] = 1;
    for (long long i = 1; i <= 3 * n; i++) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= m;
        invFact[i] = qpow(fact[i], m - 2) % m + m;
        invFact[i] %= m;
    }
    
    long long y = 2 * fact[2 * n] - fact[n] - 1 + m;
    y %= m;
    long long ans = y;
    ans %= m;

    long long x = choose(2 * n, n) * fact[n] % m * fact[2 * n] % m * 2 % m - y - 1;
    x %= m;
    x += m;
    x %= m;

    for (long long i = 0; i <= n; i++) {
        x -= fact[n + i] % m * qpow(fact[n], 4) % m * qpow(invFact[i], 3) % m * qpow(invFact[n - i], 2) % m;
        x %= m;
    }
    x %= m;
    x += m;
    x %= m;
    
    ans += 2 * x;
    ans %= m;
    ans += 3 * (((fact[3 * n] % m - x - 1 - y) % m + m) % m);
    ans %= m;
    // cout << 1 << " " << (2 * fact[2 * n] - fact[n] - 1) % m << " " << x << " " << (((fact[3 * n] % m - x - 1 - (2 * fact[2 * n] - fact[n] - 1)) % m + m) % m) << endl;
    cout << ans << endl;
    return 0;
}
////
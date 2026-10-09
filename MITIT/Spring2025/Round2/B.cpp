#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const long long mod = 1e9+7;

long long n, m;
long long amnt[3][2];
long long tot[2];
long long fact[1000000];
long long invFact[1000000];
long long midLoc;

long long inv(long long a) {
	return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

long long choose(long long a, long long b) {
	if (b > a) return 0;
	return fact[a] * invFact[b] % mod * invFact[a - b] % mod;
}

void solve() {
	cin >> n >> m;
	midLoc = -1;
	long long k = (3 * n + 1) / 2;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) amnt[j][i] = 0;
		tot[i] = 0;
	}
	for (long long i = 0; i < m; i++) {
		long long u, v;
		cin >> u >> v;
		long long loc = -1;
		if (u <= n) loc = 0;
		else if (u <= 2 * n) loc = 1;
		else loc = 2;
		if (v == k) midLoc = loc;
		else {
			bool greater = v > k;
			amnt[loc][greater]++;
			tot[greater]++;
		}
	}
	long long ans = 0;
	for (long long i = 0; i < 3; i++) {
		if (midLoc != -1 && midLoc != i) continue;
		if (amnt[i][0] > n / 2 || amnt[i][1] > n / 2) continue;
		ans += fact[3 * n - m - (n - (amnt[i][0] + amnt[i][1] + (midLoc != -1)))] % mod
			* fact[n - (amnt[i][0] + amnt[i][1] + (midLoc != -1))] % mod
			* choose(3 * n / 2 - tot[0], n / 2 - amnt[i][0]) % mod
			* choose(3 * n / 2 - tot[1], n / 2 - amnt[i][1]) % mod;
		ans %= mod;
	}
	cout << ans << endl;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	fact[0] = 1;
	invFact[0] = 1;
	for (long long i = 1; i < 1000000; i++) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= mod;
		invFact[i] = inv(fact[i]);
		invFact[i] %= mod;
	}
	long long t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
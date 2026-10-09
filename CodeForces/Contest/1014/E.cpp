#include <iostream>
using namespace std;

const long long mod = 1e9+7;

long long n, m, k;

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


void solve() {
	cin >> n >> m >> k;
	long long b[2] = {0, 0};
	long long corners = 0;
	long long free = (n - 2) * (m - 2);
	for (long long i = 0; i < k; i++) {
		long long x, y, k;
		cin >> x >> y >> k;
		bool a = (x == 1);
		bool asdf = (x == n);
		bool c = (y == 1);
		bool d = (y == m);
		b[k] += a + asdf + c + d;
		if (!a && !asdf && !c && !d) free--;

		corners += (a && c) + (a && d) + (asdf && c) + (asdf && d);
	}
	long long v;
	if (n == 1 && m == 1) {
		// cout << 0 << endl;
		v = 0;
	}
	else if (n == 1 || m == 1) {
		if (corners == 0) v = binpow(2, n * m - k - 1);
		if (corners == 2) v = binpow(2, n * m - k - 1);
		if (corners == 4 && b[0] % 2 == 1) v = binpow(2, n * m - k);
		if (corners == 4 && b[0] % 2 == 0) v = 0;
	}
	else {
		long long available = 2 * n + 2 * m - (b[0] + b[1]) - 2 * (4 - corners);
		free += (4 - corners);
		if (available == 0) {
			if (b[0] % 2 == 1) v = binpow(2, free);
			else v = 0;
		}
		else {
			v = binpow(2, available - 1 + free);
		}
	}
	cout << ((binpow(2, n * m - k) - v) % mod + mod) % mod << endl;
}

int main() {
	long long t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
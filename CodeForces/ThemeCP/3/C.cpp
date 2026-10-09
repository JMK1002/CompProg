#include <bits/stdc++.h>
using namespace std;

long long x, m, k;

void solve() {
	cin >> x >> m;
	k = 1;
	while (k <= x) k <<= 1;
	if (m < k) {
		long long cnt = 0;
		for (long long y = 1; y <= m; y++) {
			cnt += ((x ^ y) % y == 0 || (x ^ y) % x == 0);
		}
		cout << cnt << endl;
	}
	else {
		long long cnt = 0;
		for (long long y = 1; y < k; y++) {
			cnt += ((x ^ y) % y == 0) - ((x ^ y) % x == 0);
		}
		for (long long y = m / k * k; y <= m; y++) {
			cnt += ((x ^ y) % x == 0);
		}
		cout << cnt + ((m / k * k - 1) / x) << endl;
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
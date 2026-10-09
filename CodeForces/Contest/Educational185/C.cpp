#include <bits/stdc++.h>
using namespace std;

long long n, k;
long long q[200005];
long long r[200005];

void solve() {
	cin >> n >> k;
	for (long long i = 0; i < n; i++) cin >> q[i];
	for (long long i = 0; i < n; i++) cin >> r[i];
	sort(q, q + n);
	sort(r, r + n);

	long long ans = 0;

	for (long long _ = 0; _ < 2; _++) {
		long long p1 = 0;
		long long p2 = n - 1;
		while (p2 >= 0 && p1 < n) {
			while (p2 >= 0 && (1 + q[p1]) * (1 + r[p2]) - 1 > k) p2--;
			if (p2 >= 0) {
				p1++;
				p2--;
			}
		}
		ans = max(ans, p1);
		for (long long i = 0; i < n; i++) swap(q[i], r[i]);
	}
	cout << ans << endl;
	for (int i = 0; i <= n; i++) {
		q[i] = 0;
		r[i] = 0;
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
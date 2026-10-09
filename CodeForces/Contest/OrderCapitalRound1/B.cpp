#include <bits/stdc++.h>
using namespace std;

long long n;

void solve() {
	cin >> n;
	long long ans = 0;
	for (long long i = 0; i < n; i++) {
		long long a, b, c, d;
		cin >> a >> b >> c >> d;
		ans += max(0ll, a - c);
		a = min(a, c);
		if (b > d) {
			ans += a + (b - d);
		}
	}
	cout << ans << endl;
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
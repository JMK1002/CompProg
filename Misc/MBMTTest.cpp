#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	float ans = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = __builtin_popcount(i) - 1;
		int x = i;
		while (x) {
			x >>= 1;
			cnt++;
		}
		ans += (float) cnt / i;
	}
	cout << ans << endl;
}

int main() {
	cout.precision(20);
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
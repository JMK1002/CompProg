#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, k;

void solve() {
	cin >> n >> k;
	if (k < n || k >= 2 * n) {
		cout << "NO" << endl;
		return;
	}

	cout << "YES" << endl;
	int l = 2 * n - 1 - k;
	int d = n - l;
	cout << "1 " << d << " ";
	for (int i = 1; i < d; i++) {
		cout << i + 1 << " " << i << " ";
	}
	for (int i = d + 1; i <= n; i++) cout << i << " " << i << " ";
	cout << endl;
}

signed main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
